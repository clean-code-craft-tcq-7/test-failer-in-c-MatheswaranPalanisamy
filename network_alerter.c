#include <stdio.h>
#include "network_alerter.h"

int networkAlert(float celcius)
{
    printf("Temperature alerted - %f\n", celcius);
    return 200;
}
