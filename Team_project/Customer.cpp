#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;


Customer::Customer(string name)
{
    this->name = name;
    this->size = 0;
    this->bought = new Vehicle * [100];
}

string Customer::getName() const {
    return name;
}
void Customer::buyVehicle(Vehicle* v) {
    // check valid 
    if (v == nullptr) {
        cout << "Invalid" << endl;
        return;
    }
    else {
        bought[size++] = v;
    }
    cout << name << "bought: ";
    v->displayInf();
    // same thing with garage owner cpp
}

void Customer::boughtList() const {
    cout << name << "'s purchased vehicles (" << size << "):" << endl;
    if (size == 0) {
        cout << "  [None]" << endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        cout << "  [" << i + 1 << "] ";
        bought[i]->displayInf();
        cout << endl;
    }
}

void Customer::comparePrice(Vehicle* v1, Vehicle* v2) {
    if (!v1 || !v2) return;
    cout << "Comparing prices:\n" << endl;
    if (v1 < v2) {
        cout << "  " << v1->getModel() << " " << v1->getBrand() << " is cheaper than " << v2->getModel() << " " << v2->getBrand() << endl;
    }
    else if (v1 > v2) {
        cout << "  " << v1->getModel() << " " << v1->getBrand() << " is more expensive than " << v2->getModel() << " " << v2->getBrand() << endl;
    }
    else {
        cout << "  Both have the same price." << endl;
    }
}

Vehicle* Customer::getBought(int index) const {
    if (index < 0 || index >= size) return nullptr;
    return bought[index];
}

int Customer::getSize()
{
    return this->size;
}

Customer::~Customer() {
    for (int i = 0; i < size; i++) {
        delete bought[i];
    };
    delete[] bought;
}