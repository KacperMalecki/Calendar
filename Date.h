#ifndef CALENDAR_DATE_H
#define CALENDAR_DATE_H
#include <time.h>

typedef enum{
    DATE_YEAR,
    DATE_MONTH,
    DATE_DAY,
    DATE_WEEK_NR,
    DATE_DAY_NR,
    DATE_HOUR,
    DATE_MINUTE,
    DATE_SECOND,
}DateType;

int GetCurrentYear();
int GetFromToday(DateType type);
int GetFromSpecificDay(DateType type, time_t time);

const char* DayOfTheWeekToString(int dayOfTheWeek);
const char* MonthNumberToString(int monthNumber);

#endif //CALENDAR_DATE_H
