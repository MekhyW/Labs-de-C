// Configurações do mutirão. Não mexer.
#include "../macros_correcoes.h"
#define LABNUM "lab2-"
#define SOLUTIONFILE "tarefa2.c"

#include <stdio.h>

int main() {
    int s = 0;
    long i = 1;

    while (i <= 10) {
        s += i / 2;
        i++;
    }

    printf("soma das metades = %d", s);

    return 0;
}
