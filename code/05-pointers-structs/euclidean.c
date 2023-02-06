#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} ponto;

int euclidean(ponto p1, ponto p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx * dx) + sqrt(dy * dy);
}

int main() {
    ponto p1, p2;
    scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
    printf("Distância euclideana: %d", euclidean(p1, p2));
    return 0;
}