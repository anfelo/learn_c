#include <stdio.h>

#define LOWER 0 /* lower limit of temperature */
#define UPPER 300 /* upper limit */
#define STEP 20 /* step size */

/*
 * Print Farenheit-Celcius table
 * for fahr = 0,20,...,300
*/
int main()
{
    float fahr, celsius;

    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f%6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }

    // With for loop
    // int fahr;
    //
    // for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
    //     printf("%3d%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    // }
}

