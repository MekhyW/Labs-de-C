#include <stdio.h>

int main() {
    int col1[5];
    int col2[5];
    int col3[5];
    int col4[5];
    scanf("%d %d %d %d", &col1[0], &col2[0], &col3[0], &col4[0]);
    scanf("%d %d %d %d", &col1[1], &col2[1], &col3[1], &col4[1]);
    scanf("%d %d %d %d", &col1[2], &col2[2], &col3[2], &col4[2]);
    scanf("%d %d %d %d", &col1[3], &col2[3], &col3[3], &col4[3]);
    scanf("%d %d %d %d", &col1[4], &col2[4], &col3[4], &col4[4]);
    int soma1 = col1[0] + col1[1] + col1[2] + col1[3] + col1[4];
    int soma2 = col2[0] + col2[1] + col2[2] + col2[3] + col2[4];
    int soma3 = col3[0] + col3[1] + col3[2] + col3[3] + col3[4];
    int soma4 = col4[0] + col4[1] + col4[2] + col4[3] + col4[4];
    printf("Resultados: %d %d %d %d\n", soma1, soma2, soma3, soma4);
    if (soma1 > soma2 && soma1 > soma3 && soma1 > soma4)
        printf("Primeira coluna é a maior");
    else if (soma2 > soma1 && soma2 > soma3 && soma2 > soma4)
        printf("Segunda coluna é a maior");
    else if (soma3 > soma1 && soma3 > soma2 && soma3 > soma4)
        printf("Terceira coluna é a maior");
    else if (soma4 > soma1 && soma4 > soma2 && soma4 > soma3)
        printf("Quarta coluna é a maior");
    else
        printf("Nenhuma coluna é a maior");
    return 0;
}