#include "LeitorArquivos.hpp"
#include "Config.hpp"
#include "Fogo.hpp"
#include "Animal.hpp"

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
        if (config.getVento() == 0)
        {
        }
        
        switch (config.getVento())
        {
            case 0:
            fogo.alastrarFogoSemVento(matriz, linha, coluna, animal2);  //é a porra do switch case
            fogo.alastrarFogoSemVento(matrizRastro, linha, coluna, animal2); 
            break;
            
            case 1:
                fogo.alastrarFogoCima(matriz, linha, coluna, animal2);
                fogo.alastrarFogoCima(matrizRastro, linha, coluna, animal2);
                break;
        
            case 2:
                fogo.alastrarFogoDireita(matriz, linha, coluna, animal2);
                fogo.alastrarFogoDireita(matrizRastro, linha, coluna, animal2);
            break;

            case 3:
                fogo.alastrarFogoBaixo(matriz, linha, coluna, animal2);
                fogo.alastrarFogoBaixo(matrizRastro, linha, coluna, animal2);

            break;

            case 4:
                fogo.alastrarFogoEsquerda(matriz, linha, coluna, animal2);
                fogo.alastrarFogoEsquerda(matrizRastro, linha, coluna, animal2);
            break;
            
        }
        animal2.estaCercado(matrizRastro);
        leitorArquivo.escreveArquivo(matrizRastro, animal2.getContaPassos(), cont, animal2.getContaAgua(), animal2.getCercado());
        fogo.delayPropagacao(matrizAuxFogo, linha, coluna);
        if (animal2.getCercado() == true)
        {
            return 0;
        }
        
        cont++;
    }
    
    

    return 0;
}