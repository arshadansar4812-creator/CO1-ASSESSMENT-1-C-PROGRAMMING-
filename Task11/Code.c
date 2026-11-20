#include <stdio.h>
#include <stdlib.h>

#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450
#define FIXED_CHARGE_PAISE 5000L

typedef unsigned short meter_t;

unsigned int calculate_consumption(meter_t previous, meter_t current)
{
    return (meter_t)(current - previous);
}

long long compute_bill(unsigned int units)
{
    long long paise = FIXED_CHARGE_PAISE;
    if (units > SLAB2_UNITS) {
        paise += (long long)(SLAB2_UNITS - SLAB1_UNITS) * RATE2_PAISE + (long long)(units - SLAB2_UNITS) * RATE3_PAISE;
    } else if (units > SLAB1_UNITS) {
        paise += (long long)(units - SLAB1_UNITS) * RATE2_PAISE;
    }
    return paise;
}

int main(void)
{
    unsigned int household_id;
    meter_t previous, current;

    printf("Enter Household ID, Previous Reading, Current Reading: ");
    if (scanf("%u %hu %hu", &household_id, &previous, &current) != 3) {
        printf("Error: Invalid input format.\n");
        return 1;
    }

    unsigned int units = calculate_consumption(previous, current);
    long long total_paise = compute_bill(units);

    printf("----------------------------------------\n");
    printf("Household ID    : %u\n", household_id);
    printf("Previous Reading: %u\n", previous);
    printf("Current Reading : %u\n", current);
    printf("Units Consumed  : %u\n", units);
    printf("Total Bill      : Rs %lld.%02lld\n", total_paise / 100, total_paise % 100);
    printf("----------------------------------------\n");

    return 0;
}
```[cite: 9]
