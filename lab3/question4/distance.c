#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2);

int main(void) {
    double x_1;
    double y_1;
    double x_2;
    double y_2;
    double dis;
    int result;

    printf("Enter x1 y1 x2 y2: ");
    result = scanf("%lf %lf %lf %lf", &x_1, &y_1, &x_2, &y_2);

    if (result != 4) {
        printf("Error: please enter four valid numbers.\n");
        return 1;
    }

    dis = distance(x_1, y_1, x_2, y_2);

    printf("Point 1: (%.2f, %.2f)\n", x_1, y_1);
    printf("Point 2: (%.2f, %.2f)\n", x_2, y_2);
    printf("Distance: %.2f\n", dis);

    return 0;
}

double distance(double x_1, double y_1, double x_2, double y_2) {
    double xDifference = x_2 - x_1;
    double yDifference = y_2 - y_1;

    return sqrt((xDifference * xDifference) + (yDifference * yDifference));
}