#include "ProgramState.h"

#include "CalendarState.h"
#include "LanguageTable.h"
#include "Settings.h"
#include "raylib.h"
#include "rlgl.h"
#include "SettingsState.h"

extern const int REFERENCE_WIDTH;
extern const int REFERENCE_HEIGHT;
extern const char* SETTINGS_PATH;
extern const char* EVENTS_PATH;
extern const char* ICON_PATH;
extern const char* FONT_PATH;
extern const char* LANG_EN_PATH;
extern const char* LANG_PL_PATH;
extern const char* LANG_FR_PATH;

bool LoadData(Settings *settings, LanguageTable* languageTable);    //  TODO - there will be themes and events to load
bool SaveData(Settings *settings);                                  //  TODO - save settings and events
void BuildWindow(Vector2 screenSize, bool fullscreen);
void LoopThroughState(ProgramState* currentState, ProgramState loadedState);

void ProgramLoop() {
    //  load data

    bool error = false;
    char errorMssg[256] = "";

    //  Load the most of data - excluding font, which has to be loaded AFTER the window is initialized
    Settings settings;
    LanguageTable languageTable;
    InitLanguageTable(&languageTable);

    LoadData(&settings, &languageTable);

    //  Load events
    /*
     *  TODO
     *
     */
    LanguageUnit *unit = GetLanguageUnit(&languageTable, "Monday");//   TEST TEST TEST TEST TEST ^^^^^^^^

    //  Window initialization
    BuildWindow((Vector2){(float)settings.resolutionWidth, (float)settings.resolutionHeight}, settings.fullscreen);

    //  Load external font
    Font myFont = LoadFontEx(FONT_PATH, 150, 0, 383);
    SetTextureFilter(myFont.texture, TEXTURE_FILTER_TRILINEAR);

    //  start the program
    ProgramState currentState = STATE_CALENDAR;

    //  state loop
    while (currentState != STATE_CLOSE_THE_PROGRAM && currentState != STATE_FATAL_ERROR && !WindowShouldClose()) {
        switch (currentState) {
            case STATE_CALENDAR:
                CalendarState sttCal;
                InitCalendarState(&sttCal, &languageTable, &settings, &myFont);
                RunCalendarState(&sttCal, &currentState);
                break;
            case STATE_EVENTS_LIST:
                //  TODO:
                break;
            case STATE_SETTINGS:
                //  TODO:
                SettingsState sttSet;
                InitSettingsState(&sttSet, &languageTable, &settings, &myFont);
                RunSettingsState(&sttSet, &currentState);
                break;
            case STATE_ABOUT_THE_PROGRAM:
                //  TODO:
                break;
            default:
                currentState = STATE_CLOSE_THE_PROGRAM;
                break;
        }

    }

    //  save data and close the program
    if (currentState == STATE_CLOSE_THE_PROGRAM) {
        //  run state
        SaveData(&settings);

    }
    //  resize the window and show error message
    else if (currentState == STATE_FATAL_ERROR) {
        //  run state
    }
    //  resize the window and show error message - "invalid program state"
    else {
        //  run state
    }

    UnloadFont(myFont);
    CloseWindow();
}

void OnBeginDrawing() {
    Vector2 screenScale = (Vector2){(float)GetScreenWidth() / (float)REFERENCE_WIDTH, (float)GetScreenHeight() / (float)REFERENCE_HEIGHT};
    //  Drawing
    BeginDrawing();
    ClearBackground(WHITE);
    //  Screen scaling
    rlPushMatrix();
    rlScalef( screenScale.x, screenScale.y, 1.0f);
}

void OnEndDrawing() {
    rlPopMatrix();
    EndDrawing();
}

void ScaleMousePosition(Vector2* mousePosScaled) {
    WorldToScreenPosition(GetMousePosition(), mousePosScaled, (Vector2){REFERENCE_WIDTH, REFERENCE_HEIGHT});
}

