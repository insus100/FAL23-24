// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;
// función que resuelve el problema
bool resolver(vector<int> const&v) {
    int menor = INT_MAX, i = 0;
    bool minimalista = true;
    while (minimalista && i < v.size()) {
        if (v[i] < menor) {
            menor = v[i];
        }
        else if (v[i] == menor) minimalista = false;
        i++;
    }
    return minimalista;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == -1)
        return false;
    vector<int> v(n);

    for (int& c : v)
        cin >> c;

    bool sol = resolver(v);
    // escribir sol
    sol ? cout << "SI\n" : cout << "NO\n";

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
