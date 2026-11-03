#ifndef CALENDAR_TEXTFIELD_H
#define CALENDAR_TEXTFIELD_H

#include "LanguageTable.h"
#include "raylib.h"
#include "RaylibExtension.h"

typedef struct TextFieldBase {
    Vector2 position;
    TextOrigin origin;
    float size;
    float spacing;
    Font* font;
    Color color;
    LanguageUnit* languageUnit;
}TextFieldBase;

typedef struct TextField {
    TextFieldBase setts;
    char* text;
}TextField;

typedef struct TextFieldLocalized {
    TextFieldBase setts;
    LanguageUnit* localizedText;
}TextFieldLocalized;

void InitTextField(TextField* textField, Font* font, char* text);
void InitTextFieldLocalized(TextFieldLocalized* textFieldLocalized, Font* font, LanguageUnit* unit);
void SetDimensionsForTextField(TextFieldBase* textFieldBase, Vector2 position, float size, TextOrigin origin);
void DrawTextField(TextField* textField);
void DrawTextFieldLocalized(TextFieldLocalized* textFieldLocalized);
#endif //CALENDAR_TEXTFIELD_H
