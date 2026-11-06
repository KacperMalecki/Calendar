#include "TextureButton.h"

void InitTextureButton(TextureButton *bttn, Vector2 position, Color normal, Color highlighted, Color pressed, Texture2D* txtr) {
    Rectangle rect = {position.x, position.y, (float)txtr->width, (float)txtr->height};
    bttn->position = position;
    bttn->txtr = txtr;
    InitButton(&(bttn->button), rect, normal, highlighted, pressed);
}

void DrawTextureButton(TextureButton *bttn) {
    DrawTexture(*bttn->txtr, bttn->position.x, bttn->position.y, bttn->button.currentClr);
}