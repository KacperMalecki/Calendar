#ifndef CALENDAR_EVENT_H
#define CALENDAR_EVENT_H

typedef struct {
    int beginYear;
    int beginMonth;
    int beginDay;
    int beginHour;
    int beginMinute;

    int endYear;
    int endMonth;
    int endDay;
    int endHour;
    int endMinute;

    char* name;
    unsigned int textLinesOfDescription;
    char* description;
}Event;

bool LoadEvents(Event* events, const char* pathName);
bool AddEvent(Event eventToAdd, Event* eventsArray);
bool RemoveEvent(Event* eventToRemove, Event* eventsArray);
bool SaveEvents(Event* events, const char* pathName);

#endif //CALENDAR_EVENT_H
