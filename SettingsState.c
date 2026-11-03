#include "SettingsState.h"

static void Update(SettingsState* settingsState, ProgramState* currentProgramState);
static void Draw(SettingsState *settingsState);

void InitSettingsState(SettingsState* settingsState, LanguageTable* languageTable, Settings* settings, Font* font) {
    //  settings specific data
    //
    //

    settingsState->languageTable = languageTable;
    settingsState->settings = settings;
    settingsState->font = font;
}

void RunSettingsState(SettingsState* settingsState, ProgramState* currentProgramState) {
    while (*currentProgramState == STATE_SETTINGS && !WindowShouldClose()) {
        // Update
        Update(settingsState, currentProgramState);
        // Draw
        OnBeginDrawing();
        Draw(settingsState);
        OnEndDrawing();
    }

    if (WindowShouldClose() && *currentProgramState != STATE_FATAL_ERROR) {
        *currentProgramState = STATE_CLOSE_THE_PROGRAM;
    }
}

static void Update(SettingsState* settingsState, ProgramState* currentProgramState) {
    //  TODO:
    //  scaling mouse position
    Vector2 mousePosScaled;
    ScaleMousePosition(&mousePosScaled);
    //  Events / Input
    //
    //
    //  Update
    //
    //
}

static void Draw(SettingsState *settingsState) {
    //  TODO:
}