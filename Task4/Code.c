#include <stdio.h>

#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define RUPEES_TO_PAISE(r) ((long)((r) * 100))

int main(void)
{
    int a = 5;
    int b = 12;
    double rupees = 150.50;

    printf("Square of (%d + 1) = %d\n", a, SQUARE(a + 1));
    printf("Max of %d and %d = %d\n", a, b, MAX(a, b));
    printf("Rupees %.2f = %ld paise\n", rupees, RUPEES_TO_PAISE(rupees));

    return 0;
}
```[cite: 5]
