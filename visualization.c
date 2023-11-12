#include <stdio.h>
#include "rectangle_control.h"

void displayRectangles(RectangleControl* rectangleControl) {
    // Definir o tamanho do plano
    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;

    // Criar uma matriz para representar o plano
    char grid[height][width];

    // Inicializar a matriz com espaços em branco
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = '-';
        }
    }

    // Preencher a matriz com os retângulos
    for (int i = 0; i < rectangleControl->count; i++) {
        Rectangle* rectangle = &rectangleControl->rectangles[i];

        for (int j = height - rectangle->y ; j > height - rectangle->y - rectangle->h ; j--) {
            for (int k = rectangle->x - 1; k < rectangle->x + rectangle->l - 1; k++) {
                grid[j][k] = 'x';
            }

        }

    }

        printf("\n");
    // Imprimir o plano com os retângulos
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
            printf("\n");

}
