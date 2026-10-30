#include "Calendar.h"

void InitCalendar(Calendar *calendar, LanguageTable *languageTable) {
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

    ReloadLanguage(calendar, languageTable);
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

void ReloadLanguage(Calendar *calendar, LanguageTable *languageTable) {
    //  days of the week
    calendar->dayName[0] = GetLanguageUnit(languageTable, "Monday");
    calendar->dayName[1] = GetLanguageUnit(languageTable, "Tuesday");
    calendar->dayName[2] = GetLanguageUnit(languageTable, "Wednesday");
    calendar->dayName[3] = GetLanguageUnit(languageTable, "Thursday");
    calendar->dayName[4] = GetLanguageUnit(languageTable, "Friday");
    calendar->dayName[5] = GetLanguageUnit(languageTable, "Saturday");
    calendar->dayName[6] = GetLanguageUnit(languageTable, "Sunday");
    //  months
    calendar->monthsName[0] = GetLanguageUnit(languageTable, "January");
    calendar->monthsName[1] = GetLanguageUnit(languageTable, "February");
    calendar->monthsName[2] = GetLanguageUnit(languageTable, "March");
    calendar->monthsName[3] = GetLanguageUnit(languageTable, "April");
    calendar->monthsName[4] = GetLanguageUnit(languageTable, "May");
    calendar->monthsName[5] = GetLanguageUnit(languageTable, "June");
    calendar->monthsName[6] = GetLanguageUnit(languageTable, "July");
    calendar->monthsName[7] = GetLanguageUnit(languageTable, "August");
    calendar->monthsName[8] = GetLanguageUnit(languageTable, "September");
    calendar->monthsName[9] = GetLanguageUnit(languageTable, "October");
    calendar->monthsName[10] = GetLanguageUnit(languageTable, "November");
    calendar->monthsName[11] = GetLanguageUnit(languageTable, "December");
}