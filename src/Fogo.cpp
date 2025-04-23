#include "Fogo.hpp"
#include "Config.hpp"
#include "Animal.hpp"

Fogo::Fogo(){}
   void Fogo::alastrarFogoSemVento(vector<vector<int>> &matriz, int linha, int coluna, Animal& animal) {
    vector<pair<int, int>> queimar;
    bool animalAmeacado = false;

    for (int x = 0; x < linha; x++) {
        for (int y = 0; y < coluna; y++) {
            if (matriz[x][y] == 2) { 
                if (!animalAmeacado) {
                    if (x + 1 < linha && matriz[x+1][y] == 5) animalAmeacado = true;
                    if (x - 1 >= 0 && matriz[x-1][y] == 5) animalAmeacado = true;
                    if (y + 1 < coluna && matriz[x][y+1] == 5) animalAmeacado = true;
                    if (y - 1 >= 0 && matriz[x][y-1] == 5) animalAmeacado = true;
                }
                // marca árvores adjacentes para queimar
                if (x + 1 < linha && matriz[x+1][y] == 1) queimar.push_back({x+1, y});
                if (x - 1 >= 0 && matriz[x-1][y] == 1) queimar.push_back({x-1, y});
                if (y + 1 < coluna && matriz[x][y+1] == 1) queimar.push_back({x, y+1});
                if (y - 1 >= 0 && matriz[x][y-1] == 1) queimar.push_back({x, y-1});
            }
        }
    }

    if (animalAmeacado) {
        animal.setSegundaChance(true);
    }

    for (auto &pos : queimar) {
        int x = pos.first;
        int y = pos.second;
        matriz[x][y] = 2; 
    }
}
void Fogo::alastrarFogoBaixo(vector<vector<int>> &matriz, int linha, int coluna, Animal& animal){
    vector<pair<int, int>> queimar;
    bool animalAmeacado = false;

    if (animal.getSegundaChance() == true)
    {
        return;
    }

    for (int x = 0; x < linha; x++) 
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matriz[x][y] == 2)
            {
                if (!animalAmeacado)
                {
                    if (x + 1 < linha && matriz[x+1][y] == 5) animal.setSegundaChance(true);
                    if (x - 1 >= 0 && matriz[x-1][y] == 5) animal.setSegundaChance(true);
                    if (y + 1 < coluna && matriz[x][y+1] == 5) animal.setSegundaChance(true);
                    if (y - 1 >= 0 && matriz[x][y-1] == 5) animal.setSegundaChance(true);            
                }
                if (x + 1 < linha && matriz[x+1][y] == 1) queimar.push_back({x+1, y});

            }       
            
        }
    }
    if (animalAmeacado) {
        animal.setSegundaChance(true);
    }

    for (auto &pos : queimar) {
        int x = pos.first;
        int y = pos.second;
        matriz[x][y] = 2; 
    }
}

void Fogo::alastrarFogoDireita(vector<vector<int>> &matriz, int linha, int coluna, Animal& animal){
    vector<pair<int, int>> queimar;
    bool animalAmeacado = false;

    for (int x = 0; x < linha; x++) {
        for (int y = 0; y < coluna; y++) {
            if (matriz[x][y] == 2) { 
                if (!animalAmeacado) {
                    if (x + 1 < linha && matriz[x+1][y] == 5) animalAmeacado = true;
                    if (x - 1 >= 0 && matriz[x-1][y] == 5) animalAmeacado = true;
                    if (y + 1 < coluna && matriz[x][y+1] == 5) animalAmeacado = true;
                    if (y - 1 >= 0 && matriz[x][y-1] == 5) animalAmeacado = true;
                }
                // marca árvores adjacentes para queimar
                if (y + 1 < coluna && matriz[x][y+1] == 1) queimar.push_back({x, y+1});
            }
        }
    }

    if (animalAmeacado) {
        animal.setSegundaChance(true);
    }

    for (auto &pos : queimar) {
        int x = pos.first;
        int y = pos.second;
        matriz[x][y] = 2; 
    }

}

void Fogo::alastrarFogoCima(vector<vector<int>> &matriz, int linha, int coluna, Animal& animal){
    vector<pair<int, int>> queimar;
    bool animalAmeacado = false;

    for (int x = 0; x < linha; x++) {
        for (int y = 0; y < coluna; y++) {
            if (matriz[x][y] == 2) { 
                if (!animalAmeacado) {
                    if (x + 1 < linha && matriz[x+1][y] == 5) animalAmeacado = true;
                    if (x - 1 >= 0 && matriz[x-1][y] == 5) animalAmeacado = true;
                    if (y + 1 < coluna && matriz[x][y+1] == 5) animalAmeacado = true;
                    if (y - 1 >= 0 && matriz[x][y-1] == 5) animalAmeacado = true;
                }
                // marca árvores adjacentes para queimar
                if (x - 1 >= 0 && matriz[x-1][y] == 1) queimar.push_back({x-1, y});
            }
        }
    }

    if (animalAmeacado) {
        animal.setSegundaChance(true);
    }

    for (auto &pos : queimar) {
        int x = pos.first;
        int y = pos.second;
        matriz[x][y] = 2; 
    }

}

void Fogo::alastrarFogoEsquerda(vector<vector<int>> &matriz, int linha, int coluna, Animal& animal){
    vector<pair<int, int>> queimar;
    bool animalAmeacado = false;

    for (int x = 0; x < linha; x++) {
        for (int y = 0; y < coluna; y++) {
            if (matriz[x][y] == 2) { 
                if (!animalAmeacado) {
                    if (x + 1 < linha && matriz[x+1][y] == 5) animalAmeacado = true;
                    if (x - 1 >= 0 && matriz[x-1][y] == 5) animalAmeacado = true;
                    if (y + 1 < coluna && matriz[x][y+1] == 5) animalAmeacado = true;
                    if (y - 1 >= 0 && matriz[x][y-1] == 5) animalAmeacado = true;
                }
                // marca árvores adjacentes para queimar
                if (y - 1 >= 0 && matriz[x][y-1] == 1) queimar.push_back({x, y-1});
            }
        }
    }

    if (animalAmeacado) {
        animal.setSegundaChance(true);
    }

    for (auto &pos : queimar) {
        int x = pos.first;
        int y = pos.second;
        matriz[x][y] = 2; 
    }
}

void Fogo::delayPropagacao(vector<vector<int>> &matrizAux, int linha, int coluna){
    
    for (int x = 0; x < linha; x++)
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matrizAux[x][y] == 2)
            {
                matrizAux[x][y] = 7;
            }
            
        }
        
    }
}
void Fogo::alteraEstadoArvoreComFogo(vector<vector<int>> &matriz,vector<vector<int>> &matrizAux, int linha, int coluna ){
    
    for (int x = 0; x < linha; x++)
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matrizAux[x][y] == 7)
            {
                matriz[x][y] = 3;
            }
            
        }
        
    }
}

void Fogo::transfereFogoMatrizAuxiliar(vector<vector<int>> &matriz,vector<vector<int>> &matrizAux, int linha, int coluna ){
    
    for (int x = 0; x < linha; x++)
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matriz[x][y] == 2 && matrizAux[x][y] != 7)
            {
                matrizAux[x][y] = 2;
            }
            
        }
        
    }
}
    
bool Fogo::verificaFogo(vector<vector<int>> &matriz, int linha, int coluna){
    for (int x = 0; x < linha; x++)
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matriz[x][y] == 2) {
                return true;
            }
        }
        
    }
    return false;
}