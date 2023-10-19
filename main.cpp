#include <bits/stdc++.h>
#include "Compilada.h"
#include "Esporte.h"
#include "Pessoa.h"
#include "Atleta.h"
#include "Diretor.h"

using namespace std;


vector<string> Split(string linha, char divisor){
    vector<string> info; 
    string str; 
    size_t inicio = 0; 

    for (size_t i = 0; i < linha.size(); ++i) {

        if (linha[i] == divisor) {
            //cria uma substring
            str = linha.substr(inicio, i - inicio);
            info.push_back(str);
            inicio = i + 1;
        }
    }

    str = linha.substr(inicio);
    info.push_back(str);
    return info;
}

void iniciarPrograma(Compilada *ci){
    ifstream fp;

    fp.open("Compilada.txt");

    if(!fp.is_open()){
        cout << "Nao foi possivel abrir o fp do programa!" << endl;
        fp.close();
        exit(1);
    }

    while(!fp.eof()){
        string linha;

        getline(fp, linha);
        vector<string> info = Split(linha, ';');

        if (info.empty()) {
            continue; // Ignorar linhas vazias
        }

        if(info.size() == 3){
            ci->inserirEsporte(info[2]);
        } else if(info.size() == 7){
            ci->inserirAtleta(info[2], info[3], info[4], info[5], stoi(info[6]));
        } else if(info.size() == 8){
            ci->inserirDiretor(info[2], info[3], info[4], info[5], info[6], info[7]);
        }
    }
            
    fp.close();
}


int main(){
    Compilada ci;
    
    iniciarPrograma(&ci);

    while(1){
        ci.exibirMenu(); //exibe e executa        
    }


    exit(0);
}