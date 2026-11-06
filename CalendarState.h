#ifndef CALENDAR_CALENDARSTATE_H
#define CALENDAR_CALENDARSTATE_H

#include "Calendar.h"
#include "ColorTheme.h"
#include "ProgramState.h"
#include "Settings.h"
#include "TextureButton.h"

typedef struct{
    //  external data
    LanguageTable* languageTable;
    Settings* settings;
    ColorTheme* colorTheme;
    Font* font;
    char* errorMessageDest;
    Texture2D settingsTxtr;
    //  ui data
    Calendar calendar;
    TextureButton settingsButton;
}CalendarState;

void InitCalendarState(CalendarState* calendarState, LanguageTable* languageTable, Settings* settings, ColorTheme* colorTheme, Font* font, char* errorMessage);
void RunCalendarState(CalendarState* calendarState, ProgramState* currentProgramState);
void UnloadCalendarState(CalendarState* calendarState);

#endif //CALENDAR_CALENDARSTATE_H
