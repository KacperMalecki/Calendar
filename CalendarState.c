#include "CalendarState.h"
#include <stdio.h>

static void Update(CalendarState* calendarState, ProgramState* currentProgramState);
static void Draw(CalendarState *calendarState);
void OpenSettings(ProgramState* currentProgramState);

void InitCalendarState(CalendarState* calendarState, LanguageTable* languageTable, Settings* settings, Font* font) {
    //  Calendar initialization
    calendarState->calendar = (Calendar){{90.f, 200.f}, {240.f, 135.f}, {8.f, 8.f}};
    calendarState->calendar.textOffsetForWeekNumbers = (Vector2){10,10};
    calendarState->calendar.highlightDelta = (Vector4){-30,-30,-30,0};
    calendarState->calendar.pressedDelta = (Vector4){-60,-60,-60,0};

    calendarState->languageTable = languageTable;
    calendarState->settings = settings;
    calendarState->font = font;
    InitCalendar(&calendarState->calendar, calendarState->languageTable, calendarState->font);
}

void RunCalendarState(CalendarState* calendarState, ProgramState* currentProgramState) {
    while (*currentProgramState == STATE_CALENDAR && !WindowShouldClose()) {
        // Update
        Update(calendarState, currentProgramState);

        // Draw
        OnBeginDrawing();

        Draw(calendarState);

        OnEndDrawing();
    }

    if (WindowShouldClose() && *currentProgramState != STATE_FATAL_ERROR) {
        *currentProgramState = STATE_CLOSE_THE_PROGRAM;
    }
}

static void Update(CalendarState* calendarState, ProgramState* currentProgramState) {
    //  scaling mouse position
    Vector2 mousePosScaled;
    ScaleMousePosition(&mousePosScaled);
    //  Events / Input
    if (IsKeyReleased(KEY_SPACE)) {
        ToggleFullscreen();
        if (!IsWindowFullscreen()) {
            MaximizeWindow();
        }
    }
    if (IsKeyReleased(KEY_R)) {
        *currentProgramState = STATE_SETTINGS;
    }
    //  Update
    UpdateCalendar(&calendarState->calendar, mousePosScaled);
};

static void Draw(CalendarState *calendarState) {
    DrawCalendar(&calendarState->calendar, calendarState->font);
    //
    //  TESTING AREA BELOW
    //          vvv
    DrawText("TEST TEST test test!!! 1: 2: 3: 4: 5:!", 400, 360, 30, RED);
    DrawText("Küche", 200, 40, 30, RED);
    char sentence[] = "Żółty płomień";
    DrawTextEx( *calendarState->font, "oseŹ\nDrabina", (Vector2){0, 0}, 40, 1, BLACK);
    DrawTextEx( *calendarState->font, "Żółć źłbie ęńś", (Vector2){400, 50}, 60, 1, BLACK);
    DrawTextEx( *calendarState->font, sentence, (Vector2){400, 100}, 12, 1, BLACK);
    DrawTextEx(*calendarState->font, "J’aimerais déguster du fromage accompagné d’un verre de vin de très grande qualité.",
        (Vector2){1920, 0}, 30, 1, PURPLE);
    DrawTextWithOrigin(calendarState->font, "J’aimerais déguster du fromage accompagné d’un verre de vin de très grande qualité.",
        (Vector2){1920, 0}, 30, 1, PURPLE, TEXT_RIGHT);
    unsigned int dec = 0;
    sscanf("105", "%x", &dec);
    DrawTextCodepoint(*calendarState->font, 255, (Vector2){100.f, 40.f}, 50, RED);
}

void OpenSettings(ProgramState* currentProgramState) {
    *currentProgramState = STATE_SETTINGS;
}