#include "TodayDisplay.h"

#include "Date.h"

void InitTodayDisplay(TodayDisplay* tdyDisplay, LanguageTable* languageTable, Font* font) {
    tdyDisplay->year = GetFromToday(DATE_YEAR);
    tdyDisplay->monthLang = GetLanguageUnit(languageTable, MonthNumberToString(GetFromToday(DATE_MONTH)));
    tdyDisplay->dayNr = GetFromToday(DATE_DAY);
    tdyDisplay->dayOfTheWeekLang = GetLanguageUnit(languageTable, DayOfTheWeekToString(GetFromToday(DATE_DAY_NR)));

    //InitTextField(&tdyDisplay->yearText, font, )
}

void UpdateTodayDisplay(TodayDisplay* tdyDisplay) {
}

void DrawTodayDisplay(TodayDisplay* tdyDisplay) {
    DrawTextField(&tdyDisplay->yearText);
    DrawTextFieldLocalized(&tdyDisplay->monthText);
    DrawTextField(&tdyDisplay->dayText);
    DrawTextFieldLocalized(&tdyDisplay->dayOfTheWeekText);
}
