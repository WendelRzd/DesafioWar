#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes globais ---
#define MAX_TERRITORIOS 5
#define TAM_STRING 100

// --- Estrutura ---
struct Territorio {
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
};

// --- Função para limpar o buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função principal ---
int main() {
    struct Territorio mundo[MAX_TERRITORIOS];

    printf("===========================================\n");
    printf("Vamos cadastrar os %d territorios iniciais do nosso mundo.\n\n", MAX_TERRITORIOS);

    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("--- Cadastrando Territorio %d ---\n", i + 1);

        printf("Nome do Territorio: ");
        fgets(mundo[i].nome, TAM_STRING, stdin);
        mundo[i].nome[strcspn(mundo[i].nome, "\n")] = '\0';  // remove o '\n'

        printf("Cor do Exercicio (ex: Azul, Verde): ");
        fgets(mundo[i].cor, TAM_STRING, stdin);
        mundo[i].cor[strcspn(mundo[i].cor, "\n")] = '\0';

        printf("Numero de Tropas: ");
        scanf("%d", &mundo[i].tropas);
        limparBufferEntrada(); // limpa o \n deixado pelo scanf

        printf("\n");
    }

    // Exibe o resultado final
    printf("===========================================\n");
    printf("Territorios cadastrados:\n\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s\n", mundo[i].nome);
        printf("Cor: %s\n", mundo[i].cor);
        printf("Tropas: %d\n", mundo[i].tropas);
        printf("-------------------------------------------\n");
    }

    return 0;
}
