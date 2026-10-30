#include <stdio.h>
#include "raylib.h"
#include "rlgl.h"
#include "Calendar.h"
#include "LanguageTable.h"
#include "RaylibExtension.h"
#include "Settings.h"

const static int REFERENCE_WIDTH = 1920;
const static int REFERENCE_HEIGHT = 1080;
//  FILE PATHS
const static char* SETTINGS_PATH = "Data/Settings.txt";
const static char* EVENTS_PATH = "Data/Events.txt";
const static char* ICON_PATH = "Images/icon.png";
const static char* FONT_PATH = "Fonts/inconsolata.ttf";
const static char* LANG_EN_PATH = "Lang/Lang-EN.txt";
const static char* LANG_PL_PATH = "Lang/Lang-PL.txt";
const static char* LANG_FR_PATH = "Lang/Lang-FR.txt";


bool LoadData(Settings *settings, LanguageTable* languageTable);    //  TODO - there will be themes and events to load
bool SaveData(Settings *settings);                                  //  TODO - save settings and events
void BuildWindow(Vector2 screenSize, bool fullscreen);
void Draw(Calendar *calendar, Font* font);

int main(void)
{
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

    //  Calendar initialization
    Calendar cal = {{90.f, 200.f}, {240.f, 135.f}, {8.f, 8.f}};
    InitCalendar(&cal, &languageTable);

    Vector2 screenScale, mousePosScaled;

    //  Main Loop
    while (!WindowShouldClose())
    {
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
        //...
    }

    UnloadFont(myFont);

    SaveData(&settings);

    CloseWindow();
    return 0;
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
    Image icon = LoadImage(ICON_PATH);
    SetWindowIcon(icon);
    UnloadImage(icon);
    SetTargetFPS(60);
}

void Draw(Calendar *calendar, Font* font) {
    DrawCalendar(calendar);

    //
    //  TESTING AREA BELOW
    //          vvv
    DrawText("TEST TEST test test!!! 1: 2: 3: 4: 5:!", 400, 360, 30, RED);
    DrawText("Küche", 200, 40, 30, RED);
    char sentence[] = "Żółty płomień";
    DrawTextEx( *font, "oseŹ\nDrabina", (Vector2){0, 0}, 40, 1, BLACK);
    DrawTextEx( *font, "Żółć źłbie ęńś", (Vector2){400, 50}, 60, 1, BLACK);
    DrawTextEx( *font, sentence, (Vector2){400, 100}, 12, 1, BLACK);
    DrawTextEx(*font, "J’aimerais déguster du fromage accompagné d’un verre de vin de très grande qualité.",
        (Vector2){1920, 0}, 30, 1, PURPLE);
    DrawTextWithOrigin(font, "J’aimerais déguster du fromage accompagné d’un verre de vin de très grande qualité.",
        (Vector2){1920, 0}, 30, 1, PURPLE, TEXT_RIGHT);
    unsigned int dec = 0;
    sscanf("105", "%x", &dec);
    DrawTextCodepoint(*font, 255, (Vector2){100.f, 40.f}, 50, RED);
}