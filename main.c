#include <stdio.h>

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp1(char *s, char *t) {
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

/* strcpy: copy t to s */
void strcpy1(char *s, char *t) {
    while ((*s++ = *t++) != '\0')
        ;
}

/*
 * tests some str functions implemented with pointers
 */
int main() {
    int result;
    char *txt1, *txt2, *other1, *other2;

    txt1 = "first string";
    txt2 = "second string";

    result = strcmp1(txt1, txt2);

    printf("%d\n", result);

    other1 = "foo";
    other2 = "bar";

    strcpy1(other2, other1);

    printf("%c", *other2);
}
