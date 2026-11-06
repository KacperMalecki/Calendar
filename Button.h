#ifndef CALENDAR_BUTTON_H
#define CALENDAR_BUTTON_H

#include "ProgramState.h"
#include "raylib.h"

typedef enum{
    BUTTON_NORMAL,
    BUTTON_HIGHLIGHTED,
    BUTTON_PRESSED
}ButtonState;

typedef void (*callback)(ProgramState*);

typedef struct{
    Rectangle rect;
    ButtonState state;
    Color normal;
    Color highlighted;
    Color pressed;
    Color currentClr;
    bool wasPressed;
}Button;

void InitButton(Button *button, Rectangle rect, Color normal, Color highlighted, Color pressed);
void UpdateButton(Button *button, Vector2 mousePosition);
bool WasButtonPressed(Button *button);  //  if return value is TRUE, then wasPressed variable is set to FALSE

#endif //CALENDAR_BUTTON_H
