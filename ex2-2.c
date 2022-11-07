#include <stdio.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} point_t;
typedef struct circle {
    point_t center;
    double radius;
} circle_t;

int _in_circle(point_t p, circle_t c) {
    double distance;
    distance = (p.x - c.center.x) * (p.x - c.center.x) + (p.y - c.center.y) * (p.y - c.center.y);
    if (distance <= c.radius * c.radius) return 1;
}

int main() {
    point_t p;
    p.x = 1;
    p.y = 1;
    circle_t c;
    c.center.x = 0;
    c.center.y = 0;
    c.radius = 2;
    printf("%d", _in_circle(p, c));
    return 0;
}