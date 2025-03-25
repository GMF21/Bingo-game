#include "JogoBingo.h"
#include <iostream>
#include <algorithm>
//#include <ctime>
#include <cstdlib>

JogoBingo::JogoBingo() {
    for (int i = 1; i <= 75; i++) {
        numeros.push_back(i); // preenche a lista com os numeros de a 1 a 75 e depois remove-os da lista
    }
    static random_device rd;
    static mt19937 gen(rd());
    shuffle(numeros.begin(), numeros.end(), gen); //embaralha a lista (begin (interador poh primeiro elemento do vetor) end(interador que sponta poh ultimo elemento e adiciona)
}

void JogoBingo::sortearNumero() {
    if (numeros.empty()) { 
        cout << "Todos os números foram sorteados!" << endl;
        return; //evita que o programa tente acessar ao .back e ao .pop... evitando erros
    }
    int num = numeros.back();
    numeros.pop_back(); // elimina o ultimo elemento
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
