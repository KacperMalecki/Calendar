#include "TextFieldButton.h"

void InitTextFieldButton(TextFieldButton* txtFB, Font* font, char* text, float size, Rectangle sizePos, Color normal, Color highlighted, Color pressed) {
    InitTextField(&txtFB->textField, font, text);
    SetDimensionsForTextField(&txtFB->textField.setts, (Vector2){sizePos.x + sizePos.width / 2, sizePos.y + sizePos.height / 2}, size, TEXT_CENTER);
    txtFB->shape = sizePos;
    InitButton(&txtFB->button, sizePos, normal, highlighted, pressed);
}

void InitTextFieldLocalizedButton(TextFieldLocalizedButton* txtFLB, Font* font, LanguageUnit* unit, float size, Rectangle sizePos, Color normal, Color highlighted, Color pressed) {
    InitTextFieldLocalized(&txtFLB->textFieldLocalized, font, unit);
    SetDimensionsForTextField(&txtFLB->textFieldLocalized.setts, (Vector2){sizePos.x + sizePos.width / 2, sizePos.y + sizePos.height / 2}, size, TEXT_CENTER);
    txtFLB->shape = sizePos;
    InitButton(&txtFLB->button, sizePos, normal, highlighted, pressed);
}

void DrawTextFieldButton(TextFieldButton* txtFB) {
    DrawRectangle((int)txtFB->shape.x, (int)txtFB->shape.y, (int)txtFB->shape.width, (int)txtFB->shape.height, txtFB->button.currentClr);
    DrawTextField(&txtFB->textField);
}

void DrawTextFieldLocalizedButton(TextFieldLocalizedButton* txtFLB) {
    DrawRectangle((int)txtFLB->shape.x, (int)txtFLB->shape.y, (int)txtFLB->shape.width, (int)txtFLB->shape.height, txtFLB->button.currentClr);
    DrawTextFieldLocalized(&txtFLB->textFieldLocalized);
}