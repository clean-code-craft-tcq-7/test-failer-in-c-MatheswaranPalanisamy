#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "alerter.h"

extern int alertFailureCount;

int TestNetworAlertStatus = 0;

// Stub function will return the networkAlert status based on the simulated value in test cases
int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub shall return the status simulated in the test cases
    return TestNetworAlertStatus;
}

// Tester function which tests the 
void testAlerter(float farenheit, int return_code)
{
    // Setup for the test environment
    int alert_failure_count = alertFailureCount;
    TestNetworAlertStatus = return_code;

    // Test the function under test
    alertInCelcius(farenheit, networkAlertStub);

    // Check for the intended result
    if(return_code == 200)
    {
        assert(alertFailureCount == alert_failure_count);
    }
    else
    {
        assert(alertFailureCount == alert_failure_count + 1);
    }
}

// Tester function which tests the 
void testTemperatureConverter(float farenheit, float expected_celcius)
{
    // Setup for the test environment
    float celcius = convertFaranheitToCelcius(farenheit);
    float epsilon = 0.01;
    assert(fabs(celcius - expected_celcius) < epsilon);
}
