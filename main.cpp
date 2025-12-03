// Biblioteca padrão de entrada/saída
#include <iostream>
// Biblioteca para formatar saída (ex: setw)
#include <iomanip>
// Biblioteca para funções aleatórias (rand, srand)
#include <stdlib.h>
// Biblioteca para manipular tempo (time)
#include <time.h>
// Biblioteca para Sleep() - apenas Windows
#include <windows.h>
// Biblioteca para usar acentuação corretamente
#include <locale.h>

using namespace std;

// Define o tamanho do tabuleiro
const int linha = 13, coluna = 13;

// Variáveis globais do jogo
int pares = (linha * coluna) / 2; // quantidade de pares
int delayTime = 2;                // tempo para memorizar cartas erradas
int linhaAleatoria, colunaAleatoria;
int pontuacao = 0;
int x1, y1, x2, y2;

// Tabuleiro real (com letras) e tabuleiro mostrado ao jogador
char TabuleiroGabarito[linha][coluna];
char TabuleiroSecundario[linha][coluna];
// Primeira letra usada para formar pares
char letra = 65; // 'A'

// ---------------------------
// Inicializa tabuleiros
// ---------------------------
void inicializarTabuleiros()
{
    // Semeia o gerador de números aleatórios
    srand(time(NULL));

    // Preenche o tabuleiro gabarito com '0'
    // e o tabuleiro mostrado ao jogador com '*'
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            TabuleiroGabarito[i][j] = '0';
            TabuleiroSecundario[i][j] = '*';
        }
    }

    // Distribui aleatoriamente os pares de letras no tabuleiro gabarito
    while (pares > 0)
    {
        // Cada letra aparece duas vezes
        for (int i = 0; i < 2; i++)
        {
            // Escolhe posição aleatória até achar uma vaga
            do
            {
                linhaAleatoria = rand() % linha;
                colunaAleatoria = rand() % coluna;
            } while (TabuleiroGabarito[linhaAleatoria][colunaAleatoria] != '0');

            // Coloca a letra na posição aleatória
            TabuleiroGabarito[linhaAleatoria][colunaAleatoria] = letra;
        }

        // Próxima letra (A -> B -> C…)
        letra++;

        // Diminui o contador de pares restantes
        pares--;
    }

    // Restaura o valor original de "pares"
    pares = (linha * coluna) / 2;
}

// ---------------------------
// Imprime o tabuleiro ao jogador
// ---------------------------
void imprimirTabela()
{
    // Cabeçalho das colunas
    cout << "  ";
    for (int i = 0; i < coluna; i++)
    {
        cout << setw(4) << i;
    }
    cout << endl;

    // Linhas e conteúdo do tabuleiro
    for (int i = 0; i < linha; i++)
    {
        cout << setw(2) << right << i;
        for (int j = 0; j < coluna; j++)
        {
            cout << setw(4) << TabuleiroSecundario[i][j];
        }
        cout << endl;
    }
}

// ---------------------------
// Verifica se coordenada é válida
// ---------------------------
bool validarEntrada(int x, int y)
{
    // Fora dos limites ou carta já revelada
    if (x < 0 || x > (linha - 1) || y < 0 || y > (coluna - 1) || TabuleiroSecundario[x][y] != '*')
    {
        cout << "Coordenadas inválidas ou carta já revelada! Tente novamente" << endl;
        return false;
    }
    return true;
}

// ---------------------------
// Compara as cartas escolhidas
// ---------------------------
bool verificarCartas(char carta1, char carta2)
{
    // Se forem diferentes
    if (carta1 != carta2)
    {
        cout << endl
             << "Cartas diferentes, tente novamente!" << endl;

        // Tempo para memorizar
        while (delayTime >= 0)
        {
            Sleep(1000);
            cout << "\rVocê tem " << delayTime << " segundos para memorizar o tabuleiro!";
            cout.flush();
            delayTime--;
        }

        system("cls"); // limpa tela
        delayTime = 2; // reseta o tempo
        return false;
    }
    else // Se forem iguais
    {
        pontuacao++;
        cout << endl
             << "Parabéns, você encontrou " << pontuacao << " par(es) de cartas" << endl;
        Sleep(2500);
        system("cls");
        return true;
    }
}

// ---------------------------
// Função principal do jogo
// ---------------------------
void jogo()
{
    // Continua até encontrar todos os pares
    while (pontuacao < pares)
    {
        cout << endl
             << "Pontuação: " << pontuacao << endl
             << endl;

        imprimirTabela();

        // Primeira carta
        do
        {
            cout << endl
                 << "Selecione a primeira carta, digite a linha e coluna: ";
            cin >> x1 >> y1;
            cout << endl;
        } while (!validarEntrada(x1, y1));

        // Revela carta
        TabuleiroSecundario[x1][y1] = TabuleiroGabarito[x1][y1];

        imprimirTabela();

        // Segunda carta
        do
        {
            cout << endl
                 << "Selecione a segunda carta, digite a linha e coluna: ";
            cin >> x2 >> y2;
            cout << endl;
        } while (!validarEntrada(x2, y2));

        // Revela carta
        TabuleiroSecundario[x2][y2] = TabuleiroGabarito[x2][y2];

        imprimirTabela();

        // Compara cartas
        if (!verificarCartas(TabuleiroSecundario[x1][y1], TabuleiroSecundario[x2][y2]))
        {
            // Se errar, esconde de novo
            TabuleiroSecundario[x1][y1] = '*';
            TabuleiroSecundario[x2][y2] = '*';
        }
    }

    cout << endl
         << "Parabéns, você encontrou todos os pares!" << endl;
}

// ---------------------------
// Função main
// ---------------------------
int main()
{
    // Permite mostrar caracteres UTF-8 no terminal Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    setlocale(LC_ALL, "pt_BR.UTF-8");

    cout << "***************" << endl;
    cout << "JOGO DA MEMÓRIA" << endl;
    cout << "***************" << endl;

    inicializarTabuleiros(); // Prepara o jogo
    jogo();                 // Inicia o jogo

    return 0;
}
