#pragma once
#include <iostream>

class Pessoa {
    protected:
        std::string nome;
        std::string matricula;
        std::string ID;
    public:
        //construtores e destrutor
        Pessoa();
        Pessoa(std::string n, std::string mat, std::string id);
        ~Pessoa();
        
        //exibir
        virtual void exibir();
        
        //métodos set
        void setNome(std::string n);
        void setMat(std::string mat);
        void setID(std::string id);
        
        //métodos get
        std::string getNome();
        std::string getMat();
        std::string getID(); 
};

