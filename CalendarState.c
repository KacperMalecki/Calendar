#include "CalendarState.h"
#include <stdio.h>

extern const char* DARK_THEME_PATH;
extern const char* SETTINGS_TEXTURE_PATH;

static void Update(CalendarState* calendarState, ProgramState* currentProgramState);
static void Draw(CalendarState *calendarState);
void OpenSettings(ProgramState* currentProgramState);
static void UseColorTheme(CalendarState* calendarState, ColorTheme* colorTheme);

void InitCalendarState(CalendarState* calendarState, LanguageTable* languageTable, Settings* settings, ColorTheme* colorTheme, Font* font, char* errorMessage) {
    //  Load texture
    calendarState->settingsTxtr = LoadTexture(SETTINGS_TEXTURE_PATH);      //  TODO: error check
    //  Calendar initialization
    calendarState->calendar = (Calendar){{90.f, 200.f}, {240.f, 135.f}, {8.f, 8.f}};
    calendarState->calendar.textOffsetForWeekNumbers = (Vector2){10,10};

    calendarState->languageTable = languageTable;
    calendarState->settings = settings;
    calendarState->colorTheme = colorTheme;
    calendarState->font = font;
    calendarState->errorMessageDest = errorMessage;
    UseColorTheme(calendarState, colorTheme);

    InitCalendar(&calendarState->calendar, calendarState->languageTable, calendarState->font);
    //  Settings button
    Button* bttn = &calendarState->settingsButton.button;
    InitTextureButton(&calendarState->settingsButton, (Vector2){1846, 10}, bttn->normal, bttn->highlighted, bttn->pressed, &calendarState->settingsTxtr);
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

void UnloadCalendarState(CalendarState* calendarState) {
    UnloadTexture(calendarState->settingsTxtr);
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
    //  UPDATE
    //  Calendar
    UpdateCalendar(&calendarState->calendar, mousePosScaled);
    //  settings button
    UpdateButton(&calendarState->settingsButton.button, mousePosScaled);
    if (WasButtonPressed(&calendarState->settingsButton.button)) {
        *currentProgramState = STATE_SETTINGS;
    }
};

static void Draw(CalendarState *calendarState) {
    DrawCalendar(&calendarState->calendar, calendarState->font);
    DrawTextureButton(&calendarState->settingsButton);
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

static void UseColorTheme(CalendarState* calendarState, ColorTheme* colorTheme) {
    //  calendar - colors
    ButtonTheme* bttnTheme = GetButtonTheme(colorTheme, "CalendarNormalTile");
    SingleTheme* snglTheme = GetSingleTheme(colorTheme, "CalendarOutNormalTile");
    calendarState->calendar.normalDayClr = bttnTheme->normal;
    calendarState->calendar.highlightedDayClr = bttnTheme->highlight;
    calendarState->calendar.pressedDayClr = bttnTheme->pressed;
    calendarState->calendar.normalOutDayClr = snglTheme->clr;
    bttnTheme = GetButtonTheme(colorTheme, "CalendarWeekendTile");
    snglTheme = GetSingleTheme(colorTheme, "CalendarOutWeekendTile");
    calendarState->calendar.weekendDayClr = bttnTheme->normal;
    calendarState->calendar.weekendHighlightedDayClr = bttnTheme->highlight;
    calendarState->calendar.weekendPressedDayClr = bttnTheme->pressed;
    calendarState->calendar.weekendOutDayClr = snglTheme->clr;
    //  settings button - colors
    bttnTheme = GetButtonTheme(colorTheme, "SettingsButton");
    calendarState->settingsButton.button.normal = bttnTheme->normal;
    calendarState->settingsButton.button.highlighted = bttnTheme->highlight;
    calendarState->settingsButton.button.pressed = bttnTheme->pressed;
}