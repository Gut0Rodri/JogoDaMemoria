# 🎮 Jogo da memória | C++

Um simples e divertido Jogo da Memória desenvolvido em C++, rodando diretamente no terminal.
O objetivo é encontrar todos os pares de cartas escondidas em um tabuleiro gerado aleatoriamente.

Este projeto foi feito utilizando apenas recursos básicos da linguagem, sendo ideal para quem está aprendendo lógica, condicionais, vetores/matrizes e manipulação de terminal.

## 📌 Funcionalidades

- Geração totalmente aleatória dos pares no tabuleiro

- Tabuleiro mostrado ao jogador usando caracteres ASCII

- Validação de coordenadas digitadas pelo usuário

- Temporizador ao errar (para “memorizar” antes das cartas esconderem novamente)

- Contador de pontuação

- Uso de Sleep(), cls e UTF-8 para melhor experiência no Windows

- Código limpo, modularizado e cheio de comentários

- Fácil de expandir para qualquer tamanho de tabuleiro

## 🖼️ Demonstração do Jogo

### Exemplo da execução:

```markdown
***************
JOGO DA MEMÓRIA
***************

Pontuação: 0

     0   1
  0  *   *
  1  *   *

Selecione a primeira carta, digite a linha e coluna:
```

### Ao encontrar um par:

```markdown
Parabéns, você encontrou 1 par(es) de cartas!
```

### Ao errar:

```markdown
Cartas diferentes, tente novamente!
Você tem 2 segundos para memorizar o tabuleiro!
```

## 📁 Estrutura do Projeto

```bash
 JogoMemoria
 ├── README.md
 └── main.cpp  # Código principal do jogo
```

## 🚀 Como Executar

### ✔ Requisitos

- Compilador C++ (GCC, MinGW, Clang, MSVC etc.)

- Windows (recomendado por causa do Sleep() e cls)

### ✔ Compilando com g++

```bash
g++ main.cpp -o jogo
```

### ✔ Executando

```bash
./jogo
```

## 🧩 Como o Jogo Funciona

- O programa cria dois tabuleiros:
    - Tabuleiro Gabarito → onde ficam as letras reais

    - Tabuleiro Secundário → o que o jogador vê (*)

- Cada par de letras (A, B, C…) é distribuído aleatoriamente

- O jogador revela duas cartas por vez:
    - ✔ Se forem iguais → ponto + permanecem viradas

    - ✘ Se forem diferentes → tempo de memorização + escondidas novamente

- O jogo termina quando todos os pares são encontrados

## 👨‍💻 Tecnologias Utilizadas

- C++ (padrão básico)

- stdlib.h — números aleatórios

- time.h — semente do rand

- windows.h — comandos de pausa e controle do console

- locale.h — acentuação UTF-8

- iomanip — formatação do tabuleiro

## 📜 Licença

Este projeto é totalmente livre para estudo e modificação. Se quiser usar como base para um projeto maior, fique à vontade!