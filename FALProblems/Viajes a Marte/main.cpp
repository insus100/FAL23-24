// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct Pasajero {
    string nombre;
    int altura;
};
// función que resuelve el problema
pair<vector<string>, vector<string>> resolver(vector<Pasajero> const &v, int const &altura) {
    vector<string> bajos, altos;
    for (Pasajero const& p : v) {
        if (p.altura <= altura) bajos.push_back(p.nombre);
        else altos.push_back(p.nombre);
    }

    sort(bajos.begin(), bajos.end());
    sort(altos.begin(), altos.end());
    return { bajos, altos };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, altura;
    cin >> n >> altura;
    if (!std::cin)
        return false;
    vector<Pasajero> v(n);
    for (Pasajero& p : v)
        cin >> p.nombre >> p.altura;

    pair<vector<string>, vector<string>> sol = resolver(v, altura);

    // escribir sol
    cout << "Bajos: ";
    for (string const& p : sol.first)
        cout << p << " ";
    cout << "\nAltos: ";
    for (string const& p : sol.second)
        cout << p << " ";
    cout << "\n";

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