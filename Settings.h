#ifndef CALENDAR_SETTINGS_H
#define CALENDAR_SETTINGS_H

typedef enum Language {
    LANG_NONE,
    LANG_ENGLISH,
    LANG_POLISH,
    LANG_FRENCH
}Language;

typedef enum Theme {
    THEME_BRIGHT,
    THEME_DARK
}Theme;

typedef enum FirstDayOfTheWeek {
    FDW_MONDAY,
    FDW_SATURDAY,
    FDW_SUNDAY
}FirstDayOfTheWeek;

typedef struct Settings {
    int resolutionWidth;
    int resolutionHeight;
    bool fullscreen;
    Language language;
    Theme theme;
    FirstDayOfTheWeek fdw;
}Settings;

bool LoadSettings(Settings* settings,const char* filePath);
bool SaveSettings(Settings* settings,const char* filePath);
bool GenerateSettingsFile(Settings* settings,const char* filePath);

void LanguageToString(char* str,Language language);
void ThemeToString(char* str,Theme theme);
void FDWToString(char* str,FirstDayOfTheWeek fdw);
#endif //CALENDAR_SETTINGS_H
