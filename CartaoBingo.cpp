#include "CartaoBingo.h"
#include <ctime>
#include <algorithm>

CartaoBingo::CartaoBingo() : cartao(5, vector<int>(5)), marcados(5, vector<bool>(5, false)) { 
    static random_device rd;
    static mt19937 gen(rd());
    for (int col = 0; col < 5; col++) {
        vector<int> numeros; // Matriz de números
        for (int i = 1; i <= 15; i++) {
            numeros.push_back(col * 15 + i);
        }
        shuffle(numeros.begin(), numeros.end(), gen);
        for (int row = 0; row < 5; row++) {
            cartao[row][col] = numeros[row];
            marcados[row][col] = false;
        }
    }
}

void CartaoBingo::imprimirCartao() {
    cout << "B  I  N  G  O" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cartao[i][j] == 0)
                cout << " X ";
            else if (marcados[i][j])
                cout << "X ";
            else
                cout << cartao[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void CartaoBingo::marcarNumero(int num) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cartao[i][j] == num) {
                marcados[i][j] = true;
            }
        }
    }
}
