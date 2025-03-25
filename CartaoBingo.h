#ifndef CARTAOBINGO_H
#define CARTAOBINGO_H

#include <iostream>
#include <vector>
#include <random>

using namespace std;

class CartaoBingo {
private:
    vector<vector<int>> cartao; // Matriz de números
    vector<vector<bool>> marcados;
    const string letras = "BINGO";

public:
    CartaoBingo();
    void imprimirCartao();
    void marcarNumero(int num);
};

#endif
