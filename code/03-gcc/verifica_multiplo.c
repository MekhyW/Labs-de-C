#include <stdio.h>

int verifica_multiplo(int primeiro, int segundo) {
    if (segundo == 0) {
        printf(" O segundo número não pode ser zero ! \n");
        return 0;
    }
    return primeiro % segundo == 0;
}

int main(int argc, char *argv[]) {
    int primeiro, segundo;
    while (primeiro != 0 || segundo != 0) {
        printf("Digite o primeiro : \n");
        scanf("%d", &primeiro);
        printf("Digite o segundo : \n");
        scanf("%d", &segundo);
        if (verifica_multiplo(primeiro, segundo) == 1) {
            printf(" %d é múltiplo de %d \n", primeiro, segundo);
        } else {
            printf(" %d não é múltiplo de %d \n", primeiro, segundo);
        }
    }
    return 0;
}
