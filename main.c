#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main()
{
    //printf("Tag des Jahres: %i\n", day_of_the_year(18, 9, 2018));
    /*struct date date_from;
    struct date date_to;
    date_from.day = 1;
    date_from.month = 7;
    date_from.year = 2020;
    printf("%i\n", week_day(date_from));*/
    /*printf("Sollte 29 sein : %i\n", days_from_to(1,9,2018,30,9,2018));
    printf("Sollte 73 sein : %i\n", days_from_to(12,12,2018,30,9,2018));
    printf("Sollte 179 sein : %i\n", days_from_to(4,4,2018,30,9,2018));
    printf("Sollte 365 sein : %i\n", days_from_to(4,4,2018,4,4,2019));
    printf("Sollte 365 sein : %i\n", days_from_to(4,4,2019,4,4,2018));
    printf("Sollte 6603 sein : %i\n", days_from_to(1,9,2000,30,9,2018));
    printf("Sollte 6545 sein : %i\n", days_from_to(1,9,2018,30,9,2000));*/
    /*printf("%i\n",week_day(16,9,2019));

    printf("%i\n",week_day(17,9,2019));
    printf("%i\n",week_day(18,9,2019));
    printf("%i\n",week_day(19,9,2019));
    printf("%i\n",week_day(20,9,2019));
    printf("%i\n",week_day(21,9,2019));
    printf("%i\n",week_day(22,9,2019));*/
    //printf("%i\n", calendar_week(15,12,2019));
    /*int d = 0;
    int m = 0;
    int y = 0;

    int *day = &d;
    int *month = &m;
    int *year = &y;*/
    struct date date;
    input_date_struct(&date);
    printf("Entered Date: %i.%i.%i\n", date.day, date.month, date.year);
    return 0;
}


