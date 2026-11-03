#include "Tile.h"

void InitTile(Tile *tile, Rectangle rect, Color normal, Color highlighted, Color pressed, Font* font, char* text) {
    tile->rect = rect;
    InitButton(&(tile->button), rect, normal, highlighted, pressed);
    InitTextField(&tile->dayNr, font, text);
    tile->dayNr.setts.color = BLACK;
    tile->dayNr.setts.origin = TEXT_TOPLEFT;
    SetDimensionsForTextField(&tile->dayNr.setts, (Vector2){rect.x, rect.y}, tile->dayNr.setts.size, tile->dayNr.setts.origin);
    tile->textOffset = (Vector2){0,0};
}

void DrawTile(Tile *tile) {
    DrawRectangle(tile->rect.x, tile->rect.y, tile->rect.width, tile->rect.height, tile->button.currentClr);
    DrawTextField(&tile->dayNr);
}

void SetTextOffsetForTile(Tile *tile, Vector2 textOffset) {
    tile->textOffset = textOffset;
    tile->dayNr.setts.position = (Vector2){tile->rect.x + textOffset.x, tile->rect.y + textOffset.y};
}