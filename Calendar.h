#ifndef CALENDAR_CALENDAR_H
#define CALENDAR_CALENDAR_H

#include "Tile.h"
#include "LanguageTable.h"

typedef struct Calendar {
    Vector2 position;
    Vector2 tileSize;
    Vector2 spacing;    //  spacing between tiles
    Color normalDayClr;
    Color weekendDayClr;
    Color normalOutDayClr;
    Color weekendOutDayClr;
    Vector4 highlightDelta;   //  by how much to change the default color, so it's treated as a highlighted version
    Vector4 pressedDelta;     //  by how much to change the default color, so it's treated as a pressed version
    Font* font;
    char weekNumbers[6][3];     //  rows description
    Vector2 textOffsetForWeekNumbers;
    LanguageUnit *dayName[7];       //  days of the week
    LanguageUnit *monthsName[12];   //  months

    Tile tiles[6][7];

}Calendar;

void InitCalendar(Calendar *calendar, LanguageTable* languageTable, Font* font);
void DrawCalendar(Calendar *calendar, Font* font);
void UpdateCalendar(Calendar *calendar, Vector2 mousePosition);
void ReloadLanguage(Calendar *calendar, LanguageTable *languageTable);

#endif //CALENDAR_CALENDAR_H
