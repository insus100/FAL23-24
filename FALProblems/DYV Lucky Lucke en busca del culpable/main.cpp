// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
struct Sol {
    int izq, der;
};
//coste O(logN), el vector está ordenado.
// función que resuelve el problema
Sol buscarIz(const vector<int>& v, const int& ini, const int& fin, const int& h) {
    if (ini == fin) {
        if (v[ini] == h) return { ini, -1 };
        else return { -1, -1 };
    }
    else if (ini + 1 == fin) {
        if (v[ini] == h && v[fin] == h) return { ini, fin };
        else if (v[ini] == h) return { ini, -1 };
        else if (v[fin] == h) return { fin, -1 };
        else return { -1, -1 };
    }
    else {
        if (v[ini] == h && v[fin] == h) return { ini, fin };
        else {
            int mitad = (ini + fin) / 2;
            if(v[mitad] > h) return buscarIz(v, ini, mitad, h);
            else return buscarIz(v, mitad, fin, h);
        }
    }
}

Sol buscarDer(const vector<int>& v, const int& ini, const int& fin, const int& h) {
    if (ini == fin) {
        if (v[ini] == h) return { -1, ini };
        else return { -1, -1 };
    }
    else if (ini + 1 == fin) {
        if (v[ini] == h && v[fin] == h) return { ini, fin };
        if (v[ini] == h) return { -1, ini };
        else if (v[fin] == h) return { -1, fin };
        else return { -1, -1 };
    }
    else {
        if (v[ini] == h && v[fin] == h) return { ini, fin };
        else {
            int mitad = (ini + fin) / 2;
            if (v[mitad] > h) return buscarDer(v, ini, mitad, h);
            else return buscarDer(v, mitad, fin, h);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, h;
    cin >> n >> h;
    if (!std::cin)
        return false;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;
    int mitad = n / 2;
    Sol solIzq{ -1, -1 }, solDer{ -1, -1 };
    if (h > v[mitad])
        solDer = buscarDer(v, mitad, n - 1, h);
    else if (h < v[mitad])
        solIzq = buscarIz(v, 0, mitad - 1, h);
    else {
        solIzq = buscarIz(v, 0, mitad - 1, h);
        if (solIzq.izq == -1) solIzq.izq = mitad;
        solDer = buscarDer(v, mitad, n - 1, h);
        if (solDer.der == -1) solDer.der = mitad;
    }

    // escribir sol

    Sol sol{ solIzq.izq, solDer.der };
    if (sol.izq == sol.der) sol.der = -1;
    if (solIzq.izq == -1 && solDer.izq != -1)
        sol.izq = solDer.izq;
    if (solDer.der == -1 && solIzq.der != -1)
        sol.der = solIzq.der;


    if (sol.izq == -1 && sol.der == -1) cout << "NO EXISTE\n";
    else if (sol.izq != -1 && sol.der != -1) {
        cout << sol.izq << " " << sol.der << "\n";
    }
    else {
        if (sol.izq != -1) cout << sol.izq << "\n";
        if (sol.der != -1) cout << sol.der << "\n";
    }

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}