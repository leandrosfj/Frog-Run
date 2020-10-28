//
// Created by leandro on 10/28/20.
//

#include "dado.hpp"

Dado::Dado():rd(), gen(rd()), dis(1,6){
    valor = std::round(dis(gen));
}

int Dado::jogar(){
    valor = std::round(dis(gen));
    return valor;
}

int Dado::getValor(){
    return valor;
}