#ifndef JOGOBINGO_H
#define JOGOBINGO_H

#include "CartaoBingo.h"
#include <vector>

class JogoBingo {
private:
    vector<int> numeros;
    CartaoBingo cartao;

public:
    JogoBingo();
    void sortearNumero();
    void jogar();
};

#endif
