#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "misaligned.h"
#include "misaligned_test.h"
const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

void formatColorPairString(colorPair color_pair_info, char *color_pair_buffer)
{
    memset(color_pair_buffer, 0, MAX_COLOR_PAIR_STRING_SIZE);
    sprintf(color_pair_buffer, "%d\t|%s\t|%s", color_pair_info.colorCode, color_pair_info.majorColor, color_pair_info.minorColor);
}

colorPair getColorPairInfo(int major_index, int minor_index)
{
    colorPair color_pair_info;
    color_pair_info.colorCode = major_index * 5 + minor_index;
    color_pair_info.majorColor = majorColor[major_index];
    color_pair_info.minorColor = minorColor[minor_index];

    return color_pair_info;
}

int printColorMap() {
    int i = 0, j = 0;
    colorPair color_pair_info;
    char formated_color_pair[MAX_COLOR_PAIR_STRING_SIZE];
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            color_pair_info = getColorPairInfo(i, j);
            formatColorPairString(color_pair_info, formated_color_pair);
            printf("%s\n", formated_color_pair);
        }
    }

    return i * j;
}

int main(){
    testPrintColorMap();
    testColorPairs();
    testColorPairAlignment();
    // Test cases shall be extened for all the combinations for (1,0), (1,1), (1,2) ... (4,4)
    // Test cases for indices (0,0), (1,1), (2,2), (3,3) and (4,4) shall be passed. Rest of the
    // other combinations are failing
    printf("All is well !!!\n");
    return 0;
}
