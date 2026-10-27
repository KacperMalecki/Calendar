#include "Settings.h"

#include <stdio.h>

#include "raylib.h"
#include <uchar.h>

bool LoadSettings(Settings* settings, const char* filePath) {
    bool result = true;
    if (!FileExists(filePath))
        result = false;
    else {
        FILE* file = fopen(filePath, "r");
        if (file == NULL) {
            /*
             *  ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR
             */
            result = false;
        }
        else {
            int fullscreen;
            fscanf(file, "%d %d %d",
                &settings->resolutionWidth,
                &settings->resolutionHeight,
                &fullscreen);
            settings->fullscreen = (fullscreen != 0) ? true : false;
        }
    }
    return result;
}

bool SaveSettings(Settings* settings,const char* filePath) {
    return true;
}
bool GenerateSettingsFile(Settings* settings,const char* filePath) {
    return true;
}