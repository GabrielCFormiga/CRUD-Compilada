#include "Compilada.h"

using namespace std;

//construtor e destrutor
Compilada::~Compilada()
{

}
Compilada::Compilada(){
    cout << "O programa esta abrindo..." << endl;
    qtdEsportes = 0;
}

//menu
void Compilada::exibirMenu(){
    cout << endl;
    cout << "----------------MENU----------------" << endl;
    cout << "1 - Inserir" << endl;
    cout << "2 - Listar todos" << endl;
    cout << "3 - Exibir por nome"  << endl;
    cout << "4 - Alterar atleta" << endl;
    cout << "5 - Remover atleta" << endl;
    cout << "6 - Exibir relatorio" << endl;
    cout << "7 - Sair" << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
    cin >> operacao;
    executar();
}
void Compilada::executar(){
    int op2;
    switch (operacao){
    case 1:
        cout << "--------------INSERIR---------------" << endl;
        cout << "1 - Inserir Esporte" << endl;
        cout << "2 - Inserir Atleta" << endl;
        cout << "3 - Inserir Diretor" << endl; 
        cout << "------------------------------------" << endl;
        cin >> op2;

        if(op2 == 1){
            string modal;
            cin.ignore();
            cout << "Insira a modalidade: ";
            getline(cin, modal);
            inserirEsporte(modal);
        } else if(op2 == 2){
            string modal;
            cin.ignore();
            cout << "Insira a modalidade: ";
            getline(cin, modal);
            
            for(int i = 0; i < qtdEsportes; i++){
                if(esportes[i]->getModalidade() == modal){
                    esportes[i]->inserirAtleta(); // usei inserir atleta da classe Esporte
                    break;
                }
                if(i == qtdEsportes - 1){
                    cout << "Esporte inexistente!" << endl;
                }
            }
        } else if(op2 == 3){
            string modal;
            cin.ignore();
            cout << "Insira a modalidade: ";
            getline(cin, modal);

            for(int i = 0; i < qtdEsportes; i++){
                if(esportes[i]->getModalidade() == modal){
                    esportes[i]->inserirDiretor(); // usei inserir diretor da classe Esporte
                    break;
                }
                if(i == qtdEsportes - 1){
                    cout << "Esporte inexistente!" << endl;
                }
            }
        } else {
            cout << "Operacao invalida!" << endl;
        }
        break;

    case 2:
        cout << "---------------LISTAR----------------" << endl;
        cout << "1 - Esportes" << endl;
        cout << "2 - Atletas" << endl;
        cout << "3 - Diretores" << endl;
        cin >> op2;
        
        if(op2 == 1){
            for(int i = 0; i < qtdEsportes; i++){
                cout << "\t\t" <<  i + 1 << " - " << esportes[i]->getModalidade() << endl;
            }
        } else if(op2 == 2){

            string modal;
            cin.ignore();
            cout << "Insira a modalidade: ";
            getline(cin, modal);
            
            for(int i = 0; i < qtdEsportes; i++){
                if(esportes[i]->getModalidade() == modal){
                    cout << "\t\t\t" << esportes[i]->getModalidade() << endl;
                    esportes[i]->exibirAtletas(); 
                    break;
                }
                if(i == qtdEsportes - 1){
                    cout << "Esporte inexistente!" << endl;
                }
            }

        } else if(op2 == 3){
            
            string modal;
            cin.ignore();
            cout << "Insira a modalidade: ";
            getline(cin, modal);
            
            for(int i = 0; i < qtdEsportes; i++){
                if(esportes[i]->getModalidade() == modal){
                    cout << "\t\t\t" << esportes[i]->getModalidade() << endl;
                    esportes[i]->exibirDiretores(); 
                    break;
                }
                if(i == qtdEsportes - 1){
                    cout << "Esporte inexistente!" << endl;
                }
            }

        } else {
            cout << "Operacao invalida!" << endl;
        }
        break;

    case 3:
        exibirUm();
        break;
    case 4:
        alterarAtleta();
        //alterarDiretor();
        break;
    case 5:
        removerAtleta();
        //removerDiretor();
        break;
    case 6:
        exibirRelatorio();
        break;
    case 7:
        cout << "O programa esta fechando..." << endl;
        salvarDados();
        cout << "Tchau!" << endl;
        exit(0);
    default:
        cout << "Operacao invalida!" << endl;
        break;
    }
}

void Compilada::setOperacao(int op){
    operacao = op;
}

void Compilada::inserirEsporte(string modal){
    Esporte *e = new Esporte(modal);
    esportes.push_back(e);
    qtdEsportes++;
}

void Compilada::inserirAtleta(std::string modal, std::string n, std::string mat, std::string id, int sit){
    for(int i = 0; i < qtdEsportes; i++){
        if(esportes[i]->getModalidade() == modal){
            esportes[i]->inserirAtleta(n, mat, id, sit); 
            break;
        }
    }
}
void Compilada::inserirDiretor(std::string modal, std::string n, std::string mat, std::string id, std::string c, std::string g){
    for(int i = 0; i < qtdEsportes; i++){
        if(esportes[i]->getModalidade() == modal){
            esportes[i]->inserirDiretor(n, mat, id, c, g); 
            break;
        }
    }
}


void Compilada::exibirUm(){
    string busca;
    cout << "Digite o nome que voce deseja exibir: ";
    cin.ignore();
    getline(cin, busca);

    for(int i = 0; i < qtdEsportes; i++){
        int tam = esportes[i]->getQtdAtletas() + esportes[i]->getQtdDiretores();  
        for(int j = 0; j < tam; j++){
            if(((esportes[i]->getPessoa(j))->getNome()).find(busca) != string::npos){  
                (esportes[i]->getPessoa(j))->exibir();
                return;
            }
        }

    }

    cout << "Nome nao encontrado!" << endl;
}

// é garantido que só viaja entre atletas
void Compilada::alterarAtleta(){
    string busca;
    cout << "Digite o nome que voce deseja alterar: ";
    cin.ignore();
    getline(cin, busca);

    for(int i = 0; i < qtdEsportes; i++){
        int tam = esportes[i]->getQtdAtletas() + esportes[i]->getQtdDiretores();  

        for(int j = esportes[i]->getQtdDiretores(); j < tam; j++){
            if((esportes[i]->getPessoa(j))->getNome() == busca){ 
                esportes[i]->alterarAtleta(j);
                cout << "Atleta alterado com sucesso." << endl;
                return;
            }
        }

    }

    cout << "Nome nao encontrado!" << endl;
}

// é garantido que só viaja entre atletas
void Compilada::removerAtleta(){
    string busca;
    cout << "Digite o nome que voce deseja remover: ";
    cin.ignore();
    getline(cin, busca);

    //viaja apenas por atletas
    for(int i = 0; i < qtdEsportes; i++){
        int tam = esportes[i]->getQtdAtletas() + esportes[i]->getQtdDiretores();  
       
        for(int j = esportes[i]->getQtdDiretores(); j < tam; j++){
            if((esportes[i]->getPessoa(j))->getNome() == busca){
                esportes[i]->removerAtleta(j);
                cout << "Pessoa removida do sistema." << endl;
                return;
            }
        }

    }

    cout << "Nome nao encontrado!" << endl;
}   

void Compilada::exibirRelatorio(){
    cout << "\t\t\t\t\tRELATORIO\t\t\t\t" << endl;
    cout << "\tESPORTE\t\t\tATLETAS\t\t\tDIRETORES\t\t\tATIVOS" << endl;

    for(int i = 0; i < qtdEsportes; i++){
        cout << "\t" << esportes[i]->getModalidade();
        cout << "\t\t\t" << esportes[i]->getQtdAtletas();
        cout << "\t\t\t" << esportes[i]->getQtdDiretores();
        cout << "\t\t\t" << esportes[i]->getQtdAtivos() << endl;
    }
}

void Compilada::salvarDados(){
    ofstream fp;

    fp.open("Compilada.txt");

    for(int i = 0; i < qtdEsportes; i++){
        int tam = esportes[i]->getQtdAtletas() + esportes[i]->getQtdDiretores();  
        fp << "1;1;" << esportes[i]->getModalidade() << endl;
        
        //salvar diretores
        for(int j = 0; j < esportes[i]->getQtdDiretores(); j++){
            fp << "1;3;" << esportes[i]->getModalidade() << ";" << 
            (esportes[i]->getPessoa(j))->getNome() << ";" << 
            (esportes[i]->getPessoa(j))->getMat() << ";" <<
            (esportes[i]->getPessoa(j))->getID() << ";" <<
            ((Diretor*)(esportes[i]->getPessoa(j)))->getCargo() << ";" <<
            ((Diretor*)(esportes[i]->getPessoa(j)))->getGestao() << endl;
        }
        
        //salvar atletas
        for(int j = esportes[i]->getQtdDiretores(); j < tam; j++){
            fp << "1;2;" << esportes[i]->getModalidade() << ";" << 
            (esportes[i]->getPessoa(j))->getNome() << ";" << 
            (esportes[i]->getPessoa(j))->getMat() << ";" <<
            (esportes[i]->getPessoa(j))->getID() << ";" <<
            ((Atleta*)(esportes[i]->getPessoa(j)))->getSituacao() << endl;
        }

    }

    fp.close();
}

//métodods get

int Compilada::getQtdEsportes(){
    return qtdEsportes;
}