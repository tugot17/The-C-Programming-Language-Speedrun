// simillar to make_a_point.c but with typedef
#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;

Point addpoints(Point p1, Point p2)
{
    p1.x += p2.x;
    p1.y = p2.y;
    return p1;
};

Point make_a_point(int x, int y)
{
    Point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int main(int argc, char const *argv[])
{
    Point p0 = make_a_point(5, 16);
    Point p1 = {.x = 10, .y = 20};
    Point p2 = (Point){30, 40};
    Point p3 = addpoints(p1, p2);

    Point *pp0, *pp1; // pointer to a Point
    pp0 = &p0;
    pp1 = &p1;

    printf("Point 0: (%d, %d)\n", p0.x, p0.y);
    printf("Point 1: (%d, %d)\n", p1.x, p1.y);
    printf("Point 2: (%d, %d)\n", p2.x, p2.y);
    printf("Point 3 (p1 + p2): (%d, %d)\n", p3.x, p3.y);
    printf("Point 1: not changed since we sent a copy(%d, %d)\n", p1.x, p1.y);
    printf("Point 0 using a pointer: (%d, %d)\n", (*pp0).x, (*pp0).y);
    printf("Point 1 using a pointer: (%d, %d)\n", pp1->x, pp1->y);
}