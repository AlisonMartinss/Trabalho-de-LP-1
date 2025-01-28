
#include "elevador.cpp"

#include <iostream>
#include <string>
#include <limits>

using namespace std;


int main (){
    int nParametros;
    int nAndares;
    string relacaoComparativa;

    int dadoComparativo;

    bool elementosNumerosFlag = false;
    bool elementosStringsFlag = false;

    elevador<int>* e1;

    cout << "O numero de parametros a serem avaliados" << endl;
    cout << " " << endl;
    cin  >> nParametros;

    int*    elementosComparaviosNumeros = new int   [nParametros];
    string* elementosComparaviosString  = new string[nParametros];

    cout << "Quantos andares tem seu predio" << endl;
    cout << " " << endl;
    cin  >> nAndares;

    while (1)
    {
        cout << "Qual tipo de dado será comparado? " << endl;
        cout << " " << endl;
        cout << "Digite" << endl;

        cout << "1 - string" << endl;
        cout << " " << endl;
        cout << "2 - numeros" << endl;
        cout << " " << endl;
        cin >> dadoComparativo;


        if (dadoComparativo ==  1){
        int elementoCapturado;
        for (int i = 0; i < nParametros; i++){
            cout << "Digite o elemento da base a ser compara: " << endl;
            cin >> elementoCapturado;
            elementosComparaviosString[i] = elementoCapturado;          
        };
        
        elementosStringsFlag = true;
        delete elementosComparaviosNumeros;
        break;
        
      }
      else if (dadoComparativo == 2){

            int elementoCapturado;
            for (int i = 0; i < nParametros; i++){
                cout << "Digite o elemento da base a ser compara: " << endl;
                cin >> elementoCapturado;
                elementosComparaviosNumeros[i] = elementoCapturado;          
            }
            elementosNumerosFlag = true;
            delete elementosComparaviosString;
            break;
            
      }
      else {
            cout << "Parametro fora do esperado" << endl;
            cout << "Reinicie a aplicação" << endl;
       }
        
    }

    cout << "Qual a relacao logica esperada? " << endl;

    cout << "Maior (Somente para numeros). Recomendado para quando o input 'A' recebido deve ser maior que o parametro anteriormente ja definido, 'B' ex: A > B. Digite '>' " << endl;
    cout << "Menor (Somente para numeros). Recomendado para quando o input 'A' recebido deve ser menor que o parametro anteriormente ja definido, 'B' ex: A < B. Digite '<' " << endl;
    cout << "Diferente. Recomnedado para parametro onde se busca amplitude. ex: A != B. Digite '!=' " << endl;
    cout << "Igual. Recomnedado para parametro onde se busca exatidao. ex: A == B. Digite '=' " << endl;
    cin  >> relacaoComparativa;
    

    if (elementosNumerosFlag == true){
        e1 = new elevador<int>(relacaoComparativa,nAndares,nParametros,elementosComparaviosNumeros);    
    }
    


    while (1){
        int opcoes;
        cout << "SELECIONE UMA DAS OPCOES:" << endl;
        cout << " ";
        cout << "1 - Chamar elevador.";
        if (e1.getOcupacao() != 0){;
            cout << " ";
            cout << "2 - Fechar a porta.";
        }

        cin >> opcoes;
        
        if (opcoes == 1){
            int andar;
            cout << "SELECIONE O ANDAR PRETENDIDO: ";
            cout << " ";
            cin >> andar;
            e1.requisicaoEdelegacao(andar);
        }
        else if (opcoes == 2){
            if (e1.movimentacao() == true){
                cout << "movimento" << endl;
            }
            else {
                cout << "REINICIE O ELEVADOR" << endl;
                
            }
            

        }
        else {
            cout << "ESSA OPCAO NAO EXISTE";
            cout << " ";
        }
    

    }
  

    return 0;
}