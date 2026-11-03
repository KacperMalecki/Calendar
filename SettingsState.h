#ifndef CALENDAR_SETTINGSSTATE_H
#define CALENDAR_SETTINGSSTATE_H

#include "LanguageTable.h"
#include "ProgramState.h"
#include "raylib.h"
#include "Settings.h"

typedef struct SettingsState {
    //  settings window specific data
    //
    //
    LanguageTable* languageTable;
    Settings* settings;
    Font* font;
}SettingsState;

void InitSettingsState(SettingsState* settingsState, LanguageTable* languageTable, Settings* settings, Font* font);
void RunSettingsState(SettingsState* settingsState, ProgramState* currentProgramState);

#endif //CALENDAR_SETTINGSSTATE_H
