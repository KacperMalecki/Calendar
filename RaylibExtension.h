#ifndef CALENDAR_RAYLIBEXTENSION_H
#define CALENDAR_RAYLIBEXTENSION_H

#include "raylib.h"

typedef enum TextOrigin {
    TEXT_CENTER,
    TEXT_TOP,
    TEXT_BOTTOM,
    TEXT_LEFT,
    TEXT_RIGHT,
    TEXT_TOPLEFT,
    TEXT_TOPRIGHT,
    TEXT_BOTTOMLEFT,
    TEXT_BOTTOMRIGHT
}TextOrigin;

void DrawTextWithOrigin(Font* font, const char* text, Vector2 position, float fontSize, float spacing, Color tint, TextOrigin type);
void WorldToScreenPosition(Vector2 worldPosition, Vector2* screenPosition, Vector2 worldSize);

#endif //CALENDAR_RAYLIBEXTENSION_H
