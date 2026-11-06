#ifndef CALENDAR_TODAYDISPLAY_H
#define CALENDAR_TODAYDISPLAY_H
#include "LanguageTable.h"
#include "TextField.h"

typedef struct{
    int year;
    LanguageUnit* monthLang;
    int dayNr;
    LanguageUnit* dayOfTheWeekLang;
    TextField yearText;
    TextFieldLocalized monthText;
    TextField dayText;
    TextFieldLocalized dayOfTheWeekText;
}TodayDisplay;

void InitTodayDisplay(TodayDisplay* tdyDisplay, LanguageTable* languageTable, Font* font);
void UpdateTodayDisplay(TodayDisplay* tdyDisplay);
void DrawTodayDisplay(TodayDisplay* tdyDisplay);

#endif //CALENDAR_TODAYDISPLAY_H
