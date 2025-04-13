#include "Animal.hpp"

Animal::Animal(){}

Animal::Animal(const vector<vector<int>>& m) : matriz(m) {
            linhas = matriz.size();
            colunas = linhas > 0 ? matriz[0].size() : 0;
            caminhoEncontrado = false;
            
            // Encontra a posição inicial do animal (5)
            for (int i = 0; i < linhas; ++i) {
                for (int j = 0; j < colunas; ++j) {
                    if (matriz[i][j] == 5) {
                        posicaoAnimal = {i, j};
                        return;
                    }
                }
            }
            throw runtime_error("Animal não encontrado na matriz!");
        }

void Animal::Fugir(){
    if (linhas == 0 || colunas == 0) {
        cout << "Matriz vazia!" << endl;
        return;
    }

    const int dir_linha[] = {-1, 1, 0, 0};
    const int dir_coluna[] = {0, 0, -1, 1};

    vector<vector<bool>> visitado(linhas, vector<bool>(colunas, false));
    vector<vector<pair<int, int>>> origem(linhas, vector<pair<int, int>>(colunas, {-1, -1}));
    priority_queue<Celula> fila;
    
    fila.push({posicaoAnimal.first, posicaoAnimal.second, 0, {-1, -1}});
    visitado[posicaoAnimal.first][posicaoAnimal.second] = true;

    while (!fila.empty()) {
        Celula atual = fila.top();
        fila.pop();

        if (ehPosicaoSegura(matriz[atual.linha][atual.coluna])) {
            // Atualiza a matriz com o caminho
            pair<int, int> anterior = atual.origem;
            
            // Nova posição do animal
            matriz[atual.linha][atual.coluna] = 5;
            posicaoAnimal = {atual.linha, atual.coluna};

            // Marca a última posição (8)
            if (anterior.first != -1) {
                matriz[anterior.first][anterior.second] = 8;
            }
            
            cout << "Animal encontrou segurança!" << endl ;
            caminhoEncontrado = true;
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int novaLinha = atual.linha + dir_linha[i];
            int novaColuna = atual.coluna + dir_coluna[i];

            if (novaLinha < 0 || novaLinha >= linhas || 
                novaColuna < 0 || novaColuna >= colunas) {
                continue;
            }

            if (matriz[novaLinha][novaColuna] != 2 && !visitado[novaLinha][novaColuna]) {
                int prioridade = obterPrioridade(matriz[novaLinha][novaColuna]);
                if (prioridade >= 0) {
                    visitado[novaLinha][novaColuna] = true;
                    origem[novaLinha][novaColuna] = {atual.linha, atual.coluna};
                    fila.push({novaLinha, novaColuna, prioridade, {atual.linha, atual.coluna}});
                }
            }
        }
    }

    cout << "Animal não conseguiu encontrar uma rota segura!" << endl;

}

void Animal::imprimirMatriz(){
    
    for (const auto& linha : matriz) {
        for (int valor : linha) {
            cout << valor << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

bool Animal::foiCaminhoEncontrado() {
    return caminhoEncontrado;

}

int Animal::obterPrioridade(int valor){
    if (valor == 4) return 5;      // Máxima prioridade
    else if (valor == 0) return 4; 
    else if (valor == 1) return 3;
    else if (valor == 3) return 2;
    else if (valor == 8) return 1; // Caminho percorrido - menor prioridade
    else if (valor == 5) return 0; // Posição atual do animal
    else return -1;                // Obstáculos (2) ou inválidos
}

bool Animal::ehPosicaoSegura(int valor){
    return valor == 4 || valor == 0 || valor == 1 || valor == 3 || valor == 8;
}

void Animal::inserirAnimal(vector<vector<int>> &matrizAnimal, int linhas, int colunas){
    int cont=0;
    for (int x = 0; x < linhas; x++) 
    {
        for (int y = 0; y < colunas; y++)
        {
            if (matrizAnimal[x][y] == 0 && cont==0)
            {
                matrizAnimal[x][y] = 5;
                cont ++;
            }
            
        }
    }
}
void Animal::setMatriz(vector<vector<int>> &matrizAnimal) {
    matrizAnimal[posicaoAnimal.first][posicaoAnimal.second] = 5;
    matriz = matrizAnimal;
}
void Animal::setCoordenadas(){ //aparentemente nao é isso o problema
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (matriz[i][j] == 5) {
                posicaoAnimal = {i, j};
                return;
            }
        }
    }
}