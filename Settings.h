#ifndef CALENDAR_SETTINGS_H
#define CALENDAR_SETTINGS_H

typedef struct Settings {
    int resolutionWidth;
    int resolutionHeight;
    bool fullscreen;
    //Language lang;
    //Theme theme;
    //FirstDayOfTheWeek name;
}Settings;

bool LoadSettings(Settings* settings,const char* filePath);
bool SaveSettings(Settings* settings,const char* filePath);
bool GenerateSettingsFile(Settings* settings,const char* filePath);
#endif //CALENDAR_SETTINGS_H
