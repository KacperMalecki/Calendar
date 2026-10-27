#include "RaylibExtension.h"

void DrawTextWithOrigin(Font* font, const char* text, Vector2 position, float fontSize, float spacing, Color tint, TextOrigin type) {
    Vector2 textSize = MeasureTextEx(*font, text, fontSize, spacing);
    Vector2 origin = {0.f, 0.f};

    switch (type) {
        case TEXT_CENTER:        origin = (Vector2){0.5f, 0.5f};     break;
        case TEXT_TOP:           origin = (Vector2){0.5f, 0.f};      break;
        case TEXT_BOTTOM:        origin = (Vector2){0.5f, 1.f};      break;
        case TEXT_LEFT:          origin = (Vector2){0.f, 0.5f};      break;
        case TEXT_RIGHT:         origin = (Vector2){1.f, 0.5f};      break;
        case TEXT_TOPLEFT:       origin = (Vector2){0.f, 0.f};       break;
        case TEXT_TOPRIGHT:      origin = (Vector2){1.f, 0.f};       break;
        case TEXT_BOTTOMLEFT:    origin = (Vector2){0.f, 1.f};       break;
        case TEXT_BOTTOMRIGHT:   origin = (Vector2){1.f, 1.f};       break;
    }
    position.x -= (textSize.x * origin.x);
    position.y -= (textSize.y * origin.y);
    DrawTextEx(*font, text, position, fontSize, spacing, tint);
}

void WorldToScreenPosition(Vector2 worldPosition, Vector2* screenPosition, Vector2 worldSize) {
    Vector2 scale = {worldPosition.x / (float)GetScreenWidth(), worldPosition.y / (float)GetScreenHeight()};
    *screenPosition = (Vector2){worldSize.x * scale.x, worldSize.y * scale.y};
}