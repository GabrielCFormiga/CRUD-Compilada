#pragma once
#include <iostream>
#include <vector>

#include "Pessoa.h"
#include "Atleta.h"
#include "Diretor.h"

class Esporte {
    protected:
        std::vector<Pessoa *> pessoas; 
        std::string modalidade;
        int qtdAtletas; 
        int qtdDiretores; 
        int qtdAtivos;

    public:
        Esporte();
        Esporte(std::string modal);
        ~Esporte();

        //atleta
        void inserirAtleta();
        void inserirAtleta(std::string n, std::string mat, std::string id, int sit);
        void alterarAtleta(int ind);
        void removerAtleta(int ind);

        //diretor
        void inserirDiretor();
        void inserirDiretor(std::string n, std::string mat, std::string id, std::string c, std::string g);
        

        //métodos exibir
        void exibirTodos();
        void exibirAtletas();
        void exibirDiretores();

        //métodos set
        void setModalidade(std::string mod);
        void setQtdAtletas(int qtd);
        void setQtdDiretores(int qtd);
        void setQtdAtivos(int qtd);
        
        //métodos get
        std::string getModalidade();
        int getQtdAtletas();
        int getQtdDiretores();
        int getQtdAtivos();
        Pessoa * getPessoa(int i);
        
        
};

