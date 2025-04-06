#ifndef LEITORARQUIVO_HPP
#define LEITORARQUIVO_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include "Modulo.hpp"
#include "Astronauta.hpp"

using namespace std;

class LeitorArquivo {
private:
    int contadorArquivos;
    string nomeArquivoEntrada;
    string nomeArquivoSaida;

public:
    LeitorArquivo(int contador);
    LeitorArquivo();
    vector<vector<char>> lerArquivo();
    void escreveArquivo(const vector<vector<char>>& matriz,list<Astronauta> resgatados, int passos);
    void exibeMatriz(const vector<vector<char>>& matriz);
    list<Astronauta> cadastraAstronauta();
    list<Astronauta> cadastraPosicao(list<Astronauta> astronautas);
    int pegaX();
    int pegaY();
    vector<vector<Modulo>> coverteMatriz_to_Modulo(vector<vector<char>> matrizChar, int linha, int coluna);
};

#endif