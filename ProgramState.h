#ifndef CALENDAR_PROGRAMSTATE_H
#define CALENDAR_PROGRAMSTATE_H
#include "raylib.h"

typedef enum{
    STATE_CALENDAR,
    STATE_EVENTS_LIST,
    STATE_SETTINGS,
    STATE_ABOUT_THE_PROGRAM,
    STATE_CLOSE_THE_PROGRAM,
    STATE_FATAL_ERROR
}ProgramState;

void ProgramLoop();
void OnBeginDrawing();
void OnEndDrawing();
void ScaleMousePosition(Vector2* mousePosScaled);

#endif //CALENDAR_PROGRAMSTATE_H
