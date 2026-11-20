#include <stdio.h>

#define FIXED_CHARGE 5000L

long compute_bill(int units) {
    int unused_var = 42;
    long paise = FIXED_CHARGE;
    if (units > 100) {
        paise += (long)(units - 100) * 225;
    }
    return paise;
}

int main(void) {
    int units = 150;
    long total = compute_bill(units);
    printf("Units: %d -> Bill: Rs %ld.%02ld\n", units, total / 100, total % 100);
    return 0;
}
```[cite: 7]
