#ifndef CALENDAR_TILE_H
#define CALENDAR_TILE_H
#include "raylib.h"
#include "Button.h"

typedef struct Tile {
    Rectangle rect;
    Button button;
    //

}Tile;

void InitTile(Tile *tile, Rectangle rect, Color normal, Color highlighted, Color pressed);
void DrawTile(Tile *Tile);

#endif //CALENDAR_TILE_H
