#ifndef JOGOBINGO_H
#define JOGOBINGO_H

#include "CartaoBingo.h"
#include <vector>

class JogoBingo {
private:
    vector<int> numeros; //numeros 
    CartaoBingo cartao; //cartao

public:
    JogoBingo();
    void sortearNumero();
    void jogar();
};

#endif
