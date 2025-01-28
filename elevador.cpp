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
        this->status01 = FECHADA;
    }

    int getOcupacao(){
        return this->ocupacao;
    }

    int getandarAtual(){
        return this->andarAtual;
    }


    bool requisicaoEdelegacao(int x) {
    // Verificar se a posição é válida
    if (x < 0 || x > Nandares) {
        cout << "Posicao invalida. Insira uma posicao entre 0 e " << Nandares << ".\n";
        cout << "" << endl;

        return false;
    }

    if (x == andarAtual){
        cout << "Voce ja esta na andar requirido" << endl;
        cout << " " << endl;

        return false;
    }


    for (int i = 0; i < Nandares; i++) {


        if ((x - andarAtual) < andaresPrioritarios[i]) {

            if (andaresPrioritarios[i-1] == x){
                cout << "Andar ja requisitado" << endl;
                cout << " " << endl;
                return false;
            }

            for (int d = Nandares; d > i; --d) {
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

        cout << "CHAMANDO MOVIENTACAO" << endl;
        cout << " " << endl;

        if (parametro01->verificacao(relacao01) == true){

           
            this->status01 = FECHADA;
            this->status02 = PARADO;
            if (this->status01 == FECHADA && this->status02 == PARADO){
                
                
                string captura;
                cout << "OCUPACAO: " << this->ocupacao << " " << endl;
                cout << " " << endl;
                for (int i = 0; i < ocupacao; i++){

                    if (andaresPrioritarios[i] > Nandares){
                        cout << "Fora do escopo";

                        for (int i = 0; i < ocupacao; i++){
                        this->andaresPrioritarios[i] = (Nandares+1);};

                        this->ocupacao = 0;
                        this->status02 = PARADO;
                        this->status01 = ABERTA;

                        cout << "Elevador PARADO e porta ABERTA" << endl;
                        cout << " " << endl;
                    
                        return false;
                    }
                
                    this->status02 = MOVIMENTANDO_SE;
                    if (andarAtual < andaresPrioritarios[i]){

                        cout << "^ SUBINDO ^" << andaresPrioritarios[i] << endl;
                        cout << " " << endl;

                        this->status02=PARADO;
                        this->status01=ABERTA;

                        cout << "Elevador PARADO e porta ABERTA" << endl;
                        cout << " " << endl;

                        cout << "Digite X para fechar a porta " << endl;
                        cin >> captura;

                        this->andarAtual = andaresPrioritarios[i];

                        if (captura == "X" || captura == "x" ){
                            this->status01=FECHADA;
                        }
                        else {
                            cout << "Input não reconhecido" <<  endl;
                            cout << " " << endl;

                            this->status02 = PARADO;
                            this->status01 = ABERTA;

                            cout << "Elevador PARADO e porta ABERTA" << endl;
                            cout << " " << endl;

                            cout << "Saia do elevador" << endl;

                            for (int i = 0; i < ocupacao; i++){
                            this->andaresPrioritarios[i] = (Nandares+1);
                            };
                            this->ocupacao = 0;

                            return false;
                        }

                        
                        
                    }
                    else {
                        cout << "DESCENDO " << andaresPrioritarios[i] << endl;
                        cout << " " << endl;

                        this->status02=PARADO;
                        this->status01=ABERTA;

                        cout << "Elevador PARADO e porta ABERTA" << endl;
                        cout << " " << endl;

                        cout << "Digite X para fechar a porta " << endl;
                        cin >> captura;

                        this->andarAtual = andaresPrioritarios[i];

                        if (captura == "X" || captura == "x" ){
                            this->status01=FECHADA;
                        }
                        else {
                            cout << "Input não reconhecido" <<  endl;
                            cout << " " << endl;

                            this->status02 = PARADO;
                            this->status01 = ABERTA;

                            cout << "Elevador PARADO e porta ABERTA" << endl;
                            cout << " " << endl;

                            cout << "Saia do elevador" << endl;

                            for (int i = 0; i < ocupacao; i++){
                            this->andaresPrioritarios[i] = (Nandares+1);
                            };
                            this->ocupacao = 0;

                            return false;
                        }
                    } 
                };
                for (int i = 0; i < ocupacao; i++){
                this->andaresPrioritarios[i] = (Nandares+1);
                };
                this->ocupacao = 0;
                return true;   
            }

            else{
                return false;
            }

           

           
             
        }
        else {
            cout << "Falha na seguranca" << endl;
            this->status02  = PARADO;
            this->status01 = ABERTA;

            cout << "Elevador PARADO e porta ABERTA" << endl;
            cout << " " << endl;
            
            cout << "A porta esta: " << this->status01 << "e o elevador " << this->status02 << "favor, retirem-se" << endl;
            cout << " " << endl;

            for (int i = 0; i < ocupacao; i++){
                this->andaresPrioritarios[i] = (Nandares+1);
            };
            this->ocupacao = 0;

            return false;
        };

    }

   
};

#endif