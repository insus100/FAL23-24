// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;
// función que resuelve el problema
bool resolver(vector<int> const& v, int const&p) {
    if (p == v.size() - 1)
        return true;
    int max_izq = INT_MIN, min_der = INT_MAX;
    for (int i = 0; i <= p; ++i) {
        if (v[i] > max_izq)
            max_izq = v[i];
    }
    for (int i = p + 1; i < v.size(); ++i) {
        if (v[i] < min_der)
            min_der = v[i];
    }
    return max_izq < min_der;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, p;
    cin >> n >> p;
    vector<int> v(n);

    for (int& val : v)
        cin >> val;

    bool sol = resolver(v, p);
    // escribir sol
    sol ? cout << "SI\n" : cout << "NO\n";
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