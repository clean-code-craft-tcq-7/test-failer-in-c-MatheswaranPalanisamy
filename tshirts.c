#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    // Test case 1: Validate the size 'S'
    assert(size(37) == 'S');
    // Test case 2: Validate the size 'S' upper boundary
    assert(size(38) == 'S');
    // Test case 3: Validate the size 'M' lower boundary
    assert(size(38) == 'M');
    // Test case 4: Validate the size 'M'
    assert(size(40) == 'M');
    // Test case 5: Validate the size 'M' upper boundary
    assert(size(42) == 'M');
    // Test case 6: Validate the size 'L' lower boundary
    assert(size(42) == 'L');
    // Test case 7: Validate the size 'L' range
    assert(size(43) == 'L');

    // Conclusion: Here the sizes 38 and 42 are not considered for any of the sizeName check
    printf("All is well (maybe!)\n");
    return 0;
}
