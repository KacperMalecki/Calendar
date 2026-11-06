#ifndef CALENDAR_ABOUTTHEPROGRAMSTATE_H
#define CALENDAR_ABOUTTHEPROGRAMSTATE_H

#include "ColorTheme.h"
#include "LanguageTable.h"
#include "ProgramState.h"
#include "Settings.h"

typedef struct{
    //  external data
    LanguageTable* languageTable;
    Settings* settings;
    ColorTheme* colorTheme;
    Font* font;
    char* errorMessageDest;
    Texture2D goBackTxtr;
    //  ui data
    //
    //
    //  TODO:
}AboutTheProgramState;

void InitAboutTheProgramState(AboutTheProgramState* aboutTheProgramState, LanguageTable* languageTable, Settings* settings, ColorTheme* colorTheme, Font* font, char* errorMessage);
void RunAboutTheProgramState(AboutTheProgramState* aboutTheProgramState, ProgramState* currentProgramState);
void UnloadAboutTheProgramState(AboutTheProgramState* aboutTheProgramState);

#endif //CALENDAR_ABOUTTHEPROGRAMSTATE_H
