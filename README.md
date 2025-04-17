# **🌿🔥 Simulador de Fuga Animal em Incêndio Florestal**  

*Um simulador que modela o comportamento de um animal tentando escapar de um incêndio florestal em um ambiente dinâmico.*  

---

## **📌 Visão Geral**  
Este projeto simula a fuga de um animal em um cenário de incêndio florestal, utilizando:  
✔ **Matrizes** para representar o terreno, fogo e caminhos percorridos.  
✔ **Algoritmo de prioridade** para decisões de movimento.  
✔ **Mecânica de propagação de fogo** com diferentes direções de vento.  
✔ **Registro em arquivo** para análise detalhada.  

---

## **🚀 Funcionalidades**  
### **1. Sistema de Movimentação do Animal**  
- Prioriza rotas seguras (água > terra > vegetação).  
- Pausa por 2 iterações ao encontrar água, regenerando o ambiente.  
- Marca caminhos percorridos (`8`).  

### **2. Propagação Dinâmica do Fogo**  
- **5 modos de vento** (sem vento, cima, baixo, esquerda, direita).  
- **Segunda chance**: Se o fogo chegar perto, o animal tenta uma rota alternativa.  
- Árvores queimadas (`3`) não pegam fogo novamente.  

### **3. Controle por Arquivo**  
- Entrada: Define terreno, posição inicial do fogo e animal.  
- Saída: Gera relatório completo de cada iteração.  

---

## **🛠️ Como Usar**  

### **Pré-requisitos**  
- Compilador C++11 (ex: `g++`).  

### **Compilação e Execução**  
```bash
# Compilar
g++ -std=c++11 main.cpp Animal.cpp Fogo.cpp LeitorArquivos.cpp Config.cpp -o simulador

# Executar
./simulador
```

### **Arquivos**  
- **`entrada.txt`**: Configuração inicial (formato abaixo).  
- **`saida.txt`**: Resultados da simulação (gerado automaticamente).  

#### **Formato do `entrada.txt`**  
```plaintext
[linhas] [colunas] [posX_fogo] [posY_fogo]
1 1 1 1 4
1 2 1 1 1
2 1 1 1 4
0 2 1 1 1
1 1 1 0 4
# Matriz do terreno
```
**Legenda**:  
- `0`: Terra  
- `1`: Vegetação  
- `2`: Fogo  
- `3`: Árvore queimada  
- `4`: Água  
- `5`: Animal  

---

## **📂 Estrutura do Código**  
```plaintext
.
├── main.cpp                  # Loop principal da simulação
├── Animal.hpp/cpp            # Lógica do animal
├── Fogo.hpp/cpp              # Propagação do incêndio
├── LeitorArquivos.hpp/cpp    # Leitura/escrita de arquivos
├── Config.hpp/cpp            # Parâmetros (ventos, iterações)
├── entrada.txt               # Exemplo de configuração
└── saida.txt                 # Saída gerada
```

---

## **🎯 Exemplo de Saída**  
```plaintext
Iteração número 5:
0 1 5 3 4 ...
1 2 0 8 1 ...
Passos: 12
Encontrou agua: 2
Animal cercado.  # Se aplicável
```

--- 
# **Classe Animal**  

[![Licença](https://img.shields.io/badge/license-MIT-blue)](LICENSE)  
*Responsável pelo comportamento de fuga do animal em um incêndio florestal, implementando lógica de movimentação inteligente baseada em prioridades de terreno.*  

---

## **📌 Visão Geral**  
A classe `Animal` controla a movimentação de um agente em uma matriz de ambiente, priorizando:  
- **Fuga eficiente** de incêndios  
- **Busca por recursos** (água)  
- **Evitação de obstáculos** (fogo, terrenos perigosos)  

---

## **🔧 Funcionalidades**  
### **1. Sistema de Prioridades**  
| Valor | Terreno       | Prioridade | Comportamento                          |  
|-------|---------------|------------|----------------------------------------|  
| `4`   | Água          | 5 (Máxima) | Pausa simulação e regenera ambiente    |  
| `0`   | Terra         | 4          | Movimento seguro                       |  
| `1`   | Vegetação     | 3          | Inflamável (risco médio)               |  
| `3`   | Árvore queimada| 2         | Segura, mas baixa prioridade           |  
| `8`   | Caminho       | 1          | Já percorrido (evita loops)            |  

### **2. Mecânicas Especiais**  
- **Florescimento**: Ao encontrar água (`4`), transforma adjacências em terra segura (`0`).  
- **Segunda chance**: Se o fogo atingir células vizinhas, ativa modo de emergência.  
- **Detecção de cerco**: Verifica se está totalmente bloqueado pelo fogo.  

---

## **📦 Métodos Públicos**  

### **Controle de Movimento**  
| Método | Parâmetros | Retorno | Descrição |  
|--------|------------|---------|-----------|  
| `Fugir()` | `matriz`, `matrizRastro` | `void` | Algoritmo principal de busca de caminho |  
| `estaCercado()` | `matrizRastro` | `bool` | Verifica se há rotas de fuga |  

### **Gerenciamento de Estado**  
| Método | Descrição |  
|--------|-----------|  
| `getContaPassos()` | Retorna total de movimentos |  
| `getContaAgua()` | Conta quantas vezes encontrou água |  
| `setSegundaChance()` | Ativa/desativa modo emergência |  

### **Utilitários**  
```cpp  
void imprimirMatriz(vector<vector<int>>& matriz);  // Debug visual  
bool ehPosicaoSegura(int valor);                  // Checa segurança  
int obterPrioridade(int valor);                   // Define prioridades  
```

---

## **🛠️ Uso Básico**  
```cpp  
#include "Animal.hpp"  

// 1. Inicialização  
vector<vector<int>> mapa = {{0,1,4}, {2,0,1}};  
Animal animal(mapa);  

// 2. Execução  
vector<vector<int>> rastro = mapa;  
animal.Fugir(mapa, rastro);  

// 3. Consulta resultados  
cout << "Passos: " << animal.getContaPassos();  
```

---

## **⚙️ Fluxo Interno**  
1. **Inicialização**:  
   - Localiza posição inicial (`5`) na matriz.  
   - Configura contadores (passos, água).  

2. **Ciclo de Movimento**:  
   - Usa **fila de prioridade** para explorar células vizinhas.  
   - Atualiza matriz com caminho percorrido (`8`).  

3. **Eventos**:  
   - Encontro com água → Pausa 2 iterações + florescimento.  
   - Fogo adjacente → Ativa `segundaChance`.  

---

## **📊 Exemplo de Saída**  
```plaintext  
Matriz Atual:  
0 1 5  
2 8 4  
Passos: 3 | Água: 1  
```  

---

## **📌 Observações**  
- **Eficiência**: Algoritmo ótimo para matrizes até 100x100.  
- **Extensibilidade**: Adicione novos terrenos modificando `obterPrioridade()`.  

---

**🔗 Relacionados**: [Fogo](Fogo.md) | [LeitorArquivos](Leitor.md)  

--- 

**Licença MIT** | [Contribuições](CONTRIBUTING.md) são bem-vindas!

**Desenvolvido por William Leão** - 🌟
