#include <stdio.h>
#include <stdlib.h>
#include "rectangle_control.h"

void freeRectangleControl(RectangleControl* rectangleControl) {
    free(rectangleControl->rectangles);
}

void addRectangle(RectangleControl* rectangleControl, Rectangle rectangle) {
    int validPos = validPosition(rectangle);
    int intersection = checkIntersection(rectangleControl, &rectangle);

    if (rectangleControl->count < MAX_RECTANGLES && validPos && intersection) {
        rectangleControl->rectangles[rectangleControl->count++] = rectangle;
    } else if(rectangleControl->count > MAX_RECTANGLES){
        printf("Impossivel adicionar retangulo:\nLimite máximo de retângulos atingido!\n");
    }else if(!intersection){
        printf("Impossivel adicionar retangulo:\nIntersecao de retangulos!\n");
    }else{
        printf("Impossivel adicionar retangulo:\nCoordenadas invalidas!\n");
    }
}

int checkIntersection(RectangleControl* rectangleControl, Rectangle* rectangle) {
    for(int i = 0; i < rectangleControl->count; i++){
        Rectangle* r = &rectangleControl->rectangles[i];
        if(r->x < rectangle->x + rectangle->l && r->x + r->l > rectangle->x && r->y < rectangle->y + rectangle->h && r->y + r->h > rectangle->y && r != rectangle){
            return 0;
        }
    }
    return 1;
}

int validPosition(Rectangle rectangle) {
    if(rectangle.x < 1 || rectangle.x + rectangle.l - 1 > MAX_WIDTH || rectangle.y < 1 || rectangle.y + rectangle.h - 1 > MAX_HEIGHT  || rectangle.l < 1 || rectangle.h < 1){
        return 0;
    }
    return 1;
}


void applyGravity(RectangleControl* rectangleControl) {
    for (int i = 0; i < rectangleControl->count; i++) {
        Rectangle* rectangle = &rectangleControl->rectangles[i];
         while (checkIntersection(rectangleControl, rectangle) && rectangle->y > 0){
            rectangle->y--;
        }
        rectangle->y++;
    }
}

int findRectangleIndex(RectangleControl* rectangleControl, int x, int y) {
    for(int i = 0; i < rectangleControl->count; i++){
        Rectangle* r = &rectangleControl->rectangles[i];
        if(r->x == x && r->y == y){
            return i;
        }
    }
    return -1;
}

void moveRectangleRight(RectangleControl* rectangleControl, int x, int y, int p) {
    int index = findRectangleIndex(rectangleControl, x, y);
    if(index == -1){
        printf("Nao existe retangulo nessa posicao!\n");
        return;
    }
    Rectangle* rectangle = rectangleControl->rectangles + index;
    int lastX = rectangle->x;
        for (int i = 0; i < p; i++)
    {
        rectangle->x += 1;
        if(!validPosition(*rectangle) || !checkIntersection(rectangleControl, rectangle)){
            rectangle->x = lastX;
            printf("Impossivel mover o retangulo para a direita!\n");
            return;
        }
    }
}

void moveRectangleLeft(RectangleControl* rectangleControl, int x, int y, int p) {
    int index = findRectangleIndex(rectangleControl, x, y);
    if(index == -1){
        printf("Nao existe retangulo nessa posicao!\n");
        return;
    }
    Rectangle* rectangle = rectangleControl->rectangles + index;
    int lastX = rectangle->x;
    for (int i = 0; i < p; i++)
    {
        rectangle->x -= 1;
        if(!validPosition(*rectangle) || !checkIntersection(rectangleControl, rectangle)){
            rectangle->x = lastX;
            printf("Impossivel mover o retangulo para a esquerda!\n");
            return;
        }
    }

}


void calculateInstability(RectangleControl* rectangleControl) {
    float instability = 0;
    int n_instable = 0;
    for (int i = 0; i < rectangleControl->count; i++){
        Rectangle* rectangle = &rectangleControl->rectangles[i];
        int supported = 0;
        if(rectangle->y > 1){
            for (int j = 0; j < rectangleControl->count; j++){
                Rectangle* support = &rectangleControl->rectangles[j];
                if (support->y + support->h == rectangle->y){
                    if(rectangle->x >= support->x && rectangle->x <= support->x + support->l - 1){
                        supported += support->x + support->l - rectangle->x;
                    }
                    else if(rectangle->x+rectangle->l-1 >= support->x && rectangle->x+rectangle->l-1 <= support->x + support->l - 1){
                        supported += rectangle->x+rectangle->l - support->x;
                    }
                }
            }
                if(supported <= rectangle->l/2){
                    instability += ((float)rectangle->l - supported)/rectangle->l*100;
                    n_instable++;
                }
            }
        }
        if(n_instable > 0){
            n_instable = 1;
        }
        if(instability/n_instable >= 70)
            printf("O sistema exibe um grau de instabilidade de %.2f%%\n", instability/n_instable);
    }