#define MAX_COLOR_PAIR_STRING_SIZE      50

extern const char* majorColor[];
extern const char* minorColor[];

// Structure to return the color pair information
typedef struct{
    int colorCode;
    const char *majorColor;
    const char *minorColor;
}colorPair;

int printColorMap();
colorPair getColorPairInfo(int major_index, int minor_index);
void formatColorPairString(colorPair color_pair_info, char *color_pair_buffer);
