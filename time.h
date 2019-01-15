#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);
int day_of_the_year(int day, int month, int year);
int isLeapyear(int year);
int days_from_to(int day_from, int month_from, int year_from
                 , int day_to, int month_to, int year_to);
int from_date_to_end_of_year(int day, int month, int year);
int week_day(int day, int month, int year);

#endif // TIME_H_INCLUDED
