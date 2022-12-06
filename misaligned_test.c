#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "misaligned.h"
#include "misaligned_test.h"

const char *printableColorPairs[MAX_COLOR_PAIRS] = 
{
    "0\t|White\t|Blue",
    "1\t|White\t|Orange",
    "2\t|White\t|Green",
    "3\t|White\t|Brown",
    "4\t|White\t|Slate",
    "5\t|Red\t|Blue",
    "6\t|Red\t|Orange",
    "7\t|Red\t|Green",
    "8\t|Red\t|Brown",
    "9\t|Red\t|Slate",
    "10\t|Black\t|Blue",
    "11\t|Black\t|Orange",
    "12\t|Black\t|Green",
    "13\t|Black\t|Brown",
    "14\t|Black\t|Slate",
    "15\t|Yellow\t|Blue",
    "16\t|Yellow\t|Orange",
    "17\t|Yellow\t|Green",
    "18\t|Yellow\t|Brown",
    "19\t|Yellow\t|Slate",
    "20\t|Violet\t|Blue",
    "21\t|Violet\t|Orange",
    "22\t|Violet\t|Green",
    "23\t|Violet\t|Brown",
    "24\t|Violet\t|Slate",
};

void testPrintColorMap()
{
    printf("Testing color map printer\n");
    int result = printColorMap();
    assert(result == 25);
}

void testColorPairs()
{
    int i = 0, j = 0;
    colorPair color_pair_info;
    int expected_color_code = 0;
    printf("Testing color Pairs\n");

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            color_pair_info = getColorPairInfo(i, j);
            assert(color_pair_info.colorCode == expected_color_code);
            assert(strcmp(color_pair_info.majorColor, majorColor[i]) == 0);
            assert(strcmp(color_pair_info.minorColor, minorColor[j]) == 0);
            expected_color_code++;
        }
    }
}

void testColorPairAlignment()
{
    int i = 0, j = 0;
    colorPair color_pair_info;
    int color_code = 0;
    char color_pair_string[MAX_COLOR_PAIR_STRING_SIZE];

    printf("Testing alignment for color maps\n");

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            color_pair_info.colorCode = color_code;
            color_pair_info.majorColor = majorColor[i];
            color_pair_info.minorColor = minorColor[j];
            formatColorPairString(color_pair_info, color_pair_string);
            assert(strcmp(color_pair_string, printableColorPairs[color_code]) == 0);
            color_code++;
        }
    }
}
