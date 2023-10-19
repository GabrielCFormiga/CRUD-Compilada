#pragma once
#include "Pessoa.h"
#include <iostream>

class Diretor : public Pessoa {
    protected: 
        std::string cargo;
        std::string gestao;
    public:
        //construtores e destrutor
        Diretor();
        Diretor(std::string n, std::string mat, std::string id, std::string c, std::string g);
        ~Diretor();

        //exibir
        void exibir();

        //métodos set
        void setCargo(std::string c);
        void setGestao(std::string g);

        //métodos get
        std::string getCargo();
        std::string getGestao();
};

