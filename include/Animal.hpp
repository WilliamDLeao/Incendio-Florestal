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
        vector<vector<int>> matrizOriginal;
        int linhas, colunas;
        pair<int, int> posicaoAnimal;
        bool caminhoEncontrado;
        int contaPassos=0;
        bool parado=false;
        int contadorIteracoes=0;

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
        void Fugir(vector<vector<int>>& matrizParam, vector<vector<int>>& matrizRastro);
        void imprimirMatriz(vector<vector<int>> &matrizAnimal);
        bool foiCaminhoEncontrado();
        void inserirAnimal(vector<vector<int>> &matrizAnimal, int linhas, int colunas);
        void setMatriz(vector<vector<int>> &matrizAnimal);
        void setMatrizOriginal(vector<vector<int>> &matrizOrig);
        void setCoordenadas();
        int getContaPassos();
        void addPassos();
        void florescerAmbiente(vector<vector<int>>& matrizParam,  vector<vector<int>>& matrizRastro);
    };
    
    
#endif