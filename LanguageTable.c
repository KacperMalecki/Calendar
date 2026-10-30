#include "LanguageTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InitLanguageUnit(LanguageUnit* languageUnit, const char* key,  const char* value) {
    languageUnit->key = strdup(key);
    languageUnit->value = strdup(value);
}

void InitLanguageTable(LanguageTable* languageTable) {
    InitLanguageUnit(&languageTable->languageUnits[0], "Calendar", "NULL");
    //  days
    InitLanguageUnit(&languageTable->languageUnits[1], "Monday", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[2], "Tuesday", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[3], "Wednesday", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[4], "Thursday", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[5], "Friday", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[6], "Saturday", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[7], "Sunday", "NULL");
    //  months
    InitLanguageUnit(&languageTable->languageUnits[8], "January", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[9], "February", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[10], "March", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[11], "April", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[12], "May", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[13], "June", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[14], "July", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[15], "August", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[16], "September", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[17], "October", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[18], "November", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[19], "December", "NULL");
    //  languages
    InitLanguageUnit(&languageTable->languageUnits[20], "English", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[21], "Polish", "NULL");
    InitLanguageUnit(&languageTable->languageUnits[22], "French", "NULL");
    //
}

LanguageUnit* GetLanguageUnit(LanguageTable* languageTable, const char* key) {
    LanguageUnit* result = nullptr;
    for (int i = 0; i < NUMBER_OF_LANGUAGE_UNITS; i++) {
        if (*(languageTable->languageUnits[i].key) == *key) {
            result = &(languageTable->languageUnits[i]);
            i = NUMBER_OF_LANGUAGE_UNITS;
        }
    }
    return result;
}

bool LoadLanguage(LanguageTable* languageTable, const char* filePath) {
    bool result = true;
    if (languageTable == nullptr || filePath == nullptr) {
        result = false;
    }
    else {
        FILE* file = fopen(filePath, "r");
        if (file == nullptr) {
            result = false;
        }
        else {
            char buffer[256] = "";
            char* found = nullptr;
            int index = 0;

            for (int i = 0; i < NUMBER_OF_LANGUAGE_UNITS && result; i++) {
                found = nullptr;
                index = 0;

                if (fgets(buffer, sizeof(buffer), file) == nullptr) {       /*      is it REALLY safe to use???     */
                    result = false;
                }
                if (fgets(buffer, sizeof(buffer), file) == nullptr) {
                    result = false;
                }
                found = strchr(buffer, '\n');
                if (found == nullptr) {
                    found = strchr(buffer, EOF);
                }
                if (found != nullptr) {
                    index =  (int)(found - buffer);
                    buffer[index] = '\0';
                    free(languageTable->languageUnits[i].value);
                    languageTable->languageUnits[i].value = malloc(sizeof(buffer[0]) * (index + 1));
                    strncpy(languageTable->languageUnits[i].value, buffer, index + 1);
                }
            }
            fclose(file);
        }
    }
    return result;
}