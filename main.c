#include "raylib.h"

int main(void)
{
    Vector2 screenSize = {1280, 720};

    InitWindow(screenSize.x, screenSize.y, "Calendar");

    Image icon = LoadImage("images/icon.png");
    SetWindowIcon(icon);
    UnloadImage(icon);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);

        DrawText("TEST TEST test test!!! 1: 2: 3: 4: 5:!", 400, 360, 30, RED);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}