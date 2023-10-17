// Nombre del alumno .....
// Usuario del Juez ......
//Kadane's algorithm
//https://algorithmist.com/wiki/Kadane%27s_algorithm

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;
struct Result {
    int gMax, ini, fin;
};
// función que resuelve el problema
Result resolver(vector<int> const&v, int const&s) {
    Result res{ INT_MIN, 0, 0 }, aux{ 0, 0, 0 };
    int suma = 0;
    for (int i = 0; i < v.size(); i++) {
        suma += v[aux.fin];
        if (suma > res.gMax) {
            res.gMax = suma;
            res.ini = aux.ini;
            res.fin = aux.fin;
        }
        if (suma < 0) {
            suma = 0;
            aux.ini = aux.fin + 1;
        }
        aux.fin++;
    }
    return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;

    Result sol = resolver(v, s);

    // escribir sol
    sol.gMax < s ? cout << "NO COMPENSA\n" : cout << sol.gMax << " " << sol.ini << " " << sol.fin << "\n";

    return true;

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