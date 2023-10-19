#include "Atleta.h"

using namespace std;

//construtores e destrutor
Atleta::Atleta(){
    
}
Atleta::Atleta(std::string n, std::string mat, std::string id, int sit) : Pessoa(n, mat, id){
    setSituacao(sit);
}
Atleta::~Atleta()
{

}

//exibir
void Atleta::exibir(){
    Pessoa::exibir();
    cout << "\t\tSituacao: " << (situacao ? "Ativo" : "Inativo") << endl;
}

// métodos set
void Atleta::setSituacao(int sit){
    situacao = sit;
}

//métodos get
int Atleta::getSituacao(){
    return situacao;
}