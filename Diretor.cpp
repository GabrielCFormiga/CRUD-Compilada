#include "Diretor.h"
using namespace std;

//construtores e destrutor
Diretor::Diretor(){

}
Diretor::Diretor(std::string n, std::string mat, std::string id, std::string c, std::string g) : Pessoa(n, mat, id){
    cargo = c;
    gestao = g;
}
Diretor::~Diretor(){

}

//exibir
void Diretor::exibir(){
    Pessoa::exibir();
    cout << "\t\tCargo: " << cargo << endl;
    cout << "\t\tGestao: " << gestao << endl;
}

//métodos set
void Diretor::setCargo(std::string c){
    cargo = c;
}
void Diretor::setGestao(std::string g){
    gestao = g;
}

//métodos get
std::string Diretor::getCargo(){
    return cargo;
}
std::string Diretor::getGestao(){
    return gestao;
}