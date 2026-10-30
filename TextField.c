#include "TextField.h"

void InitTextField(TextField* textField, Font* font, LanguageUnit* unit) {
    textField->font = font;
    textField->languageUnit = unit;
    textField->position = (Vector2){0, 0};
    textField->size = 10;
    textField->spacing = 1;
    textField->color = BLACK;
    textField->origin = TEXT_CENTER;
}

void SetDimensionsForTextField(TextField* textField, Vector2 position, float size, TextOrigin origin) {
    textField->position = position;
    textField->size = size;
    textField->origin = origin;
}

void DrawTextField(TextField* textField) {
    DrawTextWithOrigin(textField->font, textField->languageUnit->value, textField->position, textField->size, textField->spacing, textField->color, textField->origin);
}