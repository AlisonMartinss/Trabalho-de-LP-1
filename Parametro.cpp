#ifndef PARAMETRO_H
#define PARAMETRO_H


/* =-=-=-=-= Objetos =-=-=-=-= */
#include "parametroFisico.h"

/* =-=-=-=-= Bibliotecas =-=-=-=-= */
#include <iostream>
#include<string>
#include <limits>

using namespace std;

/* =-=-=-=-= ORIENTAÇÕES DE USO =-=-=-=-= */
/*

a) Definir o tipo primitivo na intancia, define o tipo de parametros a serem comparados.
b) nParametros Define o numeros de parametros a serem comparados.
c) 'arr' presente no construtor vai receber uma lista onde os elementos serão comparados aos atributos 'valores' dos objetos parametroFisico.
d) relação no metodo verificacao, recebe o tipo de comparação esperada para se fazer entre os 'valores' e os elementos de 'arr'.

*/

template<typename T>
class parametro {

private :   

int  nParametros;
parametroFisico<T>* FisicaArray;
T* ElementosComparativos;

void preenchimento(){ 
for (int i = 0; i < nParametros; i++){
    string nomeZ;
    T valorZ;

    cout << "Digite o nome do parametro: ";
    cin >> nomeZ;
    FisicaArray[i].setnomeUnidade(nomeZ);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Digite o parametro esperado no retorno da verificacao de seguranca: ";
    cin >> valorZ;
    FisicaArray[i].setUnidade(valorZ);   
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
 }
}

void exibirMensagem(string status, const string& nome, const T& esperado, const T& recebido, string relacao) {
    cout << status << " no parametro " << nome 
         << ". Esperando " << "'" << relacao << "'" << " " << esperado << ", retornou " << recebido << ".\n";
}


public:

parametro (int nFisicA, T* arr){

    this->nParametros = nFisicA;
    FisicaArray = new parametroFisico<T>[nParametros];
    ElementosComparativos = arr;
    preenchimento();
}

~parametro() {
    delete[] FisicaArray;
}

bool verificacao (string relacao){
for (int i = 0; i < nParametros; i++){

    if ( (relacao == ">" || relacao == "<")){
    
        if (relacao == ">"){
            if( ElementosComparativos[i] > FisicaArray[i].getUnidade()){
              exibirMensagem("Sucesso", FisicaArray[i].getnomeUnidade(), FisicaArray[i].getUnidade(), ElementosComparativos[i],relacao);
              return true;
            }
            else{
              exibirMensagem("Falha", FisicaArray[i].getnomeUnidade(), FisicaArray[i].getUnidade(), ElementosComparativos[i],relacao);
              return false;

            
            }
        }

        else if (relacao == "<"){
            if(ElementosComparativos[i] < FisicaArray[i].getUnidade()){
               exibirMensagem("Sucesso", FisicaArray[i].getnomeUnidade(), FisicaArray[i].getUnidade(), ElementosComparativos[i],relacao);
               return true;
            }
            else{
                 exibirMensagem("Falha", FisicaArray[i].getnomeUnidade(), FisicaArray[i].getUnidade(), ElementosComparativos[i],relacao);
                 return false;
                
            }
        }
    }

    else if (relacao == ">" || relacao == "<"){
        cout << "Esperando um numero. Recebido algo diferente." << endl;
        return false;
    }


    else if (relacao == "="){
         if(ElementosComparativos[i] != FisicaArray[i].getUnidade()){
          exibirMensagem("Falha", FisicaArray[i].getnomeUnidade(), FisicaArray[i].getUnidade(), ElementosComparativos[i],relacao);
          return false;
        }
        else{
            exibirMensagem("Sucesso", FisicaArray[i].getnomeUnidade(), FisicaArray[i].getUnidade(), ElementosComparativos[i],relacao);
            return true;
           
        }
    }

    else if (relacao == "!="){
        if(ElementosComparativos[i] == FisicaArray[i].getUnidade()){
          exibirMensagem("Falha", FisicaArray[i].getnomeUnidade(), FisicaArray[i].getUnidade(), ElementosComparativos[i],relacao);
          return false;
        }
        else{
            exibirMensagem("Sucesso", FisicaArray[i].getnomeUnidade(), FisicaArray[i].getUnidade(), ElementosComparativos[i],relacao);
            return true;
          
        }
    }

    else {
        cout << "Você não digitou um simbolo de comparação esperado" << endl;
        return false;
    }
 }
 }
};

#endif



