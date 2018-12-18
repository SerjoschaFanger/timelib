/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year)
{
    // Returns now 1 instead of 0, what a change
    return 1;
}

/**
* Name : isLeapyear
* Param : int year
* Returns :
*           0, if year is not a leap year
*           1, if year is a leap year
*          -1, if year is smaller 1582
* Funtion : Checks if year is a leap year in the gregorian calender
**/
int isLeapyear(int year)
{
    if (year < 1582)
    {
        return -1;
    }
    if (year%4 != 0)
    {
        return 0;
    }
    else if (year%100 != 0 || year%400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
