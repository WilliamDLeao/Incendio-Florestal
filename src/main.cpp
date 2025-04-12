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

    int cont=1;
    leitorArquivo.limpaArquivo();
    vector<vector<int>> matrizAux = matriz; 

    while (cont<=config.getIteracoes())
    {
        int passos = 2;
        fogo.transfereFogoMatrizAuxiliar(matriz, matrizAux, linha, coluna);
        fogo.alteraEstadoArvoreComFogo(matriz, matrizAux, linha, coluna);
        switch (config.getVento())
        {
            case 0:
                fogo.alastrarFogoSemVento(matriz, linha, coluna); 
            break;

            case 1:
                fogo.alastrarFogoCima(matriz, linha, coluna);
            break;
        
            case 2:
                fogo.alastrarFogoDireita(matriz, linha, coluna);
            break;

            case 3:
                fogo.alastrarFogoBaixo(matriz, linha, coluna);
            break;

            case 4:
                fogo.alastrarFogoEsquerda(matriz, linha, coluna);
            break;
            
        }
        fogo.delayPropagacao(matrizAux, linha, coluna);
        leitorArquivo.escreveArquivo(matriz, passos, cont);
        cont++;
    }
    
    

    return 0;
}