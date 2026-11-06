#include "ProgramState.h"

const int REFERENCE_WIDTH = 1920;
const int REFERENCE_HEIGHT = 1080;
//  FILE PATHS
const char* SETTINGS_PATH = "Data/Settings.txt";
const char* EVENTS_PATH = "Data/Events.txt";
const char* ICON_PATH = "Images/icon.png";
const char* FONT_PATH = "Fonts/inconsolata.ttf";
const char* LANG_EN_PATH = "Lang/Lang-EN.txt";
const char* LANG_PL_PATH = "Lang/Lang-PL.txt";
const char* LANG_FR_PATH = "Lang/Lang-FR.txt";
const char* LIGHT_THEME_PATH = "Themes/LightTheme.txt";
const char* DARK_THEME_PATH = "Themes/DarkTheme.txt";
const char* SETTINGS_TEXTURE_PATH = "Images/SettingsTexture.png";
const char* GOBACK_TEXTURE_PATH = "Images/GoBackTexture.png";

int main(void)
{
    ProgramLoop();
    return 0;
}