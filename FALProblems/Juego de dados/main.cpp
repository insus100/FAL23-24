// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

// función que resuelve el problema
vector<int> resolver(vector<int> const &v, int const& m) {
    vector<int> veces(m, 0);
    int max = INT_MIN;
    for (int i = 0; i < v.size(); i++) {
        veces[v[i] - 1]++;
        if (veces[v[i] - 1] > max) max = veces[v[i] - 1];
    }
    vector<int> sol;
    for (int i = 0; i < veces.size(); i++) {
        if (veces[i] == max) sol.push_back(i + 1);
    }
    sort(sol.begin(), sol.end(), greater<int>());
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, max;
    cin >> n;
    if (n == -1)
        return false;
    cin >> max;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;

    vector<int> sol = resolver(v, max);
    // escribir sol
    for (int const& c : sol)
        cout << c << " ";
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
