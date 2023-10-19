#include "Pessoa.h"
using namespace std;

//construtores e destrutor
Pessoa::Pessoa(){

}
Pessoa::Pessoa(std::string n, std::string mat, std::string id){
    nome = n;
    matricula = mat;
    ID = id;
}
Pessoa::~Pessoa(){

}

//exibir
void Pessoa::exibir(){
    cout << "\t\tNome: " << nome << endl;
    cout << "\t\tMatricula: " << matricula << endl;
    cout << "\t\tID: " << ID << endl;
}

//métodos set
void Pessoa::setNome(std::string n){
    nome = n;
}
void Pessoa::setMat(std::string mat){
    matricula = mat;
}
void Pessoa::setID(std::string id){
    ID = id;
}

//métodos get
std::string Pessoa::getNome(){
    return nome;
}
std::string Pessoa::getMat(){
    return matricula;
}
std::string Pessoa::getID(){
    return ID;
}