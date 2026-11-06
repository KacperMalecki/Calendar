#include "Date.h"

#include "Utilities.h"

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
        case DATE_DAY_NR: value = (localTime->tm_wday == 0)?7:localTime->tm_wday; break;
        case DATE_HOUR: value = localTime->tm_hour; break;
        case DATE_MINUTE: value = localTime->tm_min; break;
        case DATE_SECOND: value = localTime->tm_sec; break;
        default: value = -1; break;
    }
    return value;
}

const char* DayOfTheWeekToString(int dayOfTheWeek) {
    dayOfTheWeek = ClampInt(dayOfTheWeek, 1, 7);
    char* result = nullptr;
    switch (dayOfTheWeek) {
        case 1: result = "Monday"; break;
        case 2: result = "Tuesday"; break;
        case 3: result = "Wednesday"; break;
        case 4: result = "Thursday"; break;
        case 5: result = "Friday"; break;
        case 6: result = "Saturday"; break;
        case 7: result = "Sunday"; break;
    }
    return result;
}
const char* MonthNumberToString(int monthNumber) {
    monthNumber = ClampInt(monthNumber, 1, 12);
    char* result = nullptr;
    switch (monthNumber) {
        case 1: result = "January"; break;
        case 2: result = "February"; break;
        case 3: result = "March"; break;
        case 4: result = "April"; break;
        case 5: result = "May"; break;
        case 6: result = "June"; break;
        case 7: result = "July"; break;
        case 8: result = "August"; break;
        case 9: result = "September"; break;
        case 10: result = "October"; break;
        case 11: result = "November"; break;
        case 12: result = "December"; break;
    }
    return result;
}