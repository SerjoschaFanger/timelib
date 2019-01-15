#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main()
{
    //printf("Tag des Jahres: %i\n", day_of_the_year(18, 9, 2018));
    /*printf("Sollte 29 sein : %i\n", days_from_to(1,9,2018,30,9,2018));
    printf("Sollte 73 sein : %i\n", days_from_to(12,12,2018,30,9,2018));
    printf("Sollte 179 sein : %i\n", days_from_to(4,4,2018,30,9,2018));
    printf("Sollte 365 sein : %i\n", days_from_to(4,4,2018,4,4,2019));
    printf("Sollte 365 sein : %i\n", days_from_to(4,4,2019,4,4,2018));
    printf("Sollte 6603 sein : %i\n", days_from_to(1,9,2000,30,9,2018));
    printf("Sollte 6545 sein : %i\n", days_from_to(1,9,2018,30,9,2000));*/
    printf("%i\n",week_day(16,9,2019));
    printf("%i\n",week_day(17,9,2019));
    printf("%i\n",week_day(18,9,2019));
    printf("%i\n",week_day(19,9,2019));
    printf("%i\n",week_day(20,9,2019));
    printf("%i\n",week_day(21,9,2019));
    printf("%i\n",week_day(22,9,2019));

    return 0;
}


