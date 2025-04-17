#include "Animal.hpp"

Animal::Animal(){}

Animal::Animal(const vector<vector<int>>& m) : matriz(m) {
            linhas = matriz.size();
            colunas = linhas > 0 ? matriz[0].size() : 0;
            caminhoEncontrado = false;
            
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

void Animal::imprimirMatriz(vector<vector<int>> &matrizAnimal){
    
    for (const auto& linha : matrizAnimal) {
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
    else if (valor == 5) return 0; 
    else return -1;               
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
void Animal::setCoordenadas(){ 
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (matriz[i][j] == 5) {
                posicaoAnimal = {i, j};
                return;
            }
        }
    }
}
int Animal::getContaPassos(){
    return contaPassos;
}
void Animal::addPassos(){
    contaPassos++;
}
void Animal::florescerAmbiente(vector<vector<int>>& matrizParam, vector<vector<int>>& matrizRastro) {
    int i = posicaoAnimal.first;
    int j = posicaoAnimal.second;

    // modifica matriz que o animal anda
    matrizParam[i][j] = 5; 
    if (i + 1 < linhas) matrizParam[i + 1][j] = 1;
    if (j + 1 < colunas) matrizParam[i][j + 1] = 1;
    if (i - 1 >= 0) matrizParam[i - 1][j] = 1;
    if (j - 1 >= 0) matrizParam[i][j - 1] = 1;

    // modifica matriz que o animal não anda
    matrizRastro[i][j] = 0;
    if (i + 1 < linhas) matrizRastro[i + 1][j] = 1;
    if (j + 1 < colunas) matrizRastro[i][j + 1] = 1;
    if (i - 1 >= 0) matrizRastro[i - 1][j] = 1;
    if (j - 1 >= 0) matrizRastro[i][j - 1] = 1;
}

void Animal::setMatrizOriginal(vector<vector<int>> &matrizOrig) {
    matrizOriginal = matrizOrig;
}

void Animal::Fugir(vector<vector<int>>& matrizParam,  vector<vector<int>>& matrizRastro) {
    segundaChance = false;
    if (matrizParam.empty() || matrizParam[0].empty()) {
        cout << "Matriz vazia!" << endl;
        return;
    }
    if (parado == true && contadorIteracoes != 2)
    {
        contadorIteracoes++;
        return;
    }
    if (parado == true && contadorIteracoes == 2)
    {
        parado = false;
        contadorIteracoes = 0;
    }
    
    
    const int dir_linha[] = {-1, 1, 0, 0};
    const int dir_coluna[] = {0, 0, -1, 1};
    addPassos();
    int linhas = matrizParam.size();
    int colunas = matrizParam[0].size();
    vector<vector<bool>> visitado(linhas, vector<bool>(colunas, false));
    vector<vector<pair<int, int>>> origem(linhas, vector<pair<int, int>>(colunas, {-1, -1}));
    priority_queue<Celula> fila;
    
    fila.push({posicaoAnimal.first, posicaoAnimal.second, 0, {-1, -1}});
    visitado[posicaoAnimal.first][posicaoAnimal.second] = true;

    while (!fila.empty()) {
        Celula atual = fila.top();
        fila.pop();

        if (ehPosicaoSegura(matrizParam[atual.linha][atual.coluna])) {
            pair<int, int> anterior = atual.origem;
            
            matrizParam[atual.linha][atual.coluna] = 5;
            posicaoAnimal = {atual.linha, atual.coluna};

            if (anterior.first != -1) {
                matrizParam[anterior.first][anterior.second] = 8;
            }
            
            if (matrizRastro[atual.linha][atual.coluna] == 4) {
                parado = true;
                florescerAmbiente(matrizParam, matrizRastro);
              
            }
            
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

            if (matrizParam[novaLinha][novaColuna] != 2 && !visitado[novaLinha][novaColuna]) {
                int prioridade = obterPrioridade(matrizParam[novaLinha][novaColuna]);
                if (prioridade >= 0) {
                    visitado[novaLinha][novaColuna] = true;
                    origem[novaLinha][novaColuna] = {atual.linha, atual.coluna};
                    fila.push({novaLinha, novaColuna, prioridade, {atual.linha, atual.coluna}});
                }
            }
        }
    }
}
void Animal::setSegundaChance(bool segundaChan){
    segundaChance = segundaChan;
}
bool Animal::getSegundaChance(){
    return segundaChance;
}