#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class Config {
private:
    int iteracoes = 2;
    int vento = 0; // 0 = sem, 1 = cima, 2 = direita, 3 = baixo, 4 = esquerda
public:
    Config();
    int getIteracoes(); 
    int getVento();
};

#endif