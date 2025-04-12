#ifndef FOGO_HPP
#define FOGO_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class Fogo {
private:
public:
    Fogo();
    void alastrarFogoSemVento(vector<vector<int>> &matriz, int x, int y);
    void alastrarFogoCima(vector<vector<int>> &matriz, int x, int y);
    void alastrarFogoDireita(vector<vector<int>> &matriz, int x, int y);
    void alastrarFogoBaixo(vector<vector<int>> &matriz, int x, int y);
    void alastrarFogoEsquerda(vector<vector<int>> &matriz, int x, int y);
    void delayPropagacao(vector<vector<int>> &matrizAux, int linha, int coluna );
    void alteraEstadoArvoreComFogo(vector<vector<int>> &matriz,vector<vector<int>> &matrizAux, int linha, int coluna );
    void transfereFogoMatrizAuxiliar(vector<vector<int>> &matriz,vector<vector<int>> &matrizAux, int linha, int coluna );
};

#endif