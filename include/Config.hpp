#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>

using namespace std;
/*
-vazio e seguro (0) nao queima
-arvore saudavel (1) queima
-arvore em chamas (2) tem que virar cinza
-arvore queimada(3) nao queima
-agua (4)
*/
class Config {
private:
    int iteracoes = 10;
    int vento = 4; // 0 = sem, 1 = cima, 2 = direita, 3 = baixo, 4 = esquerda
public:
    Config();
    int getIteracoes(); 
    int getVento();
};

#endif