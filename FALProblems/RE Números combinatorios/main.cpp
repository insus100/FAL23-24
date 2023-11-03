// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
using Matriz = vector<vector<int>>;
// función que resuelve el problema
int resolver(Matriz &m, int const&a, int const&b) {
    if (b == 0 || a == b) {//caso base
        m[a][b] = 1;
    }
    else {
        m[a][b] = m[a - 1][b - 1] != -1 ? m[a - 1][b - 1] : resolver(m, a - 1, b - 1);
        m[a][b] += m[a - 1][b] != -1 ? m[a - 1][b] : resolver(m, a - 1, b);
    }
    return m[a][b];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a, b;
    cin >> a >> b;
    if (!std::cin)
        return false;
    Matriz m = Matriz(a + 1, vector<int>(b + 1, -1));//inicializo la matriz con a + 1 filas y b + 1 columnas con todos los valores a -1
    int sol = resolver(m, a, b);

    // escribir sol
    cout << sol << "\n";

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