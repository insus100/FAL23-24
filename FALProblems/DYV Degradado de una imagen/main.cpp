/*
 * Plantilla para la Práctica 3
 * Escribid vuestro nombre y usuarios:
 * - FAL38 Daniel García Arroyo
 * - FAL98 Íñigo Velasco Sánchez
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using matriz = vector<vector<int>>;
struct sol {
    bool es_degrad;
    int suma;
};
/*
 * ESCRIBE LA FUNCIÓN DIVIDE Y VENCERÁS.
 * LA RECURSIÓN DEL COSTE
 * T(M) = { c0 si M = 1 }
 *        { 2T(M/2) + c1 si M > 1 }
 * EL COSTE QUE OBTENGAS
 * El coste de la función resolver es O(M) siendo M el número de elementos de cada vector o columnas de la matriz,
 * pues hacemos llamadas recursivas hacia la izquierda y la derecha, recorriendo todo el vector.
 * Como esto tiene que hacerse N veces, que es el número de filas de la matriz, el coste total del problema es O(N * M).
 * 
 */
sol resolver(const vector<int>& v, const int &ini, const int &fin) {
    //if (ini == fin) {

    //}
    if (ini + 1 == fin) { // todas las filas tienen potencia de 2 valores
        return { true, v[ini] };
    }
    else {
        int mitad = (ini + fin) / 2;

        sol i = resolver(v, ini, mitad);
        sol d = resolver(v, mitad, fin);

        return { i.es_degrad && d.es_degrad && i.suma < d.suma, i.suma + d.suma };
    }
}

 /*
  * Función iterativa que llama a una función recursiva que comprueba si la fila es un degradado.
  * ¡¡¡COMPLETALA!!
  */
bool comprueba_matriz(const matriz& v, const int N, const int M) {
    bool lo_es = true;
    int i = 0;
    while (lo_es && i < N) {
        //LLama a la función recursiva y actualiza las variables
        lo_es = resolver(v[i], 0, M).es_degrad;
        i++;
    }

    return lo_es;
}

//--- NO MODIFIQUES NADA AQUÍ -----//
//------------------------------------------------------
bool resuelveCaso() {

    //Lectura de datos
    int N, M; //filas y columnas
    cin >> N >> M;
    if (!cin)
        return false;

    matriz imagen;
    for (int i = 0; i < N; i++) {
        vector<int> fila(M); //para leer la fila
        for (int j = 0; j < M; j++)
            cin >> fila[j];
        imagen.push_back(fila);
    }

    //En imagen hay N filas y cada una de ellas es un vector de tamaño M

    bool sol = comprueba_matriz(imagen, N, M);

    if (sol)
        cout << "SI\n";
    else
        cout << "NO\n";

    return true;

}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}