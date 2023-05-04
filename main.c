#include <stdio.h>

/*
 * echo command-line arguments
 * argc: arguments count, if 1 then there are no arguments
 * argv: list of arguments, the first one is
 * the name by which the program was invoked.
 * argv[argc] == NULL
 *
 */
int main(int argc, char *argv[])
{
    // 1st version
    // int i;
    //
    // for (i = 1; i < argc; i++)
    //     printf("%s%s", argv[i], (i < argc - 1)?" ":"");

    // 2nd version
    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1)?" ":"");

    printf("\n");
    return 0;
}
