#include <stdio.h>

#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450
#define FIXED_CHARGE_PAISE 5000L

typedef unsigned short meter_t;

unsigned int consumption(meter_t previous, meter_t current)
{
    return (meter_t)(current - previous);
}

long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;
    if (units > SLAB2_UNITS) {
        paise += (long)(SLAB2_UNITS - SLAB1_UNITS) * RATE2_PAISE + (long)(units - SLAB2_UNITS) * RATE3_PAISE;
    } else if (units > SLAB1_UNITS) {
        paise += (long)(units - SLAB1_UNITS) * RATE2_PAISE;
    }
    return paise;
}

int main(void)
{
    meter_t prev_readings[] = {1000, 1000, 1000, 1000, 65400, 500};
    meter_t curr_readings[] = {1000, 1100, 1200, 1350, 120, 400};
    int num_tests = 6;

    for (int i = 0; i < num_tests; i++) {
        unsigned int units = consumption(prev_readings[i], curr_readings[i]);
        long paise = compute_bill(units);
        printf("Prev: %u, Curr: %u -> Units: %u -> Bill: Rs %ld.%02ld\n",
               prev_readings[i], curr_readings[i], units, paise / 100, paise % 100);
    }

    return 0;
}
```[cite: 8]
