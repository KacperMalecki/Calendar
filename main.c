#include <stdio.h>
#include "raylib.h"
#include "rlgl.h"
#include "Calendar.h"
#include "RaylibExtension.h"

const static int REFERENCE_WIDTH = 1920;
const static int REFERENCE_HEIGHT = 1080;
//  FILE PATHS
const static char* SETTINGS_PATH = "Data/Settings.txt";
const static char* EVENTS_PATH = "Data/Events.txt";
const static char* ICON_PATH = "Images/icon.png";
const static char* FONT_PATH = "Fonts/inconsolata.ttf";

bool LoadData();
void BuildWindow(Vector2 screenSize);
void Draw(Calendar *calendar, Font* font);

int main(void)
{
    //  Window initialization
    Vector2 screenSize = {1280, 720};   //  TODO: REMOVE IT LATER!!!
    BuildWindow(screenSize);

    //  Calendar initialization
    Calendar cal = {{90.f, 200.f}, {240.f, 135.f}, {8.f, 8.f}};
    InitCalendar(&cal);

    //  Load external font
    Font myFont = LoadFontEx(FONT_PATH, 150, 0, 383);
    SetTextureFilter(myFont.texture, TEXTURE_FILTER_TRILINEAR);

    Vector2 screenScale, mousePosScaled;

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

    CloseWindow();
    return 0;
}

bool LoadData() {
    bool result = false;
    //...
    return result;
}

void BuildWindow(Vector2 screenSize) {
    InitWindow(screenSize.x, screenSize.y, "Calendar");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

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