#include "Motorbike.h"

string Motorbike::getEnType()
{
    return this->engineType;
}

double Motorbike::getSpeed()
{
    return this->maxSpeed;
}

void Motorbike::setEnType(string engineType)
{
    this->engineType = engineType;
}

void Motorbike::setSpeed(double maxSpeed)
{
    this->maxSpeed = maxSpeed;
}

void Motorbike::fuelConsumption()
{
    cout << "Very low consumption !!!" << endl;
}

void Motorbike::displayInf()
{
    cout << "Bike's information: Brand: " << this->getBrand()
        << " -- Model: " << this->getModel()
        << " -- Price: $" << this->getPrice()
        << " -- Engine type: " << engineType << endl;
}

Motorbike::~Motorbike()
{
}

