#include <stdio.h>

struct point {
    int x;
    int y;
};

struct point makepoint(int, int);
struct point addpoints(struct point, struct point);

/*
 * make a point from x and y coordinates
 */
int main()
{
    struct point temp, *pp, other, bigger;

    temp.x = 1;
    temp.y = 2;

    pp = &temp;

    other = makepoint(3, 4);

    bigger = addpoints(other, temp);

    printf("%d, %d\n", temp.x, temp.y);

    // Pointer to the struct and how to
    // access the members
    // printf("%d, %d\n", (*pp).x, (*pp).y);
    printf("%d, %d\n", pp->x, pp->y);

    printf("%d, %d\n", other.x, other.y);

    printf("%d, %d\n", bigger.x, bigger.y);
}

struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;

    return temp;
}

struct point addpoints(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;

    return p1;
}
