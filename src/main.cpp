#include "LeitorArquivos.hpp"
#include "Config.hpp"
#include "Fogo.hpp"
#include "Animal.hpp"

int contaPassos=0, numIteracao=0;

int main(){

    Config config;
    Fogo fogo;
    LeitorArquivo leitorArquivo;
    Animal animal;
    
    vector<vector<int>> matriz = leitorArquivo.lerArquivo();
    int linha = leitorArquivo.leX();
    int coluna = leitorArquivo.leY();
    
    int cont=1;
    leitorArquivo.limpaArquivo();
    vector<vector<int>> matrizAuxFogo = matriz; 
    vector<vector<int>> matrizAuxAnimal = matriz; 

    animal.inserirAnimal(matrizAuxAnimal, linha, coluna);

    Animal animal2(matrizAuxAnimal);
    while (cont<=config.getIteracoes())
    {
        int passos = 2;
        vector<vector<int>> matrizTeste = matriz;
        animal2.setMatriz(matrizTeste);
        animal2.Fugir();
        animal2.imprimirMatriz();
        fogo.transfereFogoMatrizAuxiliar(matriz, matrizAuxFogo, linha, coluna);
        fogo.alteraEstadoArvoreComFogo(matriz, matrizAuxFogo, linha, coluna);
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
        fogo.delayPropagacao(matrizAuxFogo, linha, coluna);
        leitorArquivo.escreveArquivo(matriz, passos, cont);
        cont++;
    }
    
    

    return 0;
}