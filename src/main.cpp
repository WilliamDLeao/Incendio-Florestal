#include "LeitorArquivos.hpp"
#include "Config.hpp"
#include "Fogo.hpp"
#include "Animal.hpp"

int numIteracao=0;

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
    vector<vector<int>> matrizTeste = matriz;
    vector<vector<int>> matrizRastro = matriz;
    
    while (cont<=config.getIteracoes())
    {
        animal2.setMatriz(matrizTeste);
        animal2.setMatrizOriginal(matriz);
        animal2.Fugir(matriz, matrizRastro);
        animal2.imprimirMatriz(matriz);
        
        fogo.transfereFogoMatrizAuxiliar(matriz, matrizAuxFogo, linha, coluna);
        fogo.transfereFogoMatrizAuxiliar(matrizRastro, matrizAuxFogo, linha, coluna);
        fogo.alteraEstadoArvoreComFogo(matriz, matrizAuxFogo, linha, coluna);
        fogo.alteraEstadoArvoreComFogo(matrizRastro, matrizAuxFogo, linha, coluna);
        switch (config.getVento())
        {
            case 0:
            fogo.alastrarFogoSemVento(matriz, linha, coluna, animal2); 
            fogo.alastrarFogoSemVento(matrizRastro, linha, coluna, animal2); 
            break;
            
            case 1:
                fogo.alastrarFogoCima(matriz, linha, coluna);
                fogo.alastrarFogoCima(matrizRastro, linha, coluna);
                break;
        
            case 2:
                fogo.alastrarFogoDireita(matriz, linha, coluna);
                fogo.alastrarFogoDireita(matrizRastro, linha, coluna);
            break;

            case 3:
                fogo.alastrarFogoBaixo(matriz, linha, coluna);
                fogo.alastrarFogoBaixo(matrizRastro, linha, coluna);

            break;

            case 4:
                fogo.alastrarFogoEsquerda(matriz, linha, coluna);
                fogo.alastrarFogoEsquerda(matrizRastro, linha, coluna);
            break;
            
        }
        fogo.delayPropagacao(matrizAuxFogo, linha, coluna);
        animal2.estaCercado(matrizRastro);
        leitorArquivo.escreveArquivo(matrizRastro, animal2.getContaPassos(), cont, animal2.getContaAgua(), animal2.getCercado());
        if (animal2.getCercado() == true)
        {
            return 0;
        }
        
        cont++;
    }
    
    

    return 0;
}