// F38 Daniel García Arroyo
// F98 Íñigo Velasco Sánchez


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

struct Result {
    int gMax, ini, fin;
};
/*
* Coste de la función resolver: O(v.size()) es decir, lineal con respecto al número de elementos del vector v.
* Precondición resolver: requires #i : 0 <= i < v.size()
* Postcondición ensures: res.fin - res.ini = (min res.ini, res.fin : 0 <= res.ini <= res.fin < v.size() && max x = (Σw : res.ini <= w <= res.fin : v[w]))
* La función de cota es: decrease v.size() - i
* Invariante: 0 <= i < v.size()
* Invariante: res.fin - res.ini = (min res.ini, res.fin : 0 <= res.ini <= res.fin < v.size() && max x = (Σw : res.ini <= w <= res.fin : v[w]))
*/
// función que resuelve el problema
Result resolver(vector<int> const &v) {
    Result res{ INT_MIN, 0, 0 }, aux{ 0, 0, 0 };
    int suma = 0;
    for (int i = 0; i < v.size(); i++) {
        suma += v[aux.fin];
        if (suma > res.gMax) {
            res.gMax = suma;
            res.ini = aux.ini;
            res.fin = aux.fin;
        }
        else if (suma == res.gMax) {
            if (aux.fin - aux.ini < res.fin - res.ini) {
                res.ini = aux.ini;
                res.fin = aux.fin;
            }
        }
        if (suma <= 0) {
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
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;
    Result sol = resolver(v);

    // escribir sol
    cout << sol.gMax << " " << sol.ini << " " << sol.fin - sol.ini + 1 << "\n";
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