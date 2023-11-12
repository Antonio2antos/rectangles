#ifndef RECTANGLE_CONTROL_H
#define RECTANGLE_CONTROL_H

#define MAX_HEIGHT 25
#define MAX_WIDTH 80
#define MAX_RECTANGLES MAX_HEIGHT * MAX_WIDTH

typedef struct {
    int x;  // coordenada x do canto inferior esquerdo
    int y;  // coordenada y do canto inferior esquerdo
    int l;  // comprimento
    int h;  // altura
} Rectangle;

typedef struct {
    Rectangle* rectangles;  // vetor de retângulos
    int count;              // contador de retângulos
} RectangleControl;

void addRectangle(RectangleControl* rectangleControl, Rectangle rectangle);
int checkIntersection(RectangleControl* rectangleControl, Rectangle* rectangle);
int validPosition(Rectangle rectangle);
void applyGravity(RectangleControl* rectangleControl);
void freeRectangleControl(RectangleControl* rectangleControl);
int findRectangleIndex(RectangleControl* rectangleControl, int x, int y);


void moveRectangleRight(RectangleControl* rectangleControl, int x, int y, int p);
void moveRectangleLeft(RectangleControl* rectangleControl, int x, int y, int p);
void displayRectangles(RectangleControl* rectangleControl);
void calculateInstability(RectangleControl* rectangleControl);

#endif  // RECTANGLE_CONTROL_H