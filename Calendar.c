#include "Calendar.h"
#include "raylib.h"

void InitCalendar(Calendar *calendar, LanguageTable *languageTable, Font* font) {
    Vector2 tileSize = calendar->tileSize;
    Vector2 calPos = calendar->position;
    Vector2 spacing = calendar->spacing;

    Color highlight = PINK, pressed = PINK;                     //  TODO - read actual colors!!!!!!!!!!!!!!!!
    ChangeColorByDelta(&highlight, calendar->highlightDelta);
    ChangeColorByDelta(&pressed, calendar->pressedDelta);
    float fontSize = 50.f;                                      //TESTESTSETSETSETSETSETSETSETSETSET

    calendar->font = font;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            //InitButton(&(calendar->tiles[i][j].button), (Rectangle){},
            InitTile(&calendar->tiles[i][j], (Rectangle){calPos.x + (float)j * tileSize.x + (float)j *spacing.x,
            calPos.y + (float)i * tileSize.y + (float)i *spacing.y,
            tileSize.x, tileSize.y}, PINK, highlight, pressed, font, "31.");
            calendar->tiles[i][j].dayNr.setts.size = fontSize;
            SetTextOffsetForTile(&calendar->tiles[i][j], calendar->textOffsetForWeekNumbers);
                //(Color){150,150,150,255}, (Color){120,120,120,255}, (Color){90,90,90,255}); //  TEST TEST TEST
            /*if ((i + j) % 2 == 0) {                     //  TEST TEST TEST TEST TEST TEST
                calendar->tiles[i][j].color = RED;      //  TEST TEST TEST TEST TEST TEST
            }
            else
                calendar->tiles[i][j].color = BLUE;*/     //  TEST TEST TEST TEST TEST TEST
        }
    }

    ReloadLanguage(calendar, languageTable);
}

void DrawCalendar(Calendar *calendar, Font* font) {
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