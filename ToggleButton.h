#ifndef CALENDAR_TOGGLEBUTTON_H
#define CALENDAR_TOGGLEBUTTON_H

#include "raylib.h"
#include "button.h"

typedef struct{
    Button button;
    Rectangle rectKnob;
    Rectangle rectBackground;
    Color backgroundColor;
    Rectangle rectFill;
    Color fillColor;
    bool toggleValue;


}ToggleButton;

void InitToggleButton(ToggleButton *bttn, Rectangle posSize, Color normal, Color highlighted, Color pressed, Color background, Color fill, bool initValue);
void DrawToggleButton(ToggleButton *bttn);
void UseToggleButton(ToggleButton *bttn);

#endif //CALENDAR_TOGGLEBUTTON_H
