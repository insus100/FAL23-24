// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
struct Intervalo {
    int ini, fin;
};
// función que resuelve el problema
void cerosUnos(vector<int> const& v, int const& p, int const& q, int& ceros, int& unos) {
    for (int i = p; i < q; i++) {
        if (v[i] == 0) ceros++;
        else if (v[i] == 1) unos++;
    }
}
int resolver(vector<int> const &v, int const &l) {
    int numCeros = 0, numUnos = 0, cerosIgualUnosCont = 0;//num ceros y unos en el intervalo
    Intervalo in{ 0, l - 1 };
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) numCeros++;
        else if (v[i] == 1) numUnos++;
        
        if (in.fin == i) {
            if (numCeros == numUnos) cerosIgualUnosCont++;
            if (v[in.ini] == 0) numCeros--;
            else if (v[in.ini] == 1) numUnos--;
            in.fin = in.ini + l;
            in.ini = in.ini + 1;
        }
    }
    return cerosIgualUnosCont;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, l;
    cin >> l >> n;
    vector<int> v(n);

    for (int& c : v)
        cin >> c;

    int sol = resolver(v, l);
    // escribir sol
    cout << sol << "\n";

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