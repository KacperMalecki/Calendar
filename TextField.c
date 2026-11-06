#include "TextField.h"

static void InitTextFieldBase(TextFieldBase* textFieldBase, Font* font) {
    textFieldBase->font = font;
    textFieldBase->position = (Vector2){0, 0};
    textFieldBase->size = 10;
    textFieldBase->spacing = 1;
    textFieldBase->color = BLACK;
    textFieldBase->origin = TEXT_CENTER;
}

void InitTextField(TextField* textField, Font* font, char* text) {
    InitTextFieldBase(&textField->setts, font);
    textField->text = text;
}

void InitTextFieldLocalized(TextFieldLocalized* textFieldLocalized, Font* font, LanguageUnit* unit) {
    InitTextFieldBase(&textFieldLocalized->setts, font);
    textFieldLocalized->localizedText = unit;
}

void SetDimensionsForTextField(TextFieldBase* textFieldBase, Vector2 position, float size, TextOrigin origin) {
    textFieldBase->position = position;
    textFieldBase->size = size;
    textFieldBase->origin = origin;
}

void DrawTextField(TextField* textField) {
    DrawTextWithOrigin(textField->setts.font, textField->text, textField->setts.position, textField->setts.size, textField->setts.spacing, textField->setts.color, textField->setts.origin);
}

void DrawTextFieldLocalized(TextFieldLocalized* textFieldLocalized) {
    DrawTextWithOrigin(textFieldLocalized->setts.font, textFieldLocalized->localizedText->value, textFieldLocalized->setts.position, textFieldLocalized->setts.size, textFieldLocalized->setts.spacing, textFieldLocalized->setts.color, textFieldLocalized->setts.origin);
}