
#include "elevador.cpp"

#include <iostream>
#include <string>
#include <limits>



using namespace std;


int main (){
    int nParametros;
    int nAndares;
    string relacaoComparativa;

    elevador<int>* e1;


    cout << "Quantos andares tem seu predio" << endl;
    cout << " " << endl;
    cin  >> nAndares;


    cout << "Qual a relacao logica esperada? ( TETO x INPUT(ASS) ) " << endl;

    cout << "Maior (Somente para numeros). Recomendado para quando o input 'A' recebido deve ser maior que o parametro anteriormente ja definido, 'B' ex: A > B. Digite '>' " << endl;
    cout << "Menor (Somente para numeros). Recomendado para quando o input 'A' recebido deve ser menor que o parametro anteriormente ja definido, 'B' ex: A < B. Digite '<' " << endl;
    cout << "Diferente. Recomnedado para parametro onde se busca amplitude. ex: A != B. Digite '!=' " << endl;
    cout << "Igual. Recomnedado para parametro onde se busca exatidao. ex: A == B. Digite '=' " << endl;
    cin  >> relacaoComparativa;

    cout << "O numero de parametros a serem avaliados (INPUT ASSICRONO)" << endl;
    cout << " " << endl;
    cin  >> nParametros;

    int*    elementosComparaviosNumeros = new int   [nParametros];

    for (int i = 0; i < nParametros; i++){
        int elementoCapturado;
        cout << "Digite o numero do elemento da base a ser comparado: " << endl;
        cin >> elementoCapturado;
        elementosComparaviosNumeros[i] = elementoCapturado;          
    };
    
    e1 = new elevador<int>(relacaoComparativa,nAndares,nParametros,elementosComparaviosNumeros);    
    
    while (1){
        int opcoes;
        cout << "SELECIONE UMA DAS OPCOES:" << endl;
        cout << " ";
        cout << "1 - Chamar elevador.";
        if (e1->getOcupacao() != 0){;
            cout << " ";
            cout << "2 - Fechar a porta.";
        }

        cin >> opcoes;
        
        if (opcoes == 1){
            int andar;
            cout << "ANDAR ATUAL " << e1->getandarAtual() << endl;
            cout << "SELECIONE O ANDAR PRETENDIDO: ";
            cout << " ";
            cin >> andar;
            e1->requisicaoEdelegacao(andar);
        }
        else if (opcoes == 2){
            e1->setFechado();
            if (e1->movimentacao() == true){
                cout << "PESSOAS ENTREGE" << endl;
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