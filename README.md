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
[linhas] [colunas]
[posX_fogo] [posY_fogo]
0 1 0 3  ...  # Matriz do terreno
...  
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

**Desenvolvido por William Leão** - 🌟
