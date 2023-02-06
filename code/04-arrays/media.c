#include <stdio.h>

int avg(int *v, int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma / n;
}

int variance(int *v, int n) {
    int media = avg(v, n);
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += (v[i] - media) * (v[i] - media);
    }
    return soma / n;
}

int main() {
    int n;
    int vector[100];
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    printf("Digite os elementos do vetor: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }
    printf("Media: %d", avg(vector, n));
    printf("\nVariancia: %d", variance(vector, n));
    return 0;
}