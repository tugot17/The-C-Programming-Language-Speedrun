#include <stdio.h>
#include <time.h>
#include "date.h"

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day){
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}

int main(int argc, char const *argv[])
{
    time_t t = time(NULL);
    struct tm today_tm = *localtime(&t);

    struct Date today = {
        .year = today_tm.tm_year + 1900,
        .month = today_tm.tm_mon + 1,
        .day = today_tm.tm_mday
    };

    printf("Today: %d-%02d-%02d is %d day of the year\n", 
           today.year, today.month, today.day, 
           day_of_year(today.year, today.month, today.day));

    return 0;
}
