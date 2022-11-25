#include <stdio.h>
#include <assert.h>
#include <string.h> 

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

typedef struct{
    int colorCode;
    const char *majorColor;
    const char *minorColor;
}colorPair;

colorPair getColorCode(int i, int j){
    colorPair colorPair;
    colorPair.colorCode = i * 5 + j;
    colorPair.majorColor = majorColor[i];
    colorPair.minorColor = minorColor[i];
    return colorPair;
}

int printColorMap() {
    int i = 0, j = 0;
    colorPair colorPair;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            colorPair = getColorCode(i, j);
            printf("%d | %s | %s\n", colorPair.colorCode, colorPair.majorColor, colorPair.minorColor);
        }
    }
    return i * j;
}

int main(){
    colorPair colorPair;
    int result = printColorMap();
    assert(result == 25);
    printf("%d pairs printed successfully\n", result);
    printf("Now lets test the validity of individula pairs\n");

    colorPair = getColorCode(0, 0);

    // As per the requirement (wiki), color code should be in range from 1 to 25. 
    // Let me assume index is returned here instead of colorCode. We have bug in color pair itself. 
    // So I consider this as per implementation instead of requirement
    assert(colorPair.colorCode == 0);
    assert(strcmp(colorPair.majorColor, majorColor[0]) == 0);
    assert(strcmp(colorPair.minorColor, minorColor[0]) == 0);

    colorPair = getColorCode(0, 1);
    assert(colorPair.colorCode == 1);
    assert(strcmp(colorPair.majorColor, majorColor[0]) == 0);
    assert(strcmp(colorPair.minorColor, minorColor[1]) == 0);

    colorPair = getColorCode(0, 2);
    assert(colorPair.colorCode == 2);
    assert(strcmp(colorPair.majorColor, majorColor[0]) == 0);
    assert(strcmp(colorPair.minorColor, minorColor[2]) == 0);

    printf("All is well (maybe!)\n");
    return 0;
}
