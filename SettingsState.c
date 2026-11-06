#include "SettingsState.h"

extern const char* GOBACK_TEXTURE_PATH;
extern const char* LANG_EN_PATH;
extern const char* LANG_PL_PATH;
extern const char* LANG_FR_PATH;
extern const char* LIGHT_THEME_PATH;
extern const char* DARK_THEME_PATH;

static void Update(SettingsState* settingsState, ProgramState* currentProgramState);
static void Draw(SettingsState *settingsState);
static void UseColorTheme(SettingsState* settingsState, ColorTheme* colorTheme);

void InitSettingsState(SettingsState* settingsState, LanguageTable* languageTable, Settings* settings, ColorTheme* colorTheme, Font* font, char* errorMessage) {
    settingsState->languageTable = languageTable;
    settingsState->settings = settings;
    settingsState->font = font;
    settingsState->errorMessageDest = errorMessage;
    settingsState->colorTheme = colorTheme;

    settingsState->goBackTxtr = LoadTexture(GOBACK_TEXTURE_PATH);
    UseColorTheme(settingsState, colorTheme);
    //  title
    InitTextFieldLocalized(&settingsState->calendarTitle, font, GetLanguageUnit(languageTable, "Calendar"));
    SetDimensionsForTextField(&settingsState->calendarTitle.setts, (Vector2){960, 25}, 130, TEXT_TOP);
    settingsState->calendarTitle.setts.color = settingsState->titleClr;
    //  Go Back Button
    Button* bttn = &settingsState->goBackButton.button;
    InitTextureButton(&settingsState->goBackButton, (Vector2){1846, 20}, bttn->normal, bttn->highlighted, bttn->pressed, &settingsState->goBackTxtr);
    //  language section text
    InitTextFieldLocalized(&settingsState->languageSection, font, GetLanguageUnit(languageTable, "Language"));
    SetDimensionsForTextField(&settingsState->languageSection.setts, (Vector2){150, 250}, 50, TEXT_LEFT);
    settingsState->languageSection.setts.color = settingsState->settingsSectionClr;
    //  language EN button
    bttn = &settingsState->languageENbutton.button;
    InitTextFieldLocalizedButton(&settingsState->languageENbutton, font, GetLanguageUnit(languageTable, "English"), 50, (Rectangle){600, 247, 400, 90}, bttn->normal, bttn->highlighted, bttn->pressed);
    //  language PL button
    bttn = &settingsState->languagePLbutton.button;
    InitTextFieldLocalizedButton(&settingsState->languagePLbutton, font, GetLanguageUnit(languageTable, "Polish"), 50, (Rectangle){1050, 247, 400, 90}, bttn->normal, bttn->highlighted, bttn->pressed);
    //  language FR button
    bttn = &settingsState->languageFRbutton.button;
    InitTextFieldLocalizedButton(&settingsState->languageFRbutton, font, GetLanguageUnit(languageTable, "French"), 50, (Rectangle){1500, 247, 400, 90}, bttn->normal, bttn->highlighted, bttn->pressed);
    //  fullscreen section text
    InitTextFieldLocalized(&settingsState->fullscreenSection, font, GetLanguageUnit(languageTable, "Fullscreen"));
    SetDimensionsForTextField(&settingsState->fullscreenSection.setts, (Vector2){150, 450}, 50, TEXT_LEFT);
    settingsState->fullscreenSection.setts.color = settingsState->settingsSectionClr;
    //  fullscreen toggle
    bttn = &settingsState->fullscreenToggle.button;
    InitToggleButton(&settingsState->fullscreenToggle, (Rectangle){600, 397, 150, 80}, bttn->normal, bttn->highlighted, bttn->pressed, settingsState->fullscreenToggle.backgroundColor, settingsState->fullscreenToggle.fillColor, settings->fullscreen);
    //  fdw section text
    InitTextFieldLocalized(&settingsState->fdwSection, font, GetLanguageUnit(languageTable, "FDW"));
    SetDimensionsForTextField(&settingsState->fdwSection.setts, (Vector2){150, 550}, 50, TEXT_LEFT);
    settingsState->fdwSection.setts.color = settingsState->settingsSectionClr;
    //  fdw Saturday button
    bttn = &settingsState->fdwSaturdaybutton.button;
    InitTextFieldLocalizedButton(&settingsState->fdwSaturdaybutton, font, GetLanguageUnit(languageTable, "Saturday"), 50, (Rectangle){600, 697, 400, 90}, bttn->normal, bttn->highlighted, bttn->pressed);
    //  fdw Sunday button
    bttn = &settingsState->fdwSundaybutton.button;
    InitTextFieldLocalizedButton(&settingsState->fdwSundaybutton, font, GetLanguageUnit(languageTable, "Sunday"), 50, (Rectangle){1050, 697, 400, 90}, bttn->normal, bttn->highlighted, bttn->pressed);
    //  fdw Monday button
    bttn = &settingsState->fdwMondaybutton.button;
    InitTextFieldLocalizedButton(&settingsState->fdwMondaybutton, font, GetLanguageUnit(languageTable, "Monday"), 50, (Rectangle){1500, 697, 400, 90}, bttn->normal, bttn->highlighted, bttn->pressed);
    //  theme section text
    InitTextFieldLocalized(&settingsState->themeSection, font, GetLanguageUnit(languageTable, "Theme"));
    SetDimensionsForTextField(&settingsState->themeSection.setts, (Vector2){150, 750}, 50, TEXT_LEFT);
    settingsState->themeSection.setts.color = settingsState->settingsSectionClr;
    //  light theme button
    bttn = &settingsState->themeLightButton.button;
    InitTextFieldLocalizedButton(&settingsState->themeLightButton, font, GetLanguageUnit(languageTable, "Light"), 50, (Rectangle){600, 847, 400, 90}, bttn->normal, bttn->highlighted, bttn->pressed);
    //  dark theme button
    bttn = &settingsState->themeDarkButton.button;
    InitTextFieldLocalizedButton(&settingsState->themeDarkButton, font, GetLanguageUnit(languageTable, "Dark"), 50, (Rectangle){1050, 847, 400, 90}, bttn->normal, bttn->highlighted, bttn->pressed);
    //  Quit button
    bttn = &settingsState->quitButton.button;
    InitTextFieldLocalizedButton(&settingsState->quitButton, font, GetLanguageUnit(languageTable, "ExitToDesktop"), 50, (Rectangle){200, 950, 600, 90}, bttn->normal, bttn->highlighted, bttn->pressed);
    //  About button
    bttn = &settingsState->aboutStateButton.button;
    InitTextFieldLocalizedButton(&settingsState->aboutStateButton, font, GetLanguageUnit(languageTable, "AboutTheProgram"), 50, (Rectangle){900, 950, 600, 90}, bttn->normal, bttn->highlighted, bttn->pressed);
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

void UnloadSettingsState(SettingsState* settingsState) {
    UnloadTexture(settingsState->goBackTxtr);
}

static void Update(SettingsState* settingsState, ProgramState* currentProgramState) {
    //  TODO:
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
    //  UPDATE
    //  go back button
    UpdateButton(&settingsState->goBackButton.button, mousePosScaled);
    if (WasButtonPressed(&settingsState->goBackButton.button)) {
        *currentProgramState = STATE_CALENDAR;
    }
    //  language EN button
    UpdateButton(&settingsState->languageENbutton.button, mousePosScaled);
    if (WasButtonPressed(&settingsState->languageENbutton.button) && settingsState->settings->language != LANG_ENGLISH) {
        //  TODO: change lang to EN
        settingsState->settings->language = LANG_ENGLISH;
        LoadLanguage(settingsState->languageTable, LANG_EN_PATH);
        SetWindowTitle(GetLanguageUnit(settingsState->languageTable, "Calendar")->value);
    }
    //  language PL button
    UpdateButton(&settingsState->languagePLbutton.button, mousePosScaled);
    if (WasButtonPressed(&settingsState->languagePLbutton.button) && settingsState->settings->language != LANG_POLISH) {
        //  TODO: change lang to PL
        settingsState->settings->language = LANG_POLISH;
        LoadLanguage(settingsState->languageTable, LANG_PL_PATH);
        SetWindowTitle(GetLanguageUnit(settingsState->languageTable, "Calendar")->value);
    }
    //  language FR button
    UpdateButton(&settingsState->languageFRbutton.button, mousePosScaled);
    if (WasButtonPressed(&settingsState->languageFRbutton.button) && settingsState->settings->language != LANG_FRENCH) {
        //  TODO: change lang to FR
        settingsState->settings->language = LANG_FRENCH;
        LoadLanguage(settingsState->languageTable, LANG_FR_PATH);
        SetWindowTitle(GetLanguageUnit(settingsState->languageTable, "Calendar")->value);
    }
    //  fullscreen toggle
    UpdateButton(&settingsState->fullscreenToggle.button, mousePosScaled);
    if (WasButtonPressed(&settingsState->fullscreenToggle.button)) {
        UseToggleButton(&settingsState->fullscreenToggle);
        ToggleFullscreen();
        if (!IsWindowFullscreen()) {
            MaximizeWindow();
        }
        settingsState->settings->fullscreen = IsWindowFullscreen();
    }
    //  fdw Saturday button
    UpdateButton(&settingsState->fdwSaturdaybutton.button, mousePosScaled);
    if (WasButtonPressed(&settingsState->fdwSaturdaybutton.button)) {
        //  TODO: change fdw to FDW_SATURDAY
        settingsState->settings->fdw = FDW_SATURDAY;
    }
    //  fdw Sunday button
    UpdateButton(&settingsState->fdwSundaybutton.button, mousePosScaled);
    if (WasButtonPressed(&settingsState->fdwSundaybutton.button)) {
        //  TODO: change fdw to FDW_SUNDAY
        settingsState->settings->fdw = FDW_SUNDAY;
    }
    //  fdw Monday button
    UpdateButton(&settingsState->fdwMondaybutton.button, mousePosScaled);
    if (WasButtonPressed(&settingsState->fdwMondaybutton.button)) {
        //  TODO: change fdw to FDW_MONDAY
        settingsState->settings->fdw = FDW_MONDAY;
    }
    //  light theme button
    UpdateButton(&settingsState->themeLightButton.button, mousePosScaled);
    if (WasButtonPressed(&settingsState->themeLightButton.button) && settingsState->settings->theme != THEME_LIGHT) {
        //  TODO: change color theme to THEME_LIGHT
        settingsState->settings->theme = THEME_LIGHT;
        LoadColorTheme(settingsState->colorTheme, LIGHT_THEME_PATH);
        //
        //
        //
    }
    //  dark theme button
    UpdateButton(&settingsState->themeDarkButton.button, mousePosScaled);
    if (WasButtonPressed(&settingsState->themeDarkButton.button) && settingsState->settings->theme != THEME_DARK) {
        //  TODO: change fdw to FDW_MONDAY
        settingsState->settings->theme = THEME_DARK;
        LoadColorTheme(settingsState->colorTheme, DARK_THEME_PATH);
        //
        //
        //
    }
    //  quit button
    UpdateButton(&settingsState->quitButton.button, mousePosScaled);
    if (WasButtonPressed(&settingsState->quitButton.button)) {
        *currentProgramState = STATE_CLOSE_THE_PROGRAM;
    }
    //  about state button
    UpdateButton(&settingsState->aboutStateButton.button, mousePosScaled);
    if (WasButtonPressed(&settingsState->aboutStateButton.button)) {
        //  TODO: go to ABOUT STATE
        //*currentProgramState = STATE_ABOUT_THE_PROGRAM;       //  TODO:
        //
        //
        //
    }
}

static void Draw(SettingsState *settingsState) {
    //  TODO:
    ClearBackground(settingsState->backgroundColor);                    //  background
    DrawTextFieldLocalized(&settingsState->calendarTitle);              //  title text
    DrawTextureButton(&settingsState->goBackButton);                    //  back button
    DrawTextFieldLocalized(&settingsState->languageSection);            //  language section text
    DrawTextFieldLocalizedButton(&settingsState->languageENbutton);     //  language EN button
    DrawTextFieldLocalizedButton(&settingsState->languagePLbutton);     //  language PL button
    DrawTextFieldLocalizedButton(&settingsState->languageFRbutton);     //  language FR button
    DrawTextFieldLocalized(&settingsState->fullscreenSection);          //  language section text
    DrawTextFieldLocalized(&settingsState->fullscreenSection);          //  fullscreen section text
    DrawToggleButton(&settingsState->fullscreenToggle);                 //  fullscreen toggle
    DrawTextFieldLocalized(&settingsState->fdwSection);                 //  fdw section text
    DrawTextFieldLocalizedButton(&settingsState->fdwSaturdaybutton);    //  fdw Satuday button
    DrawTextFieldLocalizedButton(&settingsState->fdwSundaybutton);      //  fdw Sunday button
    DrawTextFieldLocalizedButton(&settingsState->fdwMondaybutton);      //  fdw Monday button
    DrawTextFieldLocalized(&settingsState->themeSection);               //  theme section text
    DrawTextFieldLocalizedButton(&settingsState->themeLightButton);     //  light theme button
    DrawTextFieldLocalizedButton(&settingsState->themeDarkButton);      //  dark theme button
    DrawTextFieldLocalizedButton(&settingsState->quitButton);           //  quit button
    DrawTextFieldLocalizedButton(&settingsState->aboutStateButton);     //  about state button
}

static void UseColorTheme(SettingsState* settingsState, ColorTheme* colorTheme) {
    //  settings background
    ButtonTheme* bttnTheme = GetButtonTheme(colorTheme, "GoBackButton");
    SingleTheme* snglTheme = GetSingleTheme(colorTheme, "SettingsBackground");
    settingsState->backgroundColor = snglTheme->clr;
    //  go back button
    settingsState->goBackButton.button.normal = bttnTheme->normal;
    settingsState->goBackButton.button.highlighted = bttnTheme->highlight;
    settingsState->goBackButton.button.pressed = bttnTheme->pressed;
    //  title text
    snglTheme = GetSingleTheme(colorTheme, "TitleText");
    settingsState->titleClr = snglTheme->clr;
    //  settings section text
    snglTheme = GetSingleTheme(colorTheme, "SettingsSectionText");
    settingsState->settingsSectionClr = snglTheme->clr;
    //  default button text color
    snglTheme = GetSingleTheme(colorTheme, "DefaultButtonText");
    settingsState->languageENbutton.textFieldLocalized.setts.color = snglTheme->clr;
    //  default button color
    bttnTheme = GetButtonTheme(colorTheme, "DefaultButton");
    //  -   lang buttons
    settingsState->languageENbutton.button.normal = bttnTheme->normal;
    settingsState->languageENbutton.button.highlighted = bttnTheme->highlight;
    settingsState->languageENbutton.button.pressed = bttnTheme->pressed;
    settingsState->languagePLbutton.button.normal = bttnTheme->normal;
    settingsState->languagePLbutton.button.highlighted = bttnTheme->highlight;
    settingsState->languagePLbutton.button.pressed = bttnTheme->pressed;
    settingsState->languageFRbutton.button.normal = bttnTheme->normal;
    settingsState->languageFRbutton.button.highlighted = bttnTheme->highlight;
    settingsState->languageFRbutton.button.pressed = bttnTheme->pressed;
    //  -   fdw buttons
    settingsState->fdwSaturdaybutton.button.normal = bttnTheme->normal;
    settingsState->fdwSaturdaybutton.button.highlighted = bttnTheme->highlight;
    settingsState->fdwSaturdaybutton.button.pressed = bttnTheme->pressed;
    settingsState->fdwSundaybutton.button.normal = bttnTheme->normal;
    settingsState->fdwSundaybutton.button.highlighted = bttnTheme->highlight;
    settingsState->fdwSundaybutton.button.pressed = bttnTheme->pressed;
    settingsState->fdwMondaybutton.button.normal = bttnTheme->normal;
    settingsState->fdwMondaybutton.button.highlighted = bttnTheme->highlight;
    settingsState->fdwMondaybutton.button.pressed = bttnTheme->pressed;
    //  -   theme buttons
    settingsState->themeLightButton.button.normal = bttnTheme->normal;
    settingsState->themeLightButton.button.highlighted = bttnTheme->highlight;
    settingsState->themeLightButton.button.pressed = bttnTheme->pressed;
    settingsState->themeDarkButton.button.normal = bttnTheme->normal;
    settingsState->themeDarkButton.button.highlighted = bttnTheme->highlight;
    settingsState->themeDarkButton.button.pressed = bttnTheme->pressed;
    //  -   state changing buttons
    settingsState->quitButton.button.normal = bttnTheme->normal;
    settingsState->quitButton.button.highlighted = bttnTheme->highlight;
    settingsState->quitButton.button.pressed = bttnTheme->pressed;
    settingsState->aboutStateButton.button.normal = bttnTheme->normal;
    settingsState->aboutStateButton.button.highlighted = bttnTheme->highlight;
    settingsState->aboutStateButton.button.pressed = bttnTheme->pressed;
    //  default toggle color
    bttnTheme = GetButtonTheme(colorTheme, "DefaultToggle");
    settingsState->fullscreenToggle.button.normal = bttnTheme->normal;
    settingsState->fullscreenToggle.button.highlighted = bttnTheme->highlight;
    settingsState->fullscreenToggle.button.pressed = bttnTheme->pressed;
    //  default toggle background
    snglTheme = GetSingleTheme(colorTheme, "DefaultToggleBackground");
    settingsState->fullscreenToggle.backgroundColor = snglTheme->clr;
    //  default toggle fill
    snglTheme = GetSingleTheme(colorTheme, "DefaultToggleFill");
    settingsState->fullscreenToggle.fillColor = snglTheme->clr;
}