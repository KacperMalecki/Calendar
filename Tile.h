#ifndef CALENDAR_TILE_H
#define CALENDAR_TILE_H
#include "raylib.h"
#include "Button.h"
#include "TextField.h"
#include "LanguageTable.h"

typedef struct{
    Rectangle rect;
    Button button;
    TextField dayNr;
    Vector2 textOffset;
    //

}Tile;

void InitTile(Tile *tile, Rectangle rect, Color normal, Color highlighted, Color pressed, Font* font, char* text);
void DrawTile(Tile *tile);
void SetTextOffsetForTile(Tile *tile, Vector2 textOffset);

#endif //CALENDAR_TILE_H
