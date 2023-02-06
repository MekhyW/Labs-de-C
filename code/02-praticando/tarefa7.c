// Configurações do mutirão. Não mexer.
#include "../macros_correcoes.h"
#define LABNUM "lab2-"
#define SOLUTIONFILE "tarefa7.c"

#include <stdio.h>

// TODO implemente sua função aqui
void arvore(int n) {
    int i = 0;
    while (i < n) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("/");
        }
        printf("|");
        for (int j = 0; j < i; j++) {
            printf("\\");
        }
        printf("\n");
        i++;
    }
}

// TODO implemente aqui um programa que chama
// a função que você faz, passando como
// parâmetro um inteiro que foi dado pelo usuário
int main() {
    arvore(3);
    arvore(2);
    arvore(10);
    return 0;
}
