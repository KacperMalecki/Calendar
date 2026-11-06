#ifndef CALENDAR_SETTINGSSTATE_H
#define CALENDAR_SETTINGSSTATE_H

#include "LanguageTable.h"
#include "ProgramState.h"
#include "raylib.h"
#include "Settings.h"
#include "TextField.h"
#include "TextureButton.h"
#include "ColorTheme.h"
#include "TextFieldButton.h"
#include "ToggleButton.h"

typedef struct{
    //  external data
    LanguageTable* languageTable;
    Settings* settings;
    ColorTheme* colorTheme;
    Font* font;
    char* errorMessageDest;
    Texture2D goBackTxtr;
    //  UI DATA
    Color backgroundColor;                          //  background
    TextFieldLocalized calendarTitle;               //  title text
    Color titleClr;
    TextureButton goBackButton;                     //  go back button
    TextFieldLocalized languageSection;             //  language text
    Color settingsSectionClr;                       //  color for section titles
    TextFieldLocalizedButton languageENbutton;      //  EN button
    TextFieldLocalizedButton languagePLbutton;      //  PL button
    TextFieldLocalizedButton languageFRbutton;      //  FR button
    TextFieldLocalized fullscreenSection;           //  fullscreen text
    ToggleButton fullscreenToggle;                  //  fullscreen toggle
    TextFieldLocalized fdwSection;                  //  fdw text
    TextFieldLocalizedButton fdwSaturdaybutton;     //  fdw Saturday button
    TextFieldLocalizedButton fdwSundaybutton;       //  fdw Sunday button
    TextFieldLocalizedButton fdwMondaybutton;       //  fdw Monday button
    TextFieldLocalized themeSection;                //  theme text
    TextFieldLocalizedButton themeLightButton;      //  light theme button
    TextFieldLocalizedButton themeDarkButton;       //  dark theme button
    TextFieldLocalizedButton quitButton;            //  quit button
    TextFieldLocalizedButton aboutStateButton;      //  about state button
}SettingsState;

void InitSettingsState(SettingsState* settingsState, LanguageTable* languageTable, Settings* settings, ColorTheme* colorTheme, Font* font, char* errorMessage);
void RunSettingsState(SettingsState* settingsState, ProgramState* currentProgramState);
void UnloadSettingsState(SettingsState* settingsState);

#endif //CALENDAR_SETTINGSSTATE_H
