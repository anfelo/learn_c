#include <stdio.h>

struct point {
    int x;
    int y;
};

/*
 * make a point from x and y coordinates
 */
int main()
{
    struct point temp;
    struct point *pp;

    temp.x = 1;
    temp.y = 2;

    pp = &temp;

    printf("%d, %d\n", temp.x, temp.y);
    printf("%d, %d\n", temp.x, temp.y);

    // Pointer to the struct and how to
    // access the members
    printf("%d, %d\n", (*pp).x, (*pp).y);
    printf("%d, %d\n", pp->x, pp->y);
}
