/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);
int days_from_to(int day_from, int month_from, int year_from
                 , int day_to, int month_to, int year_to);

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

/**
* Name : week_day
* Param : int day, int month, int year
* Returns :
*           0, if date is sunday
*           1, if date is monday
*           2, if date is tuesday
*           3, if date is wednesday
*           4, if date is thursday
*           5, if date is friday
*           6, if date is saturday
*           -1, if date is invalid
* Function : Returns week day of a date of the Gregorian calender between 1582 and 2400
**/
int week_day(int day, int month, int year)
{
    int diff = 0;
    if(days_from_to(day, month, year, 1, 1, 1582) == -1)
    {
        return -1;
    }
    diff = days_from_to(day, month, year, 1, 1, 1582);
    int weekday = diff % 7;
    return weekday + 2;

}

/**
* Name : from_date_to_end_of_year
* Param : int day, int month, int year
* Returns :
*           the amount of days remaining to the end of the year
*           -1, if date is invalid
* Function : Returns the days remaining to the end of the year, accounting for leap years
**/
int from_date_to_end_of_year(int day, int month, int year)
{
    int result = 0;
    if(exists_date(day, month, year))
    {
        if(isLeapyear(year))
        {
            result = 366 - day_of_the_year(day, month, year);
            return result;
        }else
        {
            result = 365 - day_of_the_year(day, month, year);
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
int days_from_to(int day_from, int month_from, int year_from
                 , int day_to, int month_to, int year_to)
{
    // check if both dates given are valid
    if(exists_date(day_from, month_from, year_from) && exists_date(day_to, month_to, year_to))
    {
        int result = 0;
        int flipped = 0;
        int year_difference = year_from - year_to;
        // if we are in the same year
        if(year_difference == 0)
        {
            // .. and the same month
            if(month_from == month_to)
            {
                // calculate day differential
                result = day_from - day_to;
                // in case day_to was bigger, flip the result
                if(result < 0)
                {
                    result = result*-1;
                }
                return result;
            }
            else
            {
                int month_difference = month_from - month_to;
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
                        result += get_days_for_month((month_to-i), year_from);
                    }else
                    {
                        result += get_days_for_month((month_from-i), year_from);
                    }
                }
                // detract remaining days from the result depending on the direction
                if(!flipped)
                {
                    result -= get_days_for_month(month_from, year_from) - day_from;
                    result -= get_days_for_month(month_to, year_to) - day_to;
                }else
                {
                    result -= day_from;
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
            if(isLeapyear(year_from-i))
            {
                result += 366;
            }else
            {
                result += 365;
            }
        }
        // detract from the result depending on the direction
        if(year_from < year_to)
        {
            result -= day_of_the_year(day_from, month_from, year_from);
            result -= from_date_to_end_of_year(day_to, month_to, year_to);

        }else if(year_from > year_to)
        {
            result -= day_of_the_year(day_to, month_to, year_to);
            result -= from_date_to_end_of_year(day_from, month_from, year_from);
        }
        return result;
    }
    return -1;
}

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
    printf("%i\n",week_day(18,8,2400));
    return 0;
}


