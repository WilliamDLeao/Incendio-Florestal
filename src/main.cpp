#include "LeitorArquivos.hpp"
#include "Config.hpp"
#include "Fogo.hpp"

int main(){

    Config config;
    Fogo fogo;
    LeitorArquivo leitorArquivo;
    
    vector<vector<int>> matriz = leitorArquivo.lerArquivo();
    int linha = leitorArquivo.leX();
    int coluna = leitorArquivo.leY();

    int cont=0;
    while (cont<=config.getIteracoes())
    {
        int passos = 2;
        leitorArquivo.escreveArquivo(matriz, passos);
        //if alastra fogo tal faz isso aql
        fogo.alastrarFogoSemVento(matriz, linha, coluna);

        
        cont++;
    }
    
    

    return 0;
}