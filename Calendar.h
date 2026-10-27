#ifndef CALENDAR_CALENDAR_H
#define CALENDAR_CALENDAR_H

#include "Tile.h"
#include <uchar.h>

typedef struct Calendar {
    Vector2 position;
    Vector2 tileSize;
    Vector2 spacing;    //  spacing between tiles
    Color normalDayClr;
    Color weekendDayClr;
    Color normalOutDayClr;
    Color weekendOutDayClr;
    char weekNumbers[6][3];     //  rows description
    char16_t* dayName[7];       //  columns description

    Tile tiles[6][7];

}Calendar;

void InitCalendar(Calendar *calendar);
void DrawCalendar(Calendar *calendar);
void UpdateCalendar(Calendar *calendar, Vector2 mousePosition);

#endif //CALENDAR_CALENDAR_H
