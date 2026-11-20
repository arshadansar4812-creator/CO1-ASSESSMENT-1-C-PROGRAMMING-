#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long watt_hour_t;

struct TariffConfig {
    unsigned int normal_rate_paise;
    unsigned int peak_rate_paise;
    unsigned int fixed_charge_paise;
};

long long compute_smart_bill(watt_hour_t normal_wh, watt_hour_t peak_wh, struct TariffConfig config)
{
    double normal_units = (double)normal_wh / 1000.0;
    double peak_units = (double)peak_wh / 1000.0;
    
    long long energy_charge = (long long)(normal_units * config.normal_rate_paise + peak_units * config.peak_rate_paise);
    return config.fixed_charge_paise + energy_charge;
}

int main(void)
{
    struct TariffConfig config = {
        .normal_rate_paise = 225,
        .peak_rate_paise = 270,
        .fixed_charge_paise = 5000
    };

    watt_hour_t normal_wh = 250000ULL;
    watt_hour_t peak_wh = 100000ULL;

    long long total_paise = compute_smart_bill(normal_wh, peak_wh, config);

    printf("Normal Watt-Hours: %llu\n", normal_wh);
    printf("Peak Watt-Hours  : %llu\n", peak_wh);
    printf("Total Bill       : Rs %lld.%02lld\n", total_paise / 100, total_paise % 100);

    return 0;
}
```[cite: 9, 10]
