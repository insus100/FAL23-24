// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

// función que resuelve el problema
vector<int> resolver(vector<int> const &v, int const& primerAnio) {
    int maxVentas = v[0];
    vector<int> anios;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > maxVentas) {
            maxVentas = v[i];
            anios.push_back(primerAnio + i);
        }
    }
    return anios;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int primerAnio, ultimoAnio;
    cin >> primerAnio >> ultimoAnio;

    vector<int> v(ultimoAnio - primerAnio + 1);

    for (int& c : v)
        cin >> c;

    vector<int> sol = resolver(v, primerAnio);
    // escribir sol
    for (int& c : sol)
        cout << c << " ";

    cout << "\n";
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