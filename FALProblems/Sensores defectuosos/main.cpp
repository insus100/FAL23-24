// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;
using lli = long long int;
// función que resuelve el problema
void resolver(vector<lli> &v, lli const &p) {
    int i = 0, pos = -1;
    while (i < v.size()) {
        if (v[i] == p) {
            if (pos == -1) pos = i;
            i++;
        }
        else {
            if (pos != -1) {
                v[pos] = v[i];
                v[i] = p;
                i = pos + 1;
                pos = -1;
            }
            else i++;
        }
    }
    if(pos != -1) v.erase(v.begin() + pos, v.end());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    lli n, p;
    cin >> n >> p;
    vector<lli> v(n);

    for (lli& c : v)
        cin >> c;

    resolver(v, p);
    // escribir sol
    cout << v.size() << "\n";
    for (lli& c : v)
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