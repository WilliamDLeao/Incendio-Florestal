#ifndef LEITORARQUIVO_HPP
#define LEITORARQUIVO_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <sstream>

using namespace std;

class LeitorArquivo {
private:
    int contadorArquivos;
    string nomeArquivoEntrada = "input.dat";
    string nomeArquivoSaida = "output.dat";

public:
    LeitorArquivo(int contador);
    LeitorArquivo();
    vector<vector<int>> lerArquivo();

    void limpaArquivo();
    void escreveArquivo(const vector<vector<int>>& matriz, int passos, int iteracao);
    void exibeMatriz(const vector<vector<char>>& matriz);
 
    int leX();
    int leY();

};

#endif