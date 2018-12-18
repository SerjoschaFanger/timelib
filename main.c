/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);

/**
* Name : day_of_the_year
* Param : int day, int month, int year
* Returns :
*           the day of the year
*          -1, if date invalid
* Function : Returns the day of the year according to input
**/
int day_of_the_year(int day, int month, int year)
{
    int days = 0;
    if(exists_date(day,month,year))
    {
        for(int i = 0; i < month; i++)
        {
           days += get_days_for_month(i+1, year);
        }
        days -= get_days_for_month(month, year) - day;
    }else
    {
        return -1;
    }


    return days;
}

/**
* Name : isLeapyear
* Param : int year
* Returns :
*           0, if year is not a leap year
*           1, if year is a leap year
*          -1, if year is smaller 1582
* Function : Checks if year is a leap year in the gregorian calender
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

/**
* Name : get_days_for_month
* Param : int month, int year
* Returns :
*           days in given month/year
*          -1, if month is invalid
* Function : Gives back days of input month
**/
int get_days_for_month(int month, int year)
{

    int days = 0;
    switch(month)
    {
        case 1 :
        case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10:
        case 12: days = 31;break;
        case 2 :
                 if(isLeapyear(year) == 1)
                 {
                     days = 29;break;
                 }else if(isLeapyear(year) == 0)
                 {
                     days = 28;break;
                 }else
                 {
                     return -1;
                 }
        case 4 :
        case 6 :
        case 9 :
        case 11: days = 30;break;

        default : return -1;
    }
    return days;
}

/**
* Name : exists_date
* Param : int day, int month, int year
* Returns :
*           0, if date is invalid
*           1, if date is valid
* Function : Checks if input date is in fact a date of the Gregorian calender between 1582 and 2400
**/
int exists_date(int day, int month, int year)
{
    if(year < 1582 || year > 2400)
    {
        return 0;
    }else
    {
        if(get_days_for_month(month, year) == -1)
        {
            return 0;
        }else if(get_days_for_month(month, year) < day || day <= 0)
        {
            return 0;
        }else
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
