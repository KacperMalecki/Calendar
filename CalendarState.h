#ifndef CALENDAR_CALENDARSTATE_H
#define CALENDAR_CALENDARSTATE_H

#include "Calendar.h"
#include "ProgramState.h"
#include "Settings.h"

typedef struct CalendarState {
    Calendar calendar;
    LanguageTable* languageTable;
    Settings* settings;
    Font* font;
}CalendarState;

void InitCalendarState(CalendarState* calendarState, LanguageTable* languageTable, Settings* settings, Font* font);
void RunCalendarState(CalendarState* calendarState, ProgramState* currentProgramState);

#endif //CALENDAR_CALENDARSTATE_H
