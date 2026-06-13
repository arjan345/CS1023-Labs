#include <stdio.h>

#define building_fac 0.234
#define gasoline_fac 2.307
#define bicycle_fac 0.021

void buildingFootprint(void);
void carFootprint(void);
void bicycleFootprint(void);

int main(void)
{
    void (*Calculators[])(void) = {
        buildingFootprint,
        carFootprint,
        bicycleFootprint
    };

    int choice;

    puts(" Carbon Footprint Calculator");
    

    do {
        puts("Menu");
        puts("1. Building electricity footprint");
        puts("2. Car gasoline footprint");
        puts("3. Bicycle life-cycle footprint");
        puts("4. Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            Calculators[choice - 1]();
        } else if (choice == 4) {
            puts("Exited");
        } else {
            puts("Invalid menu choice. Please choose 1, 2, 3, or 4.\n");
        }
    } while (choice != 4);

    return 0;
}

void buildingFootprint(void)
{
    double kwh, kgCo2e;

    printf("Enter annual building electricity use in kWh: ");
    scanf("%lf", &kwh);

    kgCo2e = kwh * building_fac;

    puts("\nBuilding Electricity Footprint");
    printf("Input: %.2f kWh per year\n", kwh);
    printf("Factor used: %.3f kg CO2e per kWh\n", building_fac);
    printf("Estimated footprint: %.2f kg CO2e per year\n", kgCo2e);
    printf("Estimated footprint: %.3f metric tonnes CO2e per year\n\n", kgCo2e / 1000.0);
}

void carFootprint(void)
{
    double distanceKm, litresPer100Km, litresUsed, kgCo2;

    printf("Enter distance driven in km: ");
    scanf("%lf", &distanceKm);

    printf("Enter fuel efficiency in L/100 km: ");
    scanf("%lf", &litresPer100Km);

    litresUsed = distanceKm * litresPer100Km / 100.0;
    kgCo2 = litresUsed * gasoline_fac;

    puts("\nCar Gasoline Footprint");
    printf("Input distance: %.2f km\n", distanceKm);
    printf("Input fuel efficiency: %.2f L/100 km\n", litresPer100Km);
    printf("Calculated gasoline used: %.2f L\n", litresUsed);
    printf("Factor used: %.3f kg CO2 per L of motor gasoline\n", gasoline_fac);
    printf("Estimated footprint: %.2f kg CO2\n\n", kgCo2);
}

void bicycleFootprint(void)
{
    double distanceKm, kgCo2e;

    printf("Enter bicycle travel distance in km: ");
    scanf("%lf", &distanceKm);

    kgCo2e = distanceKm * bicycle_fac;

    puts("\nBicycle Life-Cycle Footprint");
    printf("Input distance: %.2f km\n", distanceKm);
    printf("Boundary: life-cycle estimate including manufacturing/maintenance/food energy\n");
    printf("Factor used: %.3f kg CO2e per km\n", bicycle_fac);
    printf("Estimated footprint: %.2f kg CO2e\n\n", kgCo2e);
}