#include "Utilities.h"
#include <stdio.h>

void ClearTheBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
