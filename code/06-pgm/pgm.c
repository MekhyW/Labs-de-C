#include <stdio.h>
#include <math.h>

typedef struct {
    int largura;
    int altura;
    int matrix[640][480];
} imagem;

void le_imagem(imagem *img) {
    int i, j;
    scanf("%*s"); // P2
    scanf("%d %d", &img->largura, &img->altura);
    scanf("%*d"); // max value = 255
    for (i = 0; i < img->altura; i++) {
        for (j = 0; j < img->largura; j++) {
            scanf("%d", &img->matrix[i][j]);
        }
    }
}

void escreve_imagem(imagem *img) {
    int i, j;
    printf("P2\n");
    printf("%d %d\n", img->largura, img->altura);
    printf("255\n");
    for (i = 0; i < img->altura; i++) {
        for (j = 0; j < img->largura; j++) {
            printf("%d ", img->matrix[i][j]);
        }
    }
}

void effect_limiar(imagem *img, imagem *limiar, int threshold) {
    limiar->largura = img->largura;
    limiar->altura = img->altura;
    for (int i = 0; i < img->altura; i++) {
        for (int j = 0; j < img->largura; j++) {
            if (img->matrix[i][j] >= threshold) {
                limiar->matrix[i][j] = 255;
            } else {
                limiar->matrix[i][j] = 0;
            }
        }
    }
}

void effect_crop(imagem *img, imagem *crop, int w, int h) {
    crop->largura = w;
    crop->altura = h;
    for (int i = 0; i < img->altura; i++) {
        for (int j = 0; j < img->largura; j++) {
            if (i < h && j < w) {
                crop->matrix[i][j] = img->matrix[i][j];
            } else {
                crop->matrix[i][j] = 0;
            }
        }
    }
}

void effect_blur(imagem *img, imagem *blur) {
    blur->largura = img->largura;
    blur->altura = img->altura;
    int sum, denominator;
    for (int i = 0; i < img->altura; i++) {
        for (int j = 0; j < img->largura; j++) {
            sum = 0;
            denominator = 0;
            if (i > 0 && j > 0) {
                sum += img->matrix[i - 1][j - 1];
                denominator++;
            }
            if (i > 0) {
                sum += img->matrix[i - 1][j];
                denominator++;
            }
            if (i > 0 && j < img->largura - 1) {
                sum += img->matrix[i - 1][j + 1];
                denominator++;
            }
            if (j > 0) {
                sum += img->matrix[i][j - 1];
                denominator++;
            }
            sum += img->matrix[i][j];
            denominator++;
            blur->matrix[i][j] = sum / denominator;
        }
    }
}

void effect_edge_detection(imagem *img, imagem *edge) {
    edge->largura = img->largura;
    edge->altura = img->altura;
    int sum, denominator;
    for (int i = 0; i < img->altura; i++) {
        for (int j = 0; j < img->largura; j++) {
            sum = 0;
            denominator = 0;
            if (i > 0 && j > 0) {
                sum += img->matrix[i - 1][j - 1];
                denominator++;
            }
            if (i > 0) {
                sum += img->matrix[i - 1][j];
                denominator++;
            }
            if (i > 0 && j < img->largura - 1) {
                sum += img->matrix[i - 1][j + 1];
                denominator++;
            }
            if (j > 0) {
                sum += img->matrix[i][j - 1];
                denominator++;
            }
            if (j < img->largura - 1) {
                sum += img->matrix[i][j + 1];
                denominator++;
            }
            if (i < img->altura - 1 && j > 0) {
                sum += img->matrix[i + 1][j - 1];
                denominator++;
            }
            if (i < img->altura - 1) {
                sum += img->matrix[i + 1][j];
                denominator++;
            }
            if (i < img->altura - 1 && j < img->largura - 1) {
                sum += img->matrix[i + 1][j + 1];
                denominator++;
            }
            edge->matrix[i][j] = abs(img->matrix[i][j] - sum / denominator);
        }
    }
}

int main() {
    imagem img, limiar, crop, blur, edge;
    le_imagem(&img);
    //effect_limiar(&img, &limiar, 128);
    //effect_crop(&img, &crop, 50, 50);
    //effect_blur(&img, &blur);
    effect_edge_detection(&img, &edge);
    //escreve_imagem(&img);
    //escreve_imagem(&limiar);
    //escreve_imagem(&crop);
    //escreve_imagem(&blur);
    escreve_imagem(&edge);
    return 0;
}