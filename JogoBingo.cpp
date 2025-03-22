#include "JogoBingo.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

JogoBingo::JogoBingo() {
    for (int i = 1; i <= 75; i++) {
        numeros.push_back(i);
    }
    static random_device rd;
    static mt19937 gen(rd());
    shuffle(numeros.begin(), numeros.end(), gen);
}

void JogoBingo::sortearNumero() {
    if (numeros.empty()) {
        cout << "Todos os números foram sorteados!" << endl;
        return;
    }
    int num = numeros.back();
    numeros.pop_back();
    cout << "Número gerado: " << num << endl;
    cartao.marcarNumero(num);
    cartao.imprimirCartao();
}

void JogoBingo::jogar() {
    while (!numeros.empty()) {
        cout << "Pressione ENTER para gerar o número";
        cin.ignore();
        sortearNumero();
    }
    cout << "Bingooo, ganhaste!" << endl;
}