#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <queue>

using namespace std;

class Animal {
    private:
        vector<vector<int>> matriz;
        int linhas, colunas;
        pair<int, int> posicaoAnimal;
        bool caminhoEncontrado;
    
        struct Celula {
            int linha, coluna, prioridade;
            pair<int, int> origem;
            
            bool operator<(const Celula& outra) const {
                return prioridade < outra.prioridade;
            }
        };
    
        int obterPrioridade(int valor);
        bool ehPosicaoSegura(int valor);
    
    public:
        Animal();
        Animal(const vector<vector<int>>& m) ;
        void Fugir();
        void imprimirMatriz();
        bool foiCaminhoEncontrado();
        void inserirAnimal(vector<vector<int>> &matrizAnimal, int linhas, int colunas);
        void setMatriz(vector<vector<int>> &matrizAnimal);
        void setCoordenadas();
    };
    
    
#endif