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
    int iteracoes = 10;
    int vento = 0; 
public:
    Config();
    int getIteracoes(); 
    int getVento();
};

#endif