#include <stdio.h>

// Struktur Car global definiert
struct Car {
    float fuel_level;
    float max_fuel_level;
    char model[50]; // sinnvolle Größe für Modellname
};

// refuel gibt jetzt void zurück und nimmt einen Zeiger
void refuel(struct Car *ptr) {
    if (ptr->fuel_level < ptr->max_fuel_level) {
        ptr->fuel_level = ptr->max_fuel_level;
        printf("Das Auto wurde voll getankt. Der neue Tankstand beträgt: %f\n", ptr->fuel_level);
    } else {
        printf("Der Tank ist bereits voll. Der aktuelle Tankstand beträgt: %f\n", ptr->fuel_level);
    }
}

int main(void) {
    struct Car car1;
    car1.fuel_level = 10.5;
    car1.max_fuel_level = 100.5;
    snprintf(car1.model, sizeof(car1.model), "Mercedes"); // Modellname setzen
    refuel(&car1); // Adresse übergeben
    return 0;
}
