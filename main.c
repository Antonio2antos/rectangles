#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rectangle_control.h"
#include "visualization.h"


int main() {
    // Variáveis para armazenar os comandos
    char command[50]; 
    int x, y, l, h, p;

    // Inicializar a estrutura de controle dos retângulos
    RectangleControl rectangleControl = {malloc(MAX_RECTANGLES * sizeof(Rectangle)), 0};

    // Loop para ler os comandos do usuário
    while (1) {
        // Ler o comando do usuário
        scanf("%s", command);


        if(!strcmp(command, "create")){
            scanf("%d,%d+%d,%d", &x, &y, &l, &h);
            Rectangle rectangle = {x, y, l, h};
            addRectangle(&rectangleControl, rectangle);
        }else if(!strcmp(command, "moveleft")){
            scanf("%d,%d+%d", &x, &y, &p);
            moveRectangleLeft(&rectangleControl, x, y, p);
        }else if(!strcmp(command, "moveright")){
            scanf("%d,%d+%d", &x, &y, &p);
            moveRectangleRight(&rectangleControl, x, y, p);
        }else if(!strcmp(command, "exit")){
            printf("exiting\n");
            break;
        }else if(!strcmp(command, "print")){
            displayRectangles(&rectangleControl);
        }else{
            printf("Comando inválido!\n");
        }
        applyGravity(&rectangleControl);
        calculateInstability(&rectangleControl);
    }

    // Liberar a memória alocada pela estrutura de controle dos retângulos
    freeRectangleControl(&rectangleControl);

    return 0;
}