#include <iostream>
#include <vector>
#include "transpuesta_matriz.cpp"
#include <iomanip>

using namespace std;

vector<double> encontrar_probabilidad(const vector<double>& inicial, const vector<vector<double>>& matriz) {
    vector<double> resultado(inicial.size(), 0.0); // Inicializa el vector con el tamaño de 'inicial' y lleno de ceros

    // Ciclo externo recorre las filas de la matriz
    for (int i = 0; i < matriz.size(); i++) {
        double suma = 0;
        // Ciclo interno recorre el valor inicial
        for (int j = 0; j < inicial.size(); j++) {
            suma = ((matriz[i][j]/100) * (inicial[j])/100) + suma;
        }

        // Asigna la suma al vector de resultados
        resultado[i] = suma*100;
    }

    return resultado;
}

int main() {
    int opcion = 0, eventos = 0;
    vector<double> inicial, nueva_probabilidad;
    vector<vector<double>> matriz;

    cout << "Cadena de Markov" << endl;
    cout << "Ingrese cantidad de opciones" << endl;
    cin >> opcion;

    matriz.resize(opcion, vector<double>(opcion));

    cout << "Ingrese la matriz de transición, fila por fila, separada por espacios" << endl;
    for (int i = 0; i < opcion; i++) {
        for (int j = 0; j < opcion; j++) {
            cin >> matriz[i][j];
        }
    }

    cout << "Ingrese los valores del estado inicial" << endl;
    inicial.resize(opcion);
    for (int i = 0; i < opcion; i++) {
        cin >> inicial[i];
    }

    cout << "Cantidad de eventos" << endl;
    cin >> eventos;

    // Verificar si es necesario transponer la matriz (suma de columnas debe ser 100)
    bool transponer = false;
    for (int j = 0; j < opcion; j++) {
        double suma = 0;
        for (int i = 0; i < opcion; i++) {
            suma += matriz[i][j];
        }
        if (suma != 100.0) {
            transponer = true;
            break;
        }
    }

    if (transponer) {
        matriz = transponerMatriz(matriz);
        cout << "Matriz transpuesta: " << endl;
        for (const auto& fila : matriz) {
            for (const auto& elemento : fila) {
                cout << elemento << " ";
            }
            cout << endl;
        }
    } else {
        cout << "La matriz no requiere transposición." << endl;
    }

    for (int j = 0; j < eventos; j++) {
        if (j == 0) {
            nueva_probabilidad = encontrar_probabilidad(inicial, matriz);
        } else {
            nueva_probabilidad = encontrar_probabilidad(nueva_probabilidad, matriz);
        }
    }

    cout << fixed << setprecision(3);
    cout << "Probabilidades después de " << eventos << " eventos:" << endl;
    for (const auto& prob : nueva_probabilidad) {
        cout << prob << "% ";
    }
    cout << endl;


    return 0;
}