bool LoadData(Settings *settings, LanguageTable* languageTable) {
    bool result = true;
    //  char errorMssg[256] = "";           TODO - Pass an error message and show it to the user!!!!!!!!!
    //  Settings
    if (!LoadSettings(settings, SETTINGS_PATH)) {
        if (FileExists(SETTINGS_PATH)) {
            /*
             *  Corrupted "settings.txt" file!  TODO
             *  ERROR - HANDLE IT IN SOME WAY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
             */
            result = false;
        }
        else if (!GenerateSettingsFile(settings, SETTINGS_PATH)) {
            /*
             *  The program could not generate a new settings file!     TODO
             *  ERROR - HANDLE IT IN SOME WAY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
             */
            result = false;
        }
    }
    //  Language table
    switch (settings->language) {
        case LANG_ENGLISH:
            if (!LoadLanguage(languageTable, LANG_EN_PATH)) {
                /*
                *  Corrupted "Lang-EN.txt" file!  TODO
                *  ERROR - HANDLE IT IN SOME WAY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                */
                result = false;
            }
            break;
        case LANG_POLISH:
            if (!LoadLanguage(languageTable, LANG_PL_PATH)) {
                /*
                *  Corrupted "Lang-PL.txt" file!  TODO
                *  ERROR - HANDLE IT IN SOME WAY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                */
                result = false;
            }
            break;
        case LANG_FRENCH:
            if (!LoadLanguage(languageTable, LANG_FR_PATH)) {
                /*
                *  Corrupted "Lang-FR.txt" file!  TODO
                *  ERROR - HANDLE IT IN SOME WAY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                */
                result = false;
            }
            break;
        default:
            /*
                *  No language file found!  TODO
                *  ERROR - HANDLE IT IN SOME WAY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                */
            result = false;
            break;
    }
    return result;
}

bool SaveData(Settings *settings) {
    bool result = true;
    //  Save settings
    settings->resolutionWidth = GetScreenWidth();
    settings->resolutionHeight = GetScreenHeight();
    settings->fullscreen = IsWindowFullscreen();

    if (!SaveSettings(settings, SETTINGS_PATH)) {
        /*
        *  The program could not save changes to "Settings.txt"! Some data might be lost!
        *  ERROR - HANDLE IT IN SOME WAY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        */
        result = false;
    }
    //  Save events
    //if (!SaveEvents(events, EVENTS_PATH)) {
    //    /*
    //    *  The program could not save changes to "Events.txt"! Some data might be lost!
    //    *  ERROR - HANDLE IT IN SOME WAY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //    */
    //    result = false;
    //}
    return result;
}

void BuildWindow(Vector2 screenSize, bool fullscreen) {
    InitWindow(screenSize.x, screenSize.y, "Calendar");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    if (fullscreen == 1) {
        ToggleFullscreen();
    }
    else {
        SetWindowPosition(GetMonitorWidth(0) / 2 - (int)(screenSize.x / 2.f), (int)((float)GetMonitorHeight(0) * .51f) - (int)(screenSize.y / 2.f));
    }
    Image icon = LoadImage(ICON_PATH);
    SetWindowIcon(icon);
    UnloadImage(icon);
    SetTargetFPS(60);
}

void LoopThroughState(ProgramState* currentState, ProgramState loadedState) {
    Vector2 screenScale, mousePosScaled;

    /*while (*currentState == loadedState) {
        screenScale = (Vector2){(float)GetScreenWidth() / (float)REFERENCE_WIDTH, (float)GetScreenHeight() / (float)REFERENCE_HEIGHT};

        //  Drawing
        BeginDrawing();
        ClearBackground(WHITE);
        //  Screen scaling
        rlPushMatrix();
        rlScalef( screenScale.x, screenScale.y, 1.0f);
        Draw(&cal, &myFont);
        DrawTextWithOrigin(&myFont, unit->value, (Vector2){1920, 50}, 30, 1, PURPLE, TEXT_RIGHT);   //  TEST TEST
        rlPopMatrix();
        EndDrawing();

        //  Events / Input
        if (IsKeyReleased(KEY_SPACE)) {
            ToggleFullscreen();
        }

        //  Update
        WorldToScreenPosition(GetMousePosition(), &mousePosScaled, (Vector2){REFERENCE_WIDTH, REFERENCE_HEIGHT});

        UpdateCalendar(&cal, mousePosScaled);
    }*/
}
