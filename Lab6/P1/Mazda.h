#pragma once
#include "Car.h"
class Mazda : public Car {
  public:
    Mazda();
    char* get_numemasina() const;
    float get_fuelcapacity() const;
    float get_fuelconsumption() const;
    int get_averagespeed() const;
    void setWeather(Weather weather);
};