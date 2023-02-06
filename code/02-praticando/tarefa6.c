// Configurações do mutirão. Não mexer.
#include "../macros_correcoes.h"
#define LABNUM "lab2-"
#define SOLUTIONFILE "tarefa6.c"

#include <stdio.h>

// TODO implemente sua função aqui
void fizzbuzz_while(int n) {
    printf("FizzBuzz com while: \n");
    int i = 1;
    while (i < n) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("por três e por cinco\n");
        } else if (i % 3 == 0) {
            printf("apenas por três\n");
        } else if (i % 5 == 0) {
            printf("apenas por cinco\n");
        } else {
            printf("nenhum\n");
        }
        i++;
    }
}

void fizzbuzz_for(int n) {
    printf("FizzBuzz com for: \n");
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("por três e por cinco\n");
        } else if (i % 3 == 0) {
            printf("apenas por três\n");
        } else if (i % 5 == 0) {
            printf("apenas por cinco\n");
        } else {
            printf("nenhum\n");
        }
    }
}

// TODO implemente aqui um programa que chama
// a função que você faz, passando como
// parâmetro um inteiro que foi dado pelo usuário
int main() {
    fizzbuzz_while(10);
    fizzbuzz_for(10);
    return 0;
}
