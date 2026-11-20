#include <stdio.h>

#define SLAB1_UNITS         100
#define SLAB2_UNITS         200
#define RATE1_PAISE           0
#define RATE2_PAISE         225
#define RATE3_PAISE         450
#define FIXED_CHARGE_PAISE 5000L
#define METER_MAX          65535

typedef struct {
    unsigned int household_id;
    char category;
    unsigned short previous_reading;
    unsigned short current_reading;
    unsigned int units_consumed;
    long energy_charge_paise;
    long fixed_charge_paise;
    long total_bill_paise;
} HouseholdBill;

int main(void) {
    HouseholdBill sample_house = {
        .household_id = 4001,
        .category = 'D',
        .previous_reading = 1200,
        .current_reading = 1530,
        .units_consumed = 330,
        .fixed_charge_paise = FIXED_CHARGE_PAISE
    };

    printf("===================================================\n");
    printf(" GRAMA JYOTHI CO-OPERATIVE - TASK 1 DATA MODEL\n");
    printf("===================================================\n");
    printf("Household ID       : %u\n", sample_house.household_id);
    printf("Consumer Category  : %c\n", sample_house.category);
    printf("Previous Reading   : %u\n", sample_house.previous_reading);
    printf("Current Reading    : %u\n", sample_house.current_reading);
    printf("Units Consumed     : %u\n", sample_house.units_consumed);
    printf("Fixed Charge       : Rs %ld.%02ld\n", 
           sample_house.fixed_charge_paise / 100, 
           sample_house.fixed_charge_paise % 100);
    printf("Register Max Limit : %u (16-bit unsigned)\n", METER_MAX);
    printf("===================================================\n");

    return 0;
}
