#include "truck.h"
#include <iostream>
using namespace std;

void Truck::fuelConsumption() {
    cout << "[Truck] Fuel is low\n";
}

void Truck::displayInf() {
    cout << "Truck's information: Brand: " << this->getBrand()
        << " -- Model: " << this->getModel()
        << " -- Price: $" << this->getPrice()
        << " -- Maximum Load: " << maxLoadCapacity << " Kg"
        << " -- Length Base: " << lengthbase << " meters " << endl;
}

Truck::~Truck() {

}

