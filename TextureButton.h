#ifndef CALENDAR_TEXTUREBUTTON_H
#define CALENDAR_TEXTUREBUTTON_H
#include "Button.h"
#include "raylib.h"
#include "TextField.h"

typedef struct{
    Vector2 position;
    Button button;
    Texture2D* txtr;

}TextureButton;

void InitTextureButton(TextureButton *bttn, Vector2 position, Color normal, Color highlighted, Color pressed, Texture2D* txtr);
void DrawTextureButton(TextureButton *bttn);

#endif //CALENDAR_TEXTUREBUTTON_H
