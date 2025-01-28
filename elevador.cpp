#ifndef ELEVADOR_H
#define ELEVADOR_H

#include "Parametro.cpp"

/* =-=-=-=-= Bibliotecas =-=-=-=-= */
#include <iostream>
#include <string>
#include <limits>

using namespace std;

typedef enum{
    PARADO,
    MOVIMENTANDO_SE

}statusCinematico;

typedef enum{
    FECHADA,
    ABERTA

}statusPorta;



template<typename T>
class elevador {
private:

    // USADOS EM NA CLASSE PARAMETRO
    string relacao01;       // Relação entre os parametros 
    int Nparametros;        // Numero de parametros a serem comparados
    T* elementosParametros; // Array de elementos a serem comparados

    int Nandares;
    int andarAtual = 0;

    // SEGURANÇA
    bool fechado;
    bool movimento;
    statusPorta status01;
    statusCinematico status02;
    

    // COMO MOVIMENTAR-SE

    int*  andaresPrioritarios;
    int ocupacao = 0;

    //INTANCIAS IMPORTANTES
    parametro<T>* parametro01;

    

public:
    elevador(string relacaoN, int NandareS, int NparametroS, T* array) {
        this->relacao01   = relacaoN;
        this->Nparametros = NparametroS;
        elementosParametros = array;

        this->Nandares    = NandareS;
        
        andaresPrioritarios = new int[NandareS];

        parametro01 = new parametro<T>(Nparametros,elementosParametros);
    };

    ~elevador() {
      delete[] andaresPrioritarios;
    }

    int getStatusPorta(){
        return this->status01;
    }

    void setFechado(){
        return this->status01 = FECHADA;
    }

    int getOcupacao(){
        return this->ocupacao;
    }


    bool requisicaoEdelegacao(int x) {
    // Verificar se a posição é válida
    if (x < 0 || x > Nandares) {
        cout << "Posição inválida. Insira uma posição entre 0 e " << Nandares << ".\n";
        cout << "" << endl;

        return false;
    }

    for (int i = 0; i < Nandares; i++) {
        if ((x - andarAtual) < andaresPrioritarios[i]) {
            for (int d = ocupacao; d > i; --d) {
                andaresPrioritarios[d] = andaresPrioritarios[d - 1];
            }
            andaresPrioritarios[i] = x;
            ocupacao++;
            break;
        }
        
    }

    // Exibir os próximos andares
    for (int i = 0; i < Nandares; i++) {
        cout << "indice " << i << endl;
        cout << andaresPrioritarios[i] << endl;
        cout << "" << endl;
    }

     return true;
    };

    bool movimentacao (){
        if (parametro01->verificacao(relacao01) == true){
            if (this->status01 == FECHADA && this->status02 == PARADO){
                
                string captura;
                for (int i = 0; i < ocupacao; i++){
                
                    this->status02 = MOVIMENTANDO_SE;
                    if (andarAtual < andaresPrioritarios[i]){

                        cout << "^ " << andaresPrioritarios[i] << endl;
                        cout << " " << endl;

                        this->status02=PARADO;
                        this->status01=ABERTA;

                        cout << "Digite X para fechar a porta " << endl;
                        cin >> captura;

                        if (captura == "X" || captura == "x" ){
                            this->status01=FECHADA;
                        }
                        else {
                            cout << "Input não reconhecido" <<  endl;
                            cout << " " << endl;

                            this->status02 = PARADO;
                            this->status01 = ABERTA;

                            cout << "Saia do elevador" << endl;
                        }

                        
                        
                    }
                    else {
                        cout << "Desçendo " << endl;
                        cout << " " << endl;

                        this->status02=PARADO;
                        this->status01=ABERTA;

                        cout << "Digite X para fechar a porta " << endl;
                        cin >> captura;

                        if (captura == "X" || captura == "x" ){
                            this->status01=FECHADA;
                        }
                        else {
                            cout << "Input não reconhecido" <<  endl;
                            cout << " " << endl;

                            this->status02 = PARADO;
                            this->status01 = ABERTA;

                            cout << "Saia do elevador" << endl;
                        }
                    } 
                };     
            };

            for (int i = 0; i < ocupacao; i++){
                this->andaresPrioritarios[i] = (Nandares+1);
            };
            ocupacao = 0;

           
             
        }
        else {
            cout << "Falha na seguranca" << endl;
            this->status02  = PARADO;
            this->status01 = ABERTA;
            cout << "A porta esta: " << this->status01 << "e o elevador " << this->status02 << "favor, retirem-se" << endl;
            cout << " " << endl;
            return false;
        };

    }

   
};

#endif
