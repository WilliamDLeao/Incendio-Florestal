#include <vector>
#include "LeitorArquivos.hpp"
#include "Modulo.hpp"
#include "Astronauta.hpp"

LeitorArquivo::LeitorArquivo(int contador) : contadorArquivos(contador) {
    nomeArquivoEntrada = "entrada" + to_string(contadorArquivos) + ".txt";
    nomeArquivoSaida = "saida" + to_string(contadorArquivos) + ".txt";
}
LeitorArquivo::LeitorArquivo(){}
vector<vector<char>> LeitorArquivo::lerArquivo() {
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

    vector<vector<char>> matriz(linhas, vector<char>(colunas));

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            inFile >> matriz[i][j];
        }
    }
    return matriz;
}

list<Astronauta> LeitorArquivo::cadastraAstronauta() {
    ifstream inFile(nomeArquivoEntrada.c_str());
    if (!inFile) {
        cerr << "Não foi possível abrir o arquivo de entrada: " << nomeArquivoEntrada << "\n";
        exit(EXIT_FAILURE);
    }

    string line;

    list<Astronauta> astronautas;

    Astronauta astronauta;

    while(getline(inFile, line)) {
        if(line == "Astronautas: ") {
            break;
        }     
    }

    while(getline(inFile, line)) {
        if(line == "Posições dos astronautas na matriz: ") {
            break;
        }
        stringstream ss(line);
        string nome;
        int saude;
        bool necessidadeUrgente;
        
        getline(ss, nome, ',');
        ss >> saude;
        
        astronauta.setNivelSaude(saude);
        astronauta.setNome(nome);

        ss.ignore();  
        ss >> necessidadeUrgente;
        astronauta.setAtendimentoUrgente(necessidadeUrgente);
        
        astronautas.emplace_back(astronauta);

    }

    return astronautas;
}

list<Astronauta> LeitorArquivo::cadastraPosicao(list<Astronauta> astronautas) {
    ifstream inFile(nomeArquivoEntrada.c_str());
    
    string line;

    Astronauta astronauta;

    while(getline(inFile, line)) {
        if(line == "Posições dos astronautas na matriz: ") {
            break;
        }     
    }

    while(getline(inFile, line)) {
        if(line == "Posições dos astronautas na matriz: ") {
            break;
        }
        stringstream ss(line);
        string nome, nomeSave;
        int posicaoX, posicaoY;
        
        getline(ss, nome, ':');
        ss.ignore();
        ss.ignore();

        ss >> posicaoX;
        
        ss.ignore();  

        ss >> posicaoY;

        for(Astronauta &astronautaAux: astronautas){
            if (astronautaAux.getNome() == nome) 
            {
                astronautaAux.setX(posicaoX);
                astronautaAux.setY(posicaoY);
            }
            
        }

        astronauta.setY(posicaoY);

    }
    return astronautas;

}

void LeitorArquivo::escreveArquivo(const vector<vector<char>>& matriz, list<Astronauta> resgatados, int passos) {
    ofstream outFile(nomeArquivoSaida.c_str());
    if (!outFile) {
        cerr << "Não foi possível abrir o arquivo de saída: " << nomeArquivoSaida << "\n";
        exit(EXIT_FAILURE);
    }

    for (const auto& linha : matriz) {
        for (char elemento : linha) {
            outFile << elemento;
        }
        outFile << '\n';
    }

    outFile << "Passos: " << passos << endl;
    outFile << "Astronautas resgatados: ";

    for (Astronauta astronautaAux : resgatados)
    {
        outFile << astronautaAux.imprimir();
    }
    

}

void LeitorArquivo::exibeMatriz(const vector<vector<char>>& matriz) {
    cout << "\nConteúdo armazenado na matriz:\n";
    for (const auto& linha : matriz) {
        for (char elemento : linha) {
            cout << elemento;
        }
        cout << '\n';
    }
}

int LeitorArquivo::pegaX(){
    ifstream inFile(nomeArquivoEntrada.c_str());
    int linhas;
    inFile >> linhas;
    return linhas;
}

int LeitorArquivo::pegaY(){
    ifstream inFile(nomeArquivoEntrada.c_str());
    int linhas, colunas;
    inFile >> linhas >> colunas;
    return colunas;
}

vector<vector<Modulo>> LeitorArquivo::coverteMatriz_to_Modulo(vector<vector<char>> matrizChar, int linhas, int colunas) {
    vector<vector<Modulo>> matrizModulo; 

    matrizModulo.resize(linhas); 

    for (int i = 0; i < linhas; ++i) {
        matrizModulo[i].reserve(colunas); 

        for (int j = 0; j < colunas; ++j) {
            matrizModulo[i].emplace_back(matrizChar[i][j]);
        }
    }

    return matrizModulo;
}