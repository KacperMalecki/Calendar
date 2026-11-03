#include "Utilities.h"
#include <stdio.h>

void ClearTheBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int ClampInt(int value, int min, int max) {
    if (value < min) {value = min;}
    if (value > max) {value = max;}
    return value;
}