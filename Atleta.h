#pragma once
#include <iostream>
#include "Pessoa.h"

class Atleta : public Pessoa {
    protected: 
        int situacao; // ativo(1) ou inativo(0)
    public:
        //construtores e destrutor
        Atleta();
        Atleta(std::string n, std::string mat, std::string id, int sit);
        ~Atleta();

        //exibir
        void exibir();

        //métodos set
        void setSituacao(int sit);

        //métodos get
        int getSituacao();
};
