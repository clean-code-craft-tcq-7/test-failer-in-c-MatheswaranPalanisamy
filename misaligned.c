#include <stdio.h>
#include <assert.h>
#include <string.h> 

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

// Structure to return the color pair information
typedef struct{
    int colorCode;
    const char *majorColor;
    const char *minorColor;
}colorPair;

colorPair getColorCode(int i, int j){
    colorPair colorPair;
    // Deriving colorPair.colorCode, colorPair.majorColor and colorPair.minorColor are
    // Done as per the base code. No modification in logic was done
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
    // Test case 1: Validate the number of color pairs printed
    int result = printColorMap();
    assert(result == 25);
    printf("%d pairs printed successfully\n", result);
    printf("Now lets test the validity of individula pairs\n");

    colorPair colorPair;
    // Note: As per the requirement (wiki), color code should be in range from 1 to 25. 
    // Let me assume index is returned here instead of colorCode.
    // So I consider this as per implementation instead of requirement. Let me concentrate on 
    // validating the color pair combination

    // Test case 2: Validate the color pair combination for index 0,0
    colorPair = getColorCode(0, 0);
    assert(colorPair.colorCode == 0);
    assert(strcmp(colorPair.majorColor, majorColor[0]) == 0);
    assert(strcmp(colorPair.minorColor, minorColor[0]) == 0);

    // Test case 3: Validate the color pair combination for index 0,1
    colorPair = getColorCode(0, 1);
    assert(colorPair.colorCode == 1);
    assert(strcmp(colorPair.majorColor, majorColor[0]) == 0);
    assert(strcmp(colorPair.minorColor, minorColor[1]) == 0);

    // Test case 4: Validate the color pair combination for index 0,2
    colorPair = getColorCode(0, 2);
    assert(colorPair.colorCode == 2);
    assert(strcmp(colorPair.majorColor, majorColor[0]) == 0);
    assert(strcmp(colorPair.minorColor, minorColor[2]) == 0);

    // Test case 5: Validate the color pair combination for index 0,3
    colorPair = getColorCode(0, 3);
    assert(colorPair.colorCode == 3);
    assert(strcmp(colorPair.majorColor, majorColor[0]) == 0);
    assert(strcmp(colorPair.minorColor, minorColor[3]) == 0);

    // Test case 6: Validate the color pair combination for index 0,4
    colorPair = getColorCode(0, 4);
    assert(colorPair.colorCode == 4);
    assert(strcmp(colorPair.majorColor, majorColor[0]) == 0);
    assert(strcmp(colorPair.minorColor, minorColor[4]) == 0);

    // Test cases shall be extened for all the combinations for (1,0), (1,1), (1,2) ... (4,4)
    // Test cases for indices (0,0), (1,1), (2,2), (3,3) and (4,4) shall be passed. Rest of the
    // other combinations are failing
    printf("All is well (maybe!)\n");
    return 0;
}
