#include <stdio.h>
#include <time.h>

int year_progress();
void print_progress(int progress);

/*
 * Test power function
 */
int main()
{
    int progress;

    progress = year_progress();
    print_progress(progress);

    return 0;
}

int year_progress()
{
    int ndays, nday;

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    nday = ndays = tm->tm_yday + 1;

    if (tm->tm_year % 4 == 0 && (tm->tm_year % 100 != 0 || tm->tm_year % 400 == 0))
        ndays = 366;
    else
        ndays = 365;

    return (nday * 100) / ndays;
}

void print_progress(int progress)
{
    int i, progress_bars;

    progress_bars = progress / 10;

    printf("Progress: |");
    for (i = 0; i < 10; ++i) {
        if (i <= progress_bars)
            printf("█");
        else
            printf("-");
    }
    printf("| %d%% Complete\n", progress);
}
