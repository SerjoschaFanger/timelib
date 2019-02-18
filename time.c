
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"


/**
* Name : day_of_the_year
* Param : int day, int month, int year
* Returns :
*           the day of the year
*          -1, if date invalid
* Function : Returns the day of the year according to input
**/
int day_of_the_year(struct date date)
{
    int days = 0;
    if(exists_date(date))
    {
        for(int i = 0; i < date.month; i++)
        {
            days += get_days_for_month(i+1, date.year);
        }
        days -= get_days_for_month(date.month, date.year) - date.day;
    }else
    {
        return -1;
    }

    return days;
}

/**
* Name : isLeapyear
* Param : int yearprintf()
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
int exists_date(struct date date)
{
    if(date.year < 1582 || date.year > 2400)
    {
        return 0;
    }else
    {
        if(get_days_for_month(date.month, date.year) == -1)
        {
            return 0;
        }else if(get_days_for_month(date.month, date.year) < date.day || date.day <= 0)
        {
            return 0;
        }else
        {
            return 1;
        }
    }
    return 0;
}

/**
* Name : week_day
* Param : int day, int month, int year
* Returns :
*           0, if date is sunday 2
*           1, if date is monday 3
*           2, if date is tuesday 4
*           3, if date is wednesday 5
*           4, if date is thursday 6
*           5, if date is friday 0
*           6, if date is saturday 1
*           -1, if date is invalid
* Function : Returns week day of a date of the Gregorian calendar between 1582 and 2400
**/
int week_day(struct date date)
{
    int diff = 0;
    struct date startDate;
    startDate.day = 1;
    startDate.month = 1;
    startDate.year = 1582;
    if(days_from_to(date, startDate) == -1)
    {
        return -1;
    }
    diff = days_from_to(date, startDate);
    int weekday = diff % 7;
    if(weekday < 2)
    {
        weekday += 5;
    }else
    {
        weekday -= 2;
    }
    return weekday;

}

/**
* Name : from_date_to_end_of_year
* Param : int day, int month, int year
* Returns :
*           the amount of days remaining to the end of the year
*           -1, if date is invalid
* Function : Returns the days remaining to the end of the year, accounting for leap years
**/
int from_date_to_end_of_year(struct date date)
{
    int result = 0;
    if(exists_date(date))
    {
        if(isLeapyear(date.year))
        {
            result = 366 - day_of_the_year(date);
            return result;
        }else
        {
            result = 365 - day_of_the_year(date);
            return result;
        }
    }
    return -1;
}

/**
* Name : days_from_to
* Param : int day_from, int month_from, int year_from
*         int day_to, int month_to, int year_to
* Returns :
*           the amount of days between given dates
*           -1, if date is invalid
* Function : Returns the day differential between two dates in the gregorian calender,
*            works for bigger "from-date" to "to-date" and reverse
**/
int days_from_to(struct date date_from, struct date date_to)
{
    // check if both dates given are valid
    if(exists_date(date_from) && exists_date(date_to))
    {
        int result = 0;
        int flipped = 0;
        int year_difference = date_from.year - date_to.year;
        // if we are in the same year
        if(year_difference == 0)
        {
            // .. and the same month
            if(date_from.month == date_to.month)
            {
                // calculate day differential
                result = date_from.day - date_to.day;
                // in case day_to was bigger, flip the result
                if(result < 0)
                {
                    result = result*-1;
                }
                return result;
            }
            else
            {
                int month_difference = date_from.month - date_to.month;
                // in case month_to was bigger, flip the result
                if(month_difference < 0)
                {
                    month_difference = month_difference*-1;
                    flipped = 1;
                }
                /**
                *   Following block calculates the days for all months,
                *   assuming year_from and year_to are the same
                **/
                if(flipped)
                {
                    month_difference += 1;
                }
                for(int i = 0; i < month_difference; i++)
                {
                    // add onto the result depending on the direction
                    if(flipped)
                    {
                        result += get_days_for_month((date_to.month-i), date_from.year);
                    }else
                    {
                        result += get_days_for_month((date_from.month-i), date_from.year);
                    }
                }
                // detract remaining days from the result depending on the direction
                if(!flipped)
                {
                    result -= get_days_for_month(date_from.month, date_from.year) - date_from.day;
                    result -= get_days_for_month(date_to.month, date_to.year) - date_to.day;
                }else
                {
                    result -= date_from.day;
                }
                return result;
            }
        }
        // in case year_to was bigger than year_from, flip the result
        else if(year_difference < 0)
        {
            year_difference = year_difference*-1;
        }
        // add one extra year for the for-loop
        year_difference += 1;
        for(int i = 0; i < year_difference; i++)
        {
            // add full years to the result depending if leapyear or not
            if(isLeapyear(date_from.year-i))
            {
                result += 366;
            }else
            {
                result += 365;
            }
        }
        // detract from the result depending on the direction
        if(date_from.year < date_to.year)
        {
            result -= day_of_the_year(date_from);
            result -= from_date_to_end_of_year(date_to);

        }else if(date_from.year > date_to.year)
        {
            result -= day_of_the_year(date_to);
            result -= from_date_to_end_of_year(date_from);
        }
        return result;
    }
    return -1;
}

/**
* Name : calendar_week
* Param : int day, int month, int year
* Returns :
*           the calendar week of given date
*           -1, if date is invalid
* Function : Returns the calendar week of given date
**/
int calendar_week(struct date date)
{
    if(exists_date(date))
    {
        int result = 0;
        result = day_of_the_year(date) / 7;
        if((day_of_the_year(date)%7) != 0)
        {
            result++;
        }
        return result;
    }
    return -1;
}


/**
* Name : input_date
* Param : int *day, int *month, int *year
* Returns : -
* Function : Prompts user to input day, month and year of a date
*            until criteria of gregorian calender are met
**/
void input_date(int *day, int *month, int *year)
{
    struct date date;
    date.day = 0;
    date.month = 0;
    date.year = 0;
    do
    {
        do
        {
            printf("Please enter valid day of date:\n");
            scanf("%i", &date.day);
        }while(date.day < 1 || date.day > 31);

        do
        {
            printf("Please enter valid month of date:\n");
            scanf("%i", &date.month);
        }while(date.month < 1 || date.month > 12);

        do
        {
            printf("Please enter valid year of date:\n");
            scanf("%i", &date.year);
        }while(date.year < 1582 || date.year > 2400);

    }while(exists_date(date) == 0);

    *day = date.day;
    *month = date.month;
    *year = date.year;
}

void input_date_struct(struct date *date)
{
    struct date temp;
    temp.day = 0;
    temp.month = 0;
    temp.year = 0;

    do
    {
        do
        {
            printf("Please enter valid day of date:\n");
            scanf("%i", &temp.day);
        }while(temp.day < 1 || temp.day > 31);

        do
        {
            printf("Please enter valid month of date:\n");
            scanf("%i", &temp.month);
        }while(temp.month < 1 || temp.month > 12);

        do
        {
            printf("Please enter valid year of date:\n");
            scanf("%i", &temp.year);
        }while(temp.year < 1582 || temp.year > 2400);

    }while(exists_date(temp) == 0);

    date->day = temp.day;
    date->month = temp.month;
    date->year = temp.year;

}




