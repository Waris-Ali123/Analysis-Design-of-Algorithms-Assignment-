#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double euclideanDistance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point p1 = {2.0, 3.0};
    Point p2 = {5.0, 7.0};
    
    double distance = euclideanDistance(p1, p2);
    printf("Euclidean distance between (%.1f, %.1f) and (%.1f, %.1f) is %.2f\n",
           p1.x, p1.y, p2.x, p2.y, distance);
    
    return 0;
}
