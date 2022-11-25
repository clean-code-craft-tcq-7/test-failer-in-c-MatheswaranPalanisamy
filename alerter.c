#include <stdio.h>
#include <assert.h>
#include "product_config.h"

#ifdef PRODUCTION
#include <network_alerter.h>
#endif

int alertFailureCount = 0;

#ifdef UNIT_TEST
// Stub will be alive for the unit test build
#define networkAlert    networkAlertStub
int TestNetworAlertStatus = 0;

// Stub function will return the networkAlert status based on the simulated value in test cases
int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub shall return the status simulated in the test cases
    return TestNetworAlertStatus;
}
#endif

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlert(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    // Testcase 1: Test networkAleter success
    // simulate TestNetworAlertStatus for success
    TestNetworAlertStatus = 200;
    alertInCelcius(400.5);
    assert(alertFailureCount == 0);
    printf("%d alerts failed.\n", alertFailureCount);

    // Testcase 2: Test networkAleretr failure
    // simulate TestNetworAlertStatus for failure
    TestNetworAlertStatus = 500;
    alertInCelcius(303.6);
    assert(alertFailureCount == 1);
    printf("%d alerts failed.\n", alertFailureCount);

    // Test cases to validate faranheit to celcius calculation shall be extended with all possible boundary conditions

    printf("All is well (maybe!)\n");
    return 0;
}
