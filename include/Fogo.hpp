#ifndef FOGO_HPP
#define FOGO_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include "Animal.hpp"

using namespace std;

class Fogo {
private:
public:
    Fogo();
    void alastrarFogoSemVento(vector<vector<int>> &matriz, int x, int y, Animal& animal);
    void alastrarFogoCima(vector<vector<int>> &matriz, int x, int y, Animal& animal);
    void alastrarFogoDireita(vector<vector<int>> &matriz, int x, int y, Animal& animal);
    void alastrarFogoBaixo(vector<vector<int>> &matriz, int x, int y, Animal& animal);
    void alastrarFogoEsquerda(vector<vector<int>> &matriz, int x, int y, Animal& animal);
    void delayPropagacao(vector<vector<int>> &matrizAux, int linha, int coluna );
    void alteraEstadoArvoreComFogo(vector<vector<int>> &matriz,vector<vector<int>> &matrizAux, int linha, int coluna );
    void transfereFogoMatrizAuxiliar(vector<vector<int>> &matriz,vector<vector<int>> &matrizAux, int linha, int coluna );
    bool verificaFogo(vector<vector<int>> &matriz, int linha, int coluna);
};

#endif