#include "Car.h"

string Car::getColor()
{
	return this->color;
}

int Car::getNumSeat()
{
	return this->numSeat;
}

void Car::setColor(string color)
{
	this->color = color;
}

void Car::setNumSeat(int numSeat)
{
	this->numSeat = numSeat;
}

void Car::fuelConsumption()
{
	cout << "Low consumption!!!" << endl;
}

void Car::displayInf()
{
	cout << "Car's information: Brand: " << this->getBrand()
		<< " -- Model: " << this->getModel()
		<< " -- Price: $" << this->getPrice()
		<< " -- Color: " << color
		<< " -- Number of Seats: " << this->getNumSeat() << endl;
}

Car::~Car()
{
}

