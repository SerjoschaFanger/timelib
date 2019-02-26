#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

/**
*   Date    : 26.02.2019
*   Author  : Serjoscha Fanger
*   Function: Library provides basic date related functions,
*             like determining if a date is valid or what day of the year it is.
**/

struct date
{
    int day;
    int month;
    int year;
};

void input_date(int *day, int *month, int *year);
int get_days_for_month(int month, int year);
int exists_date(struct date date);
int day_of_the_year(struct date date);
int isLeapyear(int year);
int days_from_to(struct date date_from, struct date date_to);
int from_date_to_end_of_year(struct date date);
int week_day(struct date date);
int calendar_week(struct date date);
void input_date_struct(struct date *date);
#endif // TIME_H_INCLUDED
