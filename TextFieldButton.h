#ifndef CALENDAR_TEXTFIELDBUTTON_H
#define CALENDAR_TEXTFIELDBUTTON_H
#include "Button.h"
#include "TextField.h"

typedef struct {
    TextField textField;
    Button button;
    Rectangle shape;
}TextFieldButton;

typedef struct {
    TextFieldLocalized textFieldLocalized;
    Button button;
    Rectangle shape;
}TextFieldLocalizedButton;

void InitTextFieldButton(TextFieldButton* txtFB, Font* font, char* text, float size, Rectangle sizePos, Color normal, Color highlighted, Color pressed);
void InitTextFieldLocalizedButton(TextFieldLocalizedButton* txtFLB, Font* font, LanguageUnit* unit, float size, Rectangle sizePos, Color normal, Color highlighted, Color pressed);

void DrawTextFieldButton(TextFieldButton* txtFB);
void DrawTextFieldLocalizedButton(TextFieldLocalizedButton* txtFLB);

#endif //CALENDAR_TEXTFIELDBUTTON_H
