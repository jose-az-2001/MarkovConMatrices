#include <iostream>
#include <vector>

using namespace std;

// Función para transponer la matriz
vector<vector<double>> transponerMatriz(const vector<vector<double>>& matriz) {
    size_t filas = matriz.size();
    size_t columnas = matriz[0].size();
    vector<vector<double>> transpuesta(columnas, vector<double>(filas));

    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }
    
    return transpuesta;
}
