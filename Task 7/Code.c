#include <stdio.h>

int main(void)
{
    int units = 150;
    int fixed_charge = 5000;
    
    int wrong_division = units / 100;
    long correct_calculation = (long)units * 225;
    long explicit_cast_sum = fixed_charge + (long)units * 225;

    printf("Wrong division (150 / 100): %d\n", wrong_division);
    printf("Correct scaled multiplication: %ld\n", correct_calculation);
    printf("Explicit cast sum: Rs %ld.%02ld\n", explicit_cast_sum / 100, explicit_cast_sum % 100);

    return 0;
}
```[cite: 7]
