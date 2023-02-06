#include <stdio.h>

int area(int largura, int altura) {
    return largura * altura;
}

int perimetro(int largura, int altura) {
    return 2 * (largura + altura);
}

int main() {
    int largura, altura;
    scanf("%d %d", &largura, &altura);
    printf("area = %d, perimetro = %d", area(largura, altura), perimetro(largura, altura));
    return 0;
}