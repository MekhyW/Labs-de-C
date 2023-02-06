#include <stdio.h>

void sum_sub(int a, int b, int *psum, int *psub) {
    *psum = a + b;
    *psub = a - b;
}

int main() {
    int a, b, sum, sub;
    scanf("%d %d", &a, &b);
    sum_sub(a, b, &sum, &sub);
    printf("sum = %d, sub = %d", sum, sub);
    return 0;
}