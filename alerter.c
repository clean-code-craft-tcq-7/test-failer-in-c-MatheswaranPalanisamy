#include <stdio.h>

#include "alerter.h"
#include "alerter_test.h"

int alertFailureCount = 0;

float convertFaranheitToCelcius(float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

void alertInCelcius(float farenheit, int (*networkAlert_fptr)(float)) 
{
    float celcius = convertFaranheitToCelcius(farenheit);
    int returnCode = networkAlert_fptr(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    // Testcase 1: Test the temperature converter for negetive value faranheit
    testTemperatureConverter(-25.05, -31.69);
    // Testcase 2: Test the temperature converter for 0 faranheit
    testTemperatureConverter(0, -17.78);
    // Testcase 3: Test the temperature converter for positive value faranheit
    testTemperatureConverter(78.87, 26.03);
    // Testcase 4: Test alerter for return code 200
    testAlerter(93.75, 200);
    // Testcase 5: Test alerter for return code 404
    testAlerter(45.07, 404);
    // Testcase 5: Test alerter for return code 500
    testAlerter(31.23, 500);
    printf("All is well !!!\n");
    return 0;
}
