#include <stdio.h>

int main(void)
{
    unsigned int household_id;
    unsigned short previous;
    unsigned short current;

    printf("Enter household ID, previous reading, and current reading: ");
    if (scanf("%u %hu %hu", &household_id, &previous, &current) != 3) {
        printf("Error: Invalid input format.\n");
        return 1;
    }

    unsigned int units = (unsigned short)(current - previous);
    long paise = 5000L;

    if (units > 200) {
        paise += (long)(100) * 225 + (long)(units - 200) * 450;
    } else if (units > 100) {
        paise += (long)(units - 100) * 225;
    }

    printf("----------------------------------------\n");
    printf("Household ID   : %u\n", household_id);
    printf("Previous       : %u\n", previous);
    printf("Current        : %u\n", current);
    printf("Units Consumed : %u\n", units);
    printf("Total Bill     : Rs %ld.%02ld\n", paise / 100, paise % 100);
    printf("----------------------------------------\n");

    return 0;
}
```[cite: 6]
