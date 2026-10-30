#ifndef CALENDAR_LANGUAGETABLE_H
#define CALENDAR_LANGUAGETABLE_H

#define NUMBER_OF_LANGUAGE_UNITS 23

typedef struct LanguageUnit {
    char* key;
    char* value;
}LanguageUnit;

typedef struct LanguageTable {
    LanguageUnit languageUnits[NUMBER_OF_LANGUAGE_UNITS];

}LanguageTable;

void InitLanguageTable(LanguageTable* languageTable);
LanguageUnit* GetLanguageUnit(LanguageTable* languageTable, const char* key);
bool LoadLanguage(LanguageTable* languageTable, const char* filePath);

#endif //CALENDAR_LANGUAGETABLE_H
