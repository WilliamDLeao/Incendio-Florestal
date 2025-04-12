#include "Fogo.hpp"
#include "Config.hpp"

Fogo::Fogo(){}

void Fogo::alastrarFogoSemVento(vector<vector<int>> &matriz, int linha, int coluna ){
    for (int x = 0; x < linha; x++) 
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matriz[x][y] == 2)
            {
                if (x + 1 < linha && matriz[x+1][y] == 1) matriz[x + 1][y] = 7;
                if (x - 1 >= 0 && matriz[x-1][y] == 1) matriz[x - 1][y] = 7;
                if (y + 1 < coluna && matriz[x][y+1] == 1) matriz[x][y + 1] = 7;
                if (y - 1 >= 0 && matriz[x][y-1] == 1) matriz[x][y - 1] = 7;            
            }
            
        }
    }
    for (int x = 0; x < linha; x++)
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matriz[x][y] == 7)
            {
                matriz[x][y] = 2;
            }
            
        }
        
    }
}
void Fogo::alastrarFogoBaixo(vector<vector<int>> &matriz, int linha, int coluna ){
    for (int x = 0; x < linha; x++) 
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matriz[x][y] == 2)
            {
                if (x + 1 < linha && matriz[x+1][y] == 1) matriz[x + 1][y] = 7;
            }
            
        }
    }
    for (int x = 0; x < linha; x++)
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matriz[x][y] == 7)
            {
                matriz[x][y] = 2;
            }
            
        }
        
    }
}

void Fogo::alastrarFogoDireita(vector<vector<int>> &matriz, int linha, int coluna ){
    for (int x = 0; x < linha; x++) 
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matriz[x][y] == 2)
            {
                if (y + 1 < coluna && matriz[x][y+1] == 1) matriz[x][y + 1] = 7;
            }
            
        }
    }
    for (int x = 0; x < linha; x++)
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matriz[x][y] == 7)
            {
                matriz[x][y] = 2;
            }
            
        }
        
    }
}

void Fogo::alastrarFogoCima(vector<vector<int>> &matriz, int linha, int coluna ){
    for (int x = 0; x < linha; x++) 
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matriz[x][y] == 2)
            {
                if (x - 1 >= 0 && matriz[x-1][y] == 1) matriz[x - 1][y] = 7;
            }
            
        }
    }
    for (int x = 0; x < linha; x++)
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matriz[x][y] == 7)
            {
                matriz[x][y] = 2;
            }
            
        }
        
    }
}

void Fogo::alastrarFogoEsquerda(vector<vector<int>> &matriz, int linha, int coluna ){
    for (int x = 0; x < linha; x++) 
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matriz[x][y] == 2)
            {
                if (y - 1 >= 0 && matriz[x][y-1] == 1) matriz[x][y - 1] = 7;            
            }
            
        }
    }
    for (int x = 0; x < linha; x++)
    {
        for (int y = 0; y < coluna; y++)
        {
            if (matriz[x][y] == 7)
            {
                matriz[x][y] = 2;
            }
            
        }
        
    }
}

void Fogo::delayPropagacao(vector<vector<int>> &matrizAux, int linha, int coluna ){
    
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
    
