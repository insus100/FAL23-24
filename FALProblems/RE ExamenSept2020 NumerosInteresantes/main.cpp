// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

using lli = long long int;
using namespace std;

struct Result {
    bool interesante;
    lli suma;//esta es la suma de la izquierda
};
//coste lineal O(m) siendo m el numero de digitos del numero n de entrada
// función que resuelve el problema
Result resolver(int n, int const& suma) {//la que le paso por parametro, la suma derecha
    int digito = n % 10, numero = n / 10;
    Result sol{ true, digito };
    if (digito == 0) return {false, digito};//caso base

    if (numero != 0) {//no ha llegado al ultimo todavia (caso recursivo)
        sol = resolver(numero, digito + suma);
        bool interesante = sol.interesante && (sol.suma % digito == 0) && (suma % digito == 0);
        sol = { interesante, sol.suma + digito };
    }
    else {//ultima llamada recursiva (seria otro caso base)
        if (suma % digito != 0) sol = { false, digito };
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    Result sol = resolver(n, 0);
    
    // escribir sol
    sol.interesante ? cout << "SI\n" : cout << "NO\n";
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