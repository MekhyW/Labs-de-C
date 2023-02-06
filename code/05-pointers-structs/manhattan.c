#include <stdio.h>

typedef struct {
    int x;
    int y;
} ponto;

int manhattan(ponto p1, ponto p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    return dx + dy;
}

int main() {
    ponto p1, p2;
    scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
    printf("Distância manhattan: %d", manhattan(p1, p2));
    return 0;
}