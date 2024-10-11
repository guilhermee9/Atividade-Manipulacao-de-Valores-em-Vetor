/*
Título: Manipulação de Valores em Vetor
Autor: Profe. Berssa
Data: 2024.10.11
*/




#include <iostream>  // Biblioteca padrão para operações de entrada e saída
#include <algorithm>  // Biblioteca para funções como sort()
#include <cstdlib>    // Biblioteca para geração de números aleatórios (rand)
#include <ctime>      // Biblioteca para inicializar a semente do gerador de números aleatórios
#include <string>     // Biblioteca para usar funções como to_string
#include <limits>     // Biblioteca para usar numeric_limits

using namespace std;  // Namespace padrão para evitar o uso de std:: antes dos comandos

// Função para aguardar que o usuário pressione Enter
void esperarEnter() {
    cout << "\nPressione Enter para continuar...";
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpa o buffer de entrada - NO CASO DE DAR ERRO DURANTE A EXECUSSÃO DESCOMENTE ESSA LINHA
    cin.get();  // Aguarda o usuário pressionar Enter
}

// Função para limpar o buffer e resetar o estado do `cin`
void limparBuffer() {
    cin.clear();  // Limpa o estado de erro
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora entradas inválidas no buffer
}

// Função genérica para exibir mensagens de erro
void exibirMensagemErro(const string &mensagem) {
    cout << mensagem << endl;
}

// Função para ler um número inteiro válido
int lerEntradaValida(const string &mensagem) {
    int numero;
    while (true) {
        cout << mensagem;
        cin >> numero;
        if (cin.fail()) {
            limparBuffer();  // Limpa o estado de erro e o buffer
            exibirMensagemErro("Entrada inválida! Por favor, insira um número inteiro.");
        } else {
            limparBuffer();  // Limpa o buffer após a entrada válida
            return numero;
        }
    }
}

// Função para zerar o vetor
void zerarVetor(int vetor[], int tamanho) {
    fill(vetor, vetor + tamanho, 0);  // Usa a função fill para preencher o vetor com 0
    cout << "Vetor zerado!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para mostrar o vetor
void mostrarVetor(int vetor[], int tamanho) {
    cout << "Conteúdo do vetor:\n";
    for (int i = 0; i < tamanho; i++) {
        cout << "Posição [" << i << "]: " << vetor[i] << endl;  // Exibe o índice e o valor do vetor
    }
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para preencher o vetor com valores fornecidos pelo usuário
void preencherVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = lerEntradaValida("Digite um valor inteiro para a posição [" + to_string(i) + "]: ");
    }
    cout << "Vetor preenchido manualmente!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para preencher o vetor com valores aleatórios dentro de um intervalo fornecido pelo usuário
void preencherVetorAleatorio(int vetor[], int tamanho) {
    int minValor = lerEntradaValida("Digite o valor mínimo para o intervalo de valores aleatórios: ");
    int maxValor;

    while (true) {
        maxValor = lerEntradaValida("Digite o valor máximo para o intervalo de valores aleatórios: ");
        if (maxValor > minValor) break;  // Verifica se o valor máximo é maior que o mínimo
        exibirMensagemErro("Entrada inválida! O valor máximo deve ser maior que o valor mínimo.");
    }

    // Preenche o vetor com valores aleatórios no intervalo
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = minValor + rand() % (maxValor - minValor + 1);
    }

    cout << "Vetor preenchido com valores aleatórios!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para editar o valor de uma posição específica do vetor
void editarVetor(int vetor[], int tamanho) {
    int posicao = lerEntradaValida("Digite a posição que deseja editar (0 a " + to_string(tamanho - 1) + "): ");

    // Garante que a posição esteja dentro dos limites do vetor
    while (posicao < 0 || posicao >= tamanho) {
        exibirMensagemErro("Posição inválida! Tente novamente.");
        posicao = lerEntradaValida("Digite uma posição válida: ");
    }

    int valor = lerEntradaValida("Digite o novo valor para a posição [" + to_string(posicao) + "]: ");
    vetor[posicao] = valor;  // Atualiza o valor na posição escolhida
    cout << "Valor alterado com sucesso!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para verificar se um valor está presente no vetor
void verificarValor(int vetor[], int tamanho) {
    int valor = lerEntradaValida("Digite o valor que deseja verificar: ");
    bool encontrado = false;

    // Verifica se o valor está no vetor
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            cout << "Valor " << valor << " encontrado na posição [" << i << "]" << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Valor " << valor << " não encontrado no vetor." << endl;
    }

    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para ordenar o vetor
void ordenarVetor(int vetor[], int tamanho) {
    sort(vetor, vetor + tamanho);  // Usa a função sort() para ordenar o vetor
    cout << "Vetor ordenado com sucesso!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função que exibe o menu e retorna a escolha do usuário
int menu() {
    cout << "\nEscolha uma opção:\n";
    cout << "1 - Mostrar vetor\n";
    cout << "2 - Zerar vetor\n";
    cout << "3 - Preencher vetor manualmente\n";
    cout << "4 - Preencher vetor com valores aleatórios\n";
    cout << "5 - Editar valor do vetor\n";
    cout << "6 - Verificar valor no vetor\n";
    cout << "7 - Ordenar vetor\n";
    cout << "0 - Sair\n";
    return lerEntradaValida("Opção: ");
}

int main() {
    srand(time(0));  // Inicializa o gerador de números aleatórios

    const int TAMANHO = 10;  // Define o tamanho do vetor
    int vetor[TAMANHO];      // Declara o vetor de inteiros

    int opcao;

    do {
        opcao = menu();  // Mostra o menu e lê a opção do usuário

        switch (opcao) {
            case 1:
                mostrarVetor(vetor, TAMANHO);
                break;
            case 2:
                zerarVetor(vetor, TAMANHO);
                break;
            case 3:
                preencherVetor(vetor, TAMANHO);
                break;
            case 4:
                preencherVetorAleatorio(vetor, TAMANHO);
                break;
            case 5:
                editarVetor(vetor, TAMANHO);
                break;
            case 6:
                verificarValor(vetor, TAMANHO);
                break;
            case 7:
                ordenarVetor(vetor, TAMANHO);
                break;
            case 0:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                exibirMensagemErro("Opção inválida! Escolha uma opção válida.");
                break;
        }
    } while (opcao != 0);  // O programa continua executando até que o usuário escolha sair

    return 0;
}