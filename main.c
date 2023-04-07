#include <stdio.h>

/*
 * Copy input to output
*/
int main()
{
    int c;
    long nc;

    c = getchar();
    nc = 0;
    while (c != EOF) {
        ++nc;
        putchar(c);
        c = getchar();
        printf("%ld\n", nc);
    }

    // while ((c = getchar()) != EOF) {
    //     putchar(c);
    // }
    
    // double nc;
    //
    // for (nc = 0; getchar() != EOF; ++nc)
    //     ;
    // printf("%.0f\n", nc);
}

