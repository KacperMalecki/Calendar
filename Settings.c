#include "Settings.h"
#include <stdio.h>
#include <string.h>
#include "raylib.h"

bool LoadSettings(Settings* settings, const char* filePath) {
    bool result = true;
    FILE* file = fopen(filePath, "r");
    if (file == nullptr) {
        result = false;
    }
    else {
        int fullscreen = 0;
        char lang[64] = "", fdw[64] = "", theme[64] = "";
        fscanf(file, "%d%d%d%s%s%s",
            &settings->resolutionWidth,
            &settings->resolutionHeight,
            &fullscreen,
            lang,
            fdw,
            theme);
        settings->fullscreen = (fullscreen == 1 ? 1 : 0);
        //  language
        if (strcmp(lang, "English") == 0)       {settings->language = LANG_ENGLISH;}
        else if (strcmp(lang, "Polish") == 0)   {settings->language = LANG_POLISH;}
        else if (strcmp(lang, "French") == 0)   {settings->language = LANG_FRENCH;}
        //  first day of the week
        if (strcmp(fdw, "Monday") == 0)             {settings->fdw = FDW_MONDAY;}
        else if (strcmp(fdw, "Saturday") == 0)      {settings->fdw = FDW_SATURDAY;}
        else if (strcmp(fdw, "Sunday") == 0)        {settings->fdw = FDW_MONDAY;}
        //  theme
        if (strcmp(theme, "Bright") == 0)       {settings->theme = THEME_BRIGHT;}
        else if (strcmp(theme, "Dark") == 0)    {settings->theme = THEME_DARK;}

        fclose(file);
    }
    return result;
}

bool SaveSettings(Settings* settings,const char* filePath) {
    bool result = true;
    if (!FileExists(filePath)) {
        result = false;
    }
    else {
        FILE* file = fopen(filePath, "w");
        if (file == nullptr) {
            result = false;
        }
        else {
            //  window resolution
            fprintf(file, "%d %d\n", settings->resolutionWidth, settings->resolutionHeight);
            //  fullscreen
            fprintf(file, "%d\n", (settings->fullscreen)?1:0);

            char buffer[256] = "";
            //  language
            LanguageToString(buffer, settings->language);
            fprintf(file, "%s\n", buffer);
            buffer[0] = '\0';
            //  first day of the week
            FDWToString(buffer, settings->fdw);
            fprintf(file, "%s\n", buffer);
            buffer[0] = '\0';
            //  theme
            ThemeToString(buffer, settings->theme);
            fprintf(file, "%s", buffer);

            fclose(file);
        }
    }
    return result;
}
bool GenerateSettingsFile(Settings* settings,const char* filePath) {
    //  Preparing default data for a new file
    settings->resolutionWidth = GetMonitorWidth(0);
    settings->resolutionHeight = GetMonitorHeight(0);
    settings->fullscreen = 1;
    settings->language = LANG_POLISH;
    settings->fdw = FDW_MONDAY;
    settings->theme = THEME_BRIGHT;

    bool result = SaveSettings(settings, filePath);
    return result;
}

void LanguageToString(char* str,Language language) {
    if (str != nullptr) {
        switch (language) {
            case LANG_ENGLISH:  strcpy(str, "English"); break;
            case LANG_POLISH:   strcpy(str, "Polish");  break;
            case LANG_FRENCH:   strcpy(str, "French");  break;
            default: strcpy(str, "Unknown"); break;
        }
    }
}

void ThemeToString(char* str,Theme theme) {
    if (str != nullptr) {
        switch (theme) {
            case THEME_BRIGHT:      strcpy(str, "Bright");  break;
            case THEME_DARK:        strcpy(str, "Dark");    break;
            default:                strcpy(str, "Unknown"); break;
        }
    }
}

void FDWToString(char* str,FirstDayOfTheWeek fdw) {
    if (str != nullptr) {
        switch (fdw) {
            case FDW_MONDAY:    strcpy(str, "Monday");  break;
            case FDW_SATURDAY:  strcpy(str, "Satuday"); break;
            case FDW_SUNDAY:    strcpy(str, "Sunday");  break;
            default:            strcpy(str, "Unknown"); break;
        }
    }
}