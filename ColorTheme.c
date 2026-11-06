#include "ColorTheme.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InitSingleTheme(SingleTheme* singleTheme) {
    mempcpy(singleTheme->type, "single", sizeof(singleTheme->type));
    singleTheme->name = nullptr;
    singleTheme->clr = MAGENTA;
}

void InitButtonTheme(ButtonTheme* buttonTheme) {
    mempcpy(buttonTheme->type, "button", sizeof(buttonTheme->type));
    buttonTheme->name = nullptr;
    buttonTheme->normal = MAGENTA;
    buttonTheme->highlight = MAGENTA;
    buttonTheme->pressed = MAGENTA;
}

void InitColorTheme(ColorTheme* colorTheme) {
    colorTheme->singles = malloc(NUMBER_OF_SINGLETHEMES * sizeof(SingleTheme));
    for (int i = 0; i < NUMBER_OF_SINGLETHEMES; i++) {
        InitSingleTheme(&colorTheme->singles[i]);
    }
    colorTheme->buttons = malloc(NUMBER_OF_BUTTONTHEMES * sizeof(ButtonTheme));
    for (int i = 0; i < NUMBER_OF_BUTTONTHEMES; i++) {
        InitButtonTheme(&colorTheme->buttons[i]);
    }
}

bool LoadColorTheme(ColorTheme* colorTheme, const char* pathName) {
    bool result = true;

    if (colorTheme == nullptr || pathName == nullptr) {
        result = false;
    }
    else {
        FILE* file = fopen(pathName, "r");
        if (file == nullptr) {
            result = false;
        }
        else {
            char buffer[64] = "";
            int singleIndex = 0, buttonsIndex = 0;

            for (int i = 0; (i < NUMBER_OF_SINGLETHEMES + NUMBER_OF_BUTTONTHEMES) && result; i++) {
                if (fgets(buffer, sizeof(buffer), file) == nullptr) {
                    result = false;
                }
                else {
                    buffer[strcspn(buffer, "\n")] = '\0';
                    if (strcmp(buffer, "single") == 0) {
                        buffer[0] = '\0';
                        if (fgets(buffer, sizeof(buffer), file) == nullptr) {
                            result = false;
                        }
                        else {
                            buffer[strcspn(buffer, "\n")] = '\0';
                            if (colorTheme->singles[singleIndex].name != nullptr) {
                                free(colorTheme->singles[singleIndex].name);
                            }
                            colorTheme->singles[singleIndex].name = malloc((strlen(buffer) + 1) * sizeof(buffer[0]));
                            strcpy(colorTheme->singles[singleIndex].name, buffer);
                            fscanf(file, "%d%d%d%d",
                                &colorTheme->singles[singleIndex].clr.r,
                                &colorTheme->singles[singleIndex].clr.g,
                                &colorTheme->singles[singleIndex].clr.b,
                                &colorTheme->singles[singleIndex].clr.a);
                            singleIndex++;
                            //  skip new line
                            if (fgets(buffer, sizeof(buffer), file) == nullptr) {
                                result = false;
                            }
                            else {
                                buffer[0] = '\0';
                            }
                        }
                    }
                    else if (strcmp(buffer, "button") == 0) {
                        buffer[0] = '\0';
                        if (fgets(buffer, sizeof(buffer), file) == nullptr) {
                            result = false;
                        }
                        else {
                            buffer[strcspn(buffer, "\n")] = '\0';
                            if (colorTheme->buttons[buttonsIndex].name != nullptr) {
                                free(colorTheme->buttons[buttonsIndex].name);
                            }
                            colorTheme->buttons[buttonsIndex].name = malloc((strlen(buffer) + 1) * sizeof(buffer[0]));
                            strcpy(colorTheme->buttons[buttonsIndex].name, buffer);
                            fscanf(file, "%d%d%d%d%d%d%d%d%d%d%d%d",
                                &colorTheme->buttons[buttonsIndex].normal.r,
                                &colorTheme->buttons[buttonsIndex].normal.g,
                                &colorTheme->buttons[buttonsIndex].normal.b,
                                &colorTheme->buttons[buttonsIndex].normal.a,
                                &colorTheme->buttons[buttonsIndex].highlight.r,
                                &colorTheme->buttons[buttonsIndex].highlight.g,
                                &colorTheme->buttons[buttonsIndex].highlight.b,
                                &colorTheme->buttons[buttonsIndex].highlight.a,
                                &colorTheme->buttons[buttonsIndex].pressed.r,
                                &colorTheme->buttons[buttonsIndex].pressed.g,
                                &colorTheme->buttons[buttonsIndex].pressed.b,
                                &colorTheme->buttons[buttonsIndex].pressed.a);
                            buttonsIndex++;
                            //  skip new line
                            if (fgets(buffer, sizeof(buffer), file) == nullptr) {
                                result = false;
                            }
                            else {
                                buffer[0] = '\0';
                            }
                        }
                    }
                }
            }
            fclose(file);
        }
    }
    return result;
}
SingleTheme* GetSingleTheme(ColorTheme* colorTheme, char* name) {
    SingleTheme* result = nullptr;
    if (colorTheme != nullptr && colorTheme->singles != nullptr) {
        for (int i = 0; i < NUMBER_OF_SINGLETHEMES; i++) {
            if (strcmp(colorTheme->singles[i].name, name) == 0) {
                result = &colorTheme->singles[i];
                i = NUMBER_OF_SINGLETHEMES;
            }
        }
    }
    return result;
}
ButtonTheme* GetButtonTheme(ColorTheme* colorTheme, char* name) {
    ButtonTheme* result = nullptr;
    if (colorTheme != nullptr && colorTheme->buttons != nullptr) {
        for (int i = 0; i < NUMBER_OF_BUTTONTHEMES; i++) {
            if (strcmp(colorTheme->buttons[i].name, name) == 0) {
                result = &colorTheme->buttons[i];
                i = NUMBER_OF_BUTTONTHEMES;
            }
        }
    }
    return result;
}

void FreeMemoryForColorTheme(ColorTheme* colorTheme) {
    if (colorTheme != nullptr && colorTheme->singles != nullptr && colorTheme->buttons != nullptr) {
        for (int i = 0 ; i < NUMBER_OF_SINGLETHEMES; i++) {
            free(colorTheme->singles[i].name);
            colorTheme->singles[i].name = nullptr;
        }
        free(colorTheme->singles);
        colorTheme->singles = nullptr;

        for (int i = 0 ; i < NUMBER_OF_BUTTONTHEMES; i++) {
            free(colorTheme->buttons[i].name);
            colorTheme->buttons[i].name = nullptr;
        }
        free(colorTheme->buttons);
        colorTheme->buttons = nullptr;
    }
}