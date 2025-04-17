#include <vector>
#include "LeitorArquivos.hpp"

LeitorArquivo::LeitorArquivo(){}
vector<vector<int>> LeitorArquivo::lerArquivo() {
    ifstream inFile(nomeArquivoEntrada.c_str());
    if (!inFile) {
        cerr << "Não foi possível abrir o arquivo de entrada(por erro ou porque ele não existe): " << nomeArquivoEntrada << "\n";
        exit(EXIT_FAILURE);
    }

    int linhas, colunas;
    inFile >> linhas >> colunas;

    if (linhas <= 0 || colunas <= 0) {
        cerr << "Número inválido de linhas ou colunas\n";
        exit(EXIT_FAILURE);
    }

    int posicaoFogoX, posicaoFogoY;
    inFile >> posicaoFogoX >> posicaoFogoY;

    vector<vector<int>> matriz(linhas, vector<int>(colunas));

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            inFile >> matriz[i][j];
        }
    }
    return matriz;
}
void LeitorArquivo::limpaArquivo() {
    ofstream outFile(nomeArquivoSaida.c_str(), ios::trunc); // modo trunc apaga o conteúdo
    if (!outFile) {
        cerr << "Não foi possível abrir o arquivo para limpeza: " << nomeArquivoSaida << "\n";
        exit(EXIT_FAILURE);
    }
}
void LeitorArquivo::escreveArquivo(const vector<vector<int>>& matriz, int passos, int iteracao) {
    ofstream outFile(nomeArquivoSaida.c_str(), ios::app); 
    if (!outFile) {
        cerr << "Não foi possível abrir o arquivo de saída: " << nomeArquivoSaida << "\n";
        exit(EXIT_FAILURE);
    }

    outFile << "Iteração número " << iteracao << ":\n";

    for (const auto& linha : matriz) {
        for (int elemento : linha) {
            outFile << elemento << " ";
        }
        outFile << '\n';
    }

    outFile << "Passos: " << passos << "\n\n";
}

void LeitorArquivo::exibeMatriz(const vector<vector<char>>& matriz) {
    cout << "\nConteúdo armazenado na matriz:\n";
    for (const auto& linha : matriz) {
        for (int elemento : linha) {
            cout << elemento;
        }
        cout << '\n';
    }
}

int LeitorArquivo::leX(){
    ifstream inFile(nomeArquivoEntrada.c_str());
    int linhas;
    inFile >> linhas;
    return linhas;
}

int LeitorArquivo::leY(){
    ifstream inFile(nomeArquivoEntrada.c_str());
    int linhas, colunas;
    inFile >> linhas >> colunas;
    return colunas;
}
