#include "Date.h"

//  https://www.w3schools.com/c/c_date_time.php

int GetCurrentYear() {              //  IS IT NEEDED?????????????
    time_t today = time(nullptr);
    struct tm *localTime = localtime(&today);
    int currentYear;
    return currentYear;
}

int GetFromToday(DateType type) {
    return GetFromSpecificDay(type, time(nullptr));
}

int GetFromSpecificDay(DateType type, time_t time) {
    int value = 0;
    struct tm *localTime = localtime(&time);
    switch (type) {
        case DATE_YEAR: value = localTime->tm_year + 1900; break;
        case DATE_MONTH: value = localTime->tm_mon + 1; break;
        case DATE_DAY: value = localTime->tm_mday; break;
        case DATE_WEEK_NR:
            //      TODO
            char buffer[10];
            // %V gives ISO 8601 week number (01-53)
            strftime(buffer, sizeof(buffer), "%V", localTime);
            //  TODO char to int
            //value = localTime->tm_wday;
            break;
        case DATE_DAY_NR: value = localTime->tm_wday; break;    //  0 = Sunday, 6 = Monday !!!
        case DATE_HOUR: value = localTime->tm_hour; break;
        case DATE_MINUTE: value = localTime->tm_min; break;
        case DATE_SECOND: value = localTime->tm_sec; break;
        default: value = -1; break;
    }
    return value;
}