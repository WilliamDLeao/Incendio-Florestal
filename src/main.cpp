#include "LeitorArquivos.hpp"   

int main(){

    int cont=1;
    while (cont<=2)
    {
        LeitorArquivo leitorArquivo(cont);
        vector<vector<int>> matriz = leitorArquivo.lerArquivo();

        int passos = 2;
        leitorArquivo.escreveArquivo(matriz, passos);
                
        cont++;
    }
    
    

    return 0;
}