#include <iostream>
#include "Car.h"
#include "Vehicle.h"
#include "Motorbike.h"
#include "truck.h"
#include "Customer.h"
#include "GarageOwner.h"
#include <string>
using namespace std;
// Main function
int main() {
    GarageOwner owner("Nhóm 11", 0);
    // Add vehicles to garage
    owner.addVehicles(new Car("Toyota", "Corolla", 20000.0, "Red", 7));
    owner.addVehicles(new Truck("Volvo", "FH16", 120000.0, 25000.0, 8.0));
    owner.addVehicles(new Motorbike("Yamaha", "R15", 1500.0, "150cc", 140.0));
    owner.addVehicles(new Car("Honda", "Civic", 22000.0, "Blue", 5));
    owner.addVehicles(new Motorbike("Honda", "F3", 2000, "150", 200));

    Customer cus("Team 11 ");
    int choice;
    do {
        cout << "Welcome to our Garage\n";
        cout << "1. Buy a vehicle\n";
        cout << "2. Find by budget\n";
        cout << "3. Compare 2 vehicles\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "---------------------------------------";
        cout << endl;

        // User want to buy vehiclevehicle
        if (choice == 1) {
            if (owner.getVehicleCount() == 0) {
                cout << "Garage is empty.\n";
                continue;
            }
            owner.showGarage();
            cout << "\nEnter the index of the vehicle to buy: ";
            int idx; cin >> idx;
            cout << endl;
            Vehicle* v = owner.sellVehicle(idx - 1);
            cus.buyVehicle(v);
            cout << "---------------------------------------";
            cout << endl;
        }

        // User want to compare their vehicle's price
        else if (choice == 2) {
            cout << "Enter your budget: $";
            double budget;
            cin >> budget;
            int found = 0;
            cout << "Vehicles fit your budget: \n" << endl;
            for (int j = 0; j < owner.getVehicleCount(); j++) {
                if (*owner.vehicles[j] < budget) {
                    owner.vehicles[j]->displayInf();
                    found++;
                }
                else if (found == 0 && j == owner.getVehicleCount() - 1) {
                    cout << "Not exist!!!";
                    cout << "---------------------------------------" << endl;
                }
            }
            cout << "---------------------------------------" << endl;
        }
        else if (choice == 3) {
            cout << "\n--- Your Vehicles ---\n";
            cus.boughtList();
            cout << "Enter first vehicle index: "; int i, j;
            cin >> i;
            cout << "Enter second vehicle index: ";
            cin >> j;
            Vehicle* v1 = cus.getBought(i - 1);
            Vehicle* v2 = cus.getBought(j - 1);
            if (v1 && v2) {
                cout << "\n";
                cus.comparePrice(v1, v2);
            }
            else {
                cout << "Invalid indices.\n" << endl;
            }
        }
    } while (choice != 4);
    cout << "---------------------------------------" << endl;
    cout << "\nCustomer has bought: " << endl;
    for (int i = 0; i < cus.getSize(); i++) {
        cus.getBought(i)->displayInf();
    }
    cout << "\nThank for using our services." << endl;

    return 0;
}