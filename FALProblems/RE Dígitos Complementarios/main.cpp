/*
* FAL38 Daniel García Arroyo
* FAL98 Íñigo Velasco Sánchez
*/


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
using par = pair<int, int>;

/*
* El coste de ambas funciones (resolverComplementario(n) y resolverInverso(n)) es O(m) (cada una) siendo m el número de dígitos
* que tiene el parámetro entero n.
* Si el número n tiene 5 dígitos. Si se hace la operación n/10 5 veces se producirán (5 llamadas recursivas) para llegar al caso base.
* La precondición de ambas funciones es: { 0 <= N <= 1.000.000.000 }
* Recurrencia:
* T(n) = {k_0 si n < 10
*        { T(n/10) + k_1 eoc
*/
// función que resuelve el problema
int resolverComplementario(int const &n) {
    if (n < 10) return 9 - n;//caso base
    else { 
        int cifra = n % 10, res = resolverComplementario(n / 10);
        return 9 - cifra + res * 10;
    }
}

par resolverInverso(int const &n) {
    if(n < 10) return { 9 - n, 10 };
    else {
        int cifra = 9 - n % 10;
        par r = resolverInverso(n / 10);
        return { cifra * r.second + r.first, r.second * 10 };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    int solComp = resolverComplementario(n), solInverso = resolverInverso(n).first;
    // escribir sol
    cout << solComp << " " << solInverso << "\n";

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