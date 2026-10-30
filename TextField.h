#ifndef CALENDAR_TEXTFIELD_H
#define CALENDAR_TEXTFIELD_H

#include "LanguageTable.h"
#include "raylib.h"
#include "RaylibExtension.h"

typedef struct TextField {
    Vector2 position;
    TextOrigin origin;
    float size;
    float spacing;
    Font* font;
    Color color;
    LanguageUnit* languageUnit;
}TextField;

void InitTextField(TextField* textField, Font* font, LanguageUnit* unit);
void SetDimensionsForTextField(TextField* textField, Vector2 position, float size, TextOrigin origin);
void DrawTextField(TextField* textField);
#endif //CALENDAR_TEXTFIELD_H
