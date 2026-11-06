#ifndef CALENDAR_COLORTHEME_H
#define CALENDAR_COLORTHEME_H

#define NUMBER_OF_SINGLETHEMES 10
#define NUMBER_OF_BUTTONTHEMES 6

#include "raylib.h"

typedef struct {
    char type[7];
    char* name;
    Color clr;
}SingleTheme;

typedef struct {
    char type[7];
    char* name;
    Color normal;
    Color highlight;
    Color pressed;
}ButtonTheme;

typedef struct {
    SingleTheme* singles;
    ButtonTheme* buttons;
}ColorTheme;

void InitSingleTheme(SingleTheme* singleTheme);
void InitButtonTheme(ButtonTheme* buttonTheme);

void InitColorTheme(ColorTheme* colorTheme);
bool LoadColorTheme(ColorTheme* colorTheme, const char* pathName);
SingleTheme* GetSingleTheme(ColorTheme* colorTheme, char* name);
ButtonTheme* GetButtonTheme(ColorTheme* colorTheme, char* name);

void FreeMemoryForColorTheme(ColorTheme* colorTheme);

#endif //CALENDAR_COLORTHEME_H
