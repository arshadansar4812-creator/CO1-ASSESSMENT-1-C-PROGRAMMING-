#ifndef BILLING_H
#define BILLING_H

#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450
#define FIXED_CHARGE_PAISE 5000L

typedef unsigned short meter_t;

unsigned int consumption(meter_t previous, meter_t current);
long compute_bill(int units);

#endif

#include <stdio.h>

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
    meter_t prev = 1200;
    meter_t curr = 1530;
    unsigned int units = consumption(prev, curr);
    long p = compute_bill(units);

#ifdef DEBUG
    printf("[DEBUG] Previous: %u, Current: %u\n", prev, curr);
#endif

    printf("Units: %u -> Rs %ld.%02ld\n", units, p / 100, p % 100);
    return 0;
}
```[cite: 6]
