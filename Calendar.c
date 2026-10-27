#include "Calendar.h"

void InitCalendar(Calendar *calendar) {
    Vector2 tileSize = calendar->tileSize;
    Vector2 calPos = calendar->position;
    Vector2 spacing = calendar->spacing;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            InitButton(&(calendar->tiles[i][j].button), (Rectangle){},
                (Color){150,150,150,255}, (Color){120,120,120,255}, (Color){90,90,90,255}); //  TEST TEST TEST
            /*if ((i + j) % 2 == 0) {                     //  TEST TEST TEST TEST TEST TEST
                calendar->tiles[i][j].color = RED;      //  TEST TEST TEST TEST TEST TEST
            }
            else
                calendar->tiles[i][j].color = BLUE;*/     //  TEST TEST TEST TEST TEST TEST
            calendar->tiles[i][j].rect.x = calPos.x + (float)j * tileSize.x + (float)j *spacing.x;
            calendar->tiles[i][j].rect.y = calPos.y + (float)i * tileSize.y + (float)i *spacing.y;
            calendar->tiles[i][j].rect.width = tileSize.x;
            calendar->tiles[i][j].rect.height = tileSize.y;

            calendar->tiles[i][j].button.rect = calendar->tiles[i][j].rect;
        }
    }
}

void DrawCalendar(Calendar *calendar) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            DrawTile(&calendar->tiles[i][j]);
        }
    }
}

void UpdateCalendar(Calendar *calendar, Vector2 mousePosition) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            UpdateButton(&(calendar->tiles[i][j].button), mousePosition);
        }
    }
}