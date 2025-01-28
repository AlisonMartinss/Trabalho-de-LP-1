#ifndef PARAMETROFISICO_H
#define PARAMETROFISICO_H

#include <iostream>
#include<string>
#include <limits>

using namespace std;
template <typename T>

class parametroFisico
{
private:
    string nomeUnidade;
    T unidade;
public:
    T getUnidade();
    void setUnidade(T unidadeEsperada);

    string getnomeUnidade();
    void setnomeUnidade(string nomeUnidadeEsperada);
};

template<typename T>
void parametroFisico<T>::setUnidade(T unidadeEsperada){
    this->unidade = unidadeEsperada;
}

template<typename T>
T parametroFisico<T>::getUnidade(){
    return this->unidade;
}

template<typename T>
void parametroFisico<T>::setnomeUnidade(string nomeUnidadeEsperada){
    this->nomeUnidade = nomeUnidadeEsperada;
}

template<typename T>
string parametroFisico<T>::getnomeUnidade(){
    return this->nomeUnidade;
}

#endif


