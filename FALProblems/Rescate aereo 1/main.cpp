// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
struct Resultado {
    int ini, fin;
};
// función que resuelve el problema
Resultado resolver(vector<int> const&v, int const&t) {
    int tamUltimoIntervalo = 0;
    Resultado aux{ 0, -1 }, r{ 0,0 };
    bool intervalo = false;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > t) {
            if (intervalo) {
                aux.fin = i;
            }
            else {
                aux.ini = aux.fin = i;
                intervalo = true;
            }
        }
        else {
            if (tamUltimoIntervalo < aux.fin - aux.ini + 1) {
                r = aux;
                tamUltimoIntervalo = r.fin - r.ini + 1;
            }
            intervalo = false;
        }
    }
    if (tamUltimoIntervalo < aux.fin - aux.ini + 1) {
        r = aux;
        tamUltimoIntervalo = r.fin - r.ini + 1;
    }
    return r;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, t;
    cin >> n >> t;
    vector<int> v(n);

    for (int& c : v)
        cin >> c;

    Resultado sol = resolver(v, t);
    // escribir sol
    cout << sol.ini << " " << sol.fin << "\n";

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}