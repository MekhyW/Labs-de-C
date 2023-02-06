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

void limiar(imagem *img, imagem *limiar, int threshold) {
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

void crop(imagem *img, imagem *crop) {
    int i, j;
    int x, y;
    int w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    crop->largura = w;
    crop->altura = h;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            crop->matrix[i][j] = img->matrix[i + y][j + x];
        }
    }
}

void blur(imagem *img, imagem *blur) {
    int i, j;
    int x, y;
    int w, h;
    int sum;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    blur->largura = w;
    blur->altura = h;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            sum = 0;
            sum += img->matrix[i + y - 1][j + x - 1];
            sum += img->matrix[i + y - 1][j + x];
            sum += img->matrix[i + y - 1][j + x + 1];
            sum += img->matrix[i + y][j + x - 1];
            sum += img->matrix[i + y][j + x];
            sum += img->matrix[i + y][j + x + 1];
            sum += img->matrix[i + y + 1][j + x - 1];
            sum += img->matrix[i + y + 1][j + x];
            sum += img->matrix[i + y + 1][j + x + 1];
            blur->matrix[i][j] = sum / 9;
        }
    }
}

void edge_detection(imagem *img, imagem *edge) {
    int i, j;
    int x, y;
    int w, h;
    int sum;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    edge->largura = w;
    edge->altura = h;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            sum = 0;
            sum += img->matrix[i + y - 1][j + x - 1] * -1;
            sum += img->matrix[i + y - 1][j + x] * -1;
            sum += img->matrix[i + y - 1][j + x + 1] * -1;
            sum += img->matrix[i + y][j + x - 1] * -1;
            sum += img->matrix[i + y][j + x] * 8;
            sum += img->matrix[i + y][j + x + 1] * -1;
            sum += img->matrix[i + y + 1][j + x - 1] * -1;
            sum += img->matrix[i + y + 1][j + x] * -1;
            sum += img->matrix[i + y + 1][j + x + 1] * -1;
            edge->matrix[i][j] = sum;
        }
    }
}

int main() {
    imagem img, limiar, crop, blur, edge;
    int threshold = 128;
    le_imagem(&img);
    //limiar(&img, &limiar, threshold);
    //crop(&img, &crop);
    //blur(&img, &blur);
    edge_detection(&img, &edge);
    //escreve_imagem(&limiar);
    //escreve_imagem(&crop);
    //escreve_imagem(&blur);
    escreve_imagem(&edge);
    return 0;
}