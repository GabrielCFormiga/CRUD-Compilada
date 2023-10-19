#include "Esporte.h"
using namespace std;

//construtores e destrutor
Esporte::Esporte(){
    qtdAtletas = 0;
    qtdDiretores = 0;
    qtdAtivos = 0;
}
Esporte::Esporte(std::string modal){
    qtdAtletas = 0;
    qtdDiretores = 0;
    qtdAtivos = 0;
    modalidade = modal;
}
Esporte::~Esporte(){

}

//insere o atleta com leitura do teclado
void Esporte::inserirAtleta(){
    string n, mat, id;
    int sit;
    cout << "Insira o nome: ";
    getline(cin, n);
    cout << "Insira a matricula: ";
    cin >> mat;
    cout << "Insira a ID: ";
    cin >> id; // criei uma funcao pra ver se a ID já existe
    cout << "Defina a situacao ativo(1) ou inativo(0): ";
    cin >> sit;
    
    Atleta *a = new Atleta(n, mat, id, sit);
    pessoas.push_back(a);
    qtdAtletas++;
}
//insere o atleta com leitura pelos atributos
void Esporte::inserirAtleta(std::string n, std::string mat, std::string id, int sit){
    Pessoa *p = new Atleta(n, mat, id, sit);
    pessoas.push_back(p);
    qtdAtletas++;
}
void Esporte::alterarAtleta(int ind){
    string n, mat, id;
    int sit;
    cout << "Insira o novo nome: ";
    getline(cin, n);
    cout << "Insira a nova matricula: ";
    cin >> mat;
    cout << "Insira a nova ID: ";
    cin >> id; // criei uma funcao pra ver se a ID já existe
    cout << "Defina a nova situacao ativo(1) ou inativo(0): ";
    cin >> sit;
    pessoas[ind]->setNome(n);
    pessoas[ind]->setMat(mat);
    pessoas[ind]->setID(id);
    ((Atleta*)(pessoas[ind]))->setSituacao(sit);
}
void Esporte::removerAtleta(int ind){
    pessoas.erase(pessoas.begin() + ind);
    qtdAtletas--;
}


//insere o diretor com leitura do teclado
void Esporte::inserirDiretor(){
    string n, mat, id, c, g;
    cout << "Insira o nome: ";
    getline(cin, n);
    cout << "Insira a matricula: ";
    cin >> mat;
    cout << "Insira a ID: ";
    cin >> id; // criei uma funcao pra ver se a ID já existe
    cout << "Insira o cargo: ";
    cin >> c;
    cout << "Insira a gestao: ";
    cin >> g;
    
    Pessoa *p = new Diretor(n, mat, id, c, g);
    pessoas.insert(pessoas.begin(), p);
    qtdDiretores++;
}
//insere o diretor com leitura pelos atributos
void Esporte::inserirDiretor(std::string n, std::string mat, std::string id, std::string c, std::string g){
    Pessoa *p = new Diretor(n, mat, id, c, g);
    pessoas.insert(pessoas.begin(), p);
    qtdDiretores++;
}

//métodos exibir
void Esporte::exibirTodos(){
    exibirDiretores();
    exibirAtletas();
}
void Esporte::exibirAtletas(){
    int t = pessoas.size();
    for(int i = qtdDiretores; i < t; i++){
        pessoas[i]->exibir();
        cout << "\t\t---------------------" << endl;
    }
}
void Esporte::exibirDiretores(){
    for(int i = 0; i < qtdDiretores; i++){
        pessoas[i]->exibir();
        cout << "\t\t---------------------" << endl;
    }
}

//métodos set
void Esporte::setModalidade(std::string mod){
    modalidade = mod;
}
void Esporte::setQtdAtletas(int qtd){
    qtdAtletas = qtd;
}
void Esporte::setQtdDiretores(int qtd){
    qtdDiretores = qtd;
}
void Esporte::setQtdAtivos(int qtd){
    qtdAtivos = qtd;
}

//métodos get
std::string Esporte::getModalidade(){
    return modalidade;
}
int Esporte::getQtdAtletas(){
    return qtdAtletas;
}
int Esporte::getQtdDiretores(){
    return qtdDiretores;
}
int Esporte::getQtdAtivos(){
    int tam = qtdAtletas = qtdDiretores;
    int soma = 0;
    for(int i = qtdDiretores; i < tam; i ++){
        if(((Atleta*)(pessoas[i]))->getSituacao() == 1){
            soma++;
        }
    }

    return soma;
}
Pessoa * Esporte::getPessoa(int i){
    return pessoas[i];
}