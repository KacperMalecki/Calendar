#include "ToggleButton.h"

void InitToggleButton(ToggleButton *bttn, Rectangle posSize, Color normal, Color highlighted, Color pressed, Color background, Color fill, bool initValue) {
    bttn->toggleValue = !initValue;
    InitButton(&bttn->button, posSize, normal, highlighted, pressed);
    bttn->rectBackground = posSize;
    bttn->backgroundColor = background;
    bttn->fillColor = fill;
    UseToggleButton(bttn);
}

void DrawToggleButton(ToggleButton *bttn) {
    Rectangle toDraw = bttn->rectBackground;
    DrawRectangle((int)toDraw.x, (int)toDraw.y, (int)toDraw.width, (int)toDraw.height, bttn->backgroundColor);
    toDraw = bttn->rectFill;
    DrawRectangle((int)toDraw.x, (int)toDraw.y, (int)toDraw.width, (int)toDraw.height, bttn->fillColor);
    toDraw = bttn->rectKnob;
    DrawRectangle((int)toDraw.x, (int)toDraw.y, (int)toDraw.width, (int)toDraw.height, bttn->button.currentClr);
}

void UseToggleButton(ToggleButton *bttn) {
    bttn->toggleValue = !bttn->toggleValue;
    Rectangle rect = bttn->button.rect;
    float factor = bttn->toggleValue ? 1.0f : .0f;
    bttn->rectFill = (Rectangle){rect.x, rect.y, rect.width * (.4f + .5f * factor), rect.height};
    bttn->rectKnob = (Rectangle){rect.x + rect.width * (.1f + .5f * factor), rect.y + rect.height * .025f, rect.width * .3f, rect.height * .95f};
}