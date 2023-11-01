// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
using ulli = unsigned long long int;
// función que resuelve el problema
//recursion multiple: tarda mucho para valores > 50
/*int fib(int n) {
    if (n == 0 || n == 1) return n;//caso base
    else {
        return fib(n - 1) + fib(n - 2);
    }
}*/

ulli fib(ulli const& n, ulli const& a, ulli const& b) {
    if (n == 0) return b;
    else {
        return fib(n - 1, b, a + b);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;

    if (n == 0 || n == 1) cout << n << "\n";
    else {
        ulli sol = fib(n - 1, 0, 1);
        cout << sol << "\n";
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