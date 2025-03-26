#include "CartaoBingo.h"
#include <algorithm>

CartaoBingo::CartaoBingo() : cartao(5, vector<int>(5)), marcados(5, vector<bool>(5, false)) { 
    static random_device rd; //variável seja criada uma única vez e persista ao longo da execução do programa
    static mt19937 gen(rd());//gerador de numeros aleatórios (Mersenne Twister 19937, gerador de números pseudoaleatórios)
    for (int col = 0; col < 5; col++) {
        vector<int> numeros; // Matriz de números
        for (int i = 1; i <= 15; i++) {
            numeros.push_back(col * 15 + i); //GERA OS NUMEROS DE 1 A 75 por colunas
        }
        shuffle(numeros.begin(), numeros.end(), gen); //shuffle utilizado para embaralhar os numeros
        for (int row = 0; row < 5; row++) {
            cartao[row][col] = numeros[row]; // preenche o cartao 
            marcados[row][col] = false; // para saber que inicialmente nenhum ta marcado  
        }
    }
}

void CartaoBingo::imprimirCartao() {
    cout << "B  I  N  G  O" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (marcados[i][j])
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
                marcados[i][j] = true; // se for encontrado passa a variavel para true
            }
        }
    }
}
