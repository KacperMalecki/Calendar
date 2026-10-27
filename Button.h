#ifndef CALENDAR_BUTTON_H
#define CALENDAR_BUTTON_H

#include "raylib.h"

typedef enum ButtonState {
    BUTTON_NORMAL,
    BUTTON_HIGHLIGHTED,
    BUTTON_PRESSED
}ButtonState;

typedef void (*callback)();

typedef struct Button {
    Rectangle rect;
    ButtonState state;
    Color normal;
    Color highlighted;
    Color pressed;
    Color currentClr;
    callback onRelease;
}Button;

void InitButton(Button *button, Rectangle rect, Color normal, Color highlighted, Color pressed);
void UpdateButton(Button *button, Vector2 mousePosition);

#endif //CALENDAR_BUTTON_H
