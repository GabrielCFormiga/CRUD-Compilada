#pragma once
#include <iostream>
#include <fstream>
#include <vector>

#include "Esporte.h"

class Compilada : public Esporte {
    protected:
        std::vector<Esporte *> esportes;
        int qtdEsportes;
        int operacao;
    public:
        //construtor e destrutor
        Compilada();
        ~Compilada();
        
        //menu
        void exibirMenu();
        void executar();
        void setOperacao(int op);
        
        //métodos do menu
        void inserirEsporte(std::string modal);
        
        void inserirAtleta(std::string modal, std::string n, std::string mat, std::string id, int sit);
        void inserirDiretor(std::string modal, std::string n, std::string mat, std::string id, std::string c, std::string g);
        void exibirUm();
        void alterarAtleta();
        void removerAtleta();
        void exibirRelatorio();
        void salvarDados();

        //métodos get
        int getQtdEsportes();
};

