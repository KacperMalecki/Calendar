#include "Tile.h"

void InitTile(Tile *tile, Rectangle rect, Color normal, Color highlighted, Color pressed) {
    tile->rect = rect;
    InitButton(&(tile->button), rect, normal, highlighted, pressed);
}

void DrawTile(Tile *Tile) {
    DrawRectangle(Tile->rect.x, Tile->rect.y, Tile->rect.width, Tile->rect.height, Tile->button.currentClr);
}