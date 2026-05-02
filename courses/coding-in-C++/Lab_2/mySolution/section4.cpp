#include <iostream>
#include <string>
#include <iomanip>
#include "section4.hpp"

Drinkbuilder& Drinkbuilder::setName(const std::string& name)
{
    this->name = name;
    return *this;
}
Drinkbuilder& Drinkbuilder::setSugar(int sugar)
{
    while(sugar>MAXIMUM_SUGAR)
    {
        std::cout<<"Wrong value (range <100)"<<std::endl;
    }
    this->sugar = sugar;
    return *this;
}
Drinkbuilder& Drinkbuilder::setTemperature(int temperature)
{   while(temperature>MAXIMUM_TEMPERATURE || temperature<MINIMUM_TEMPERATURE)
    {
        std::cout<<"Wrong value (range 1-100)"<<std::endl;
    }
    this->temperature=temperature;
    return *this;
}
Drinkbuilder& Drinkbuilder::setWithMilk(bool withMilk)
{
    this->withMilk=withMilk;
    return *this;
}

void Drinkbuilder::print()
{
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Sugar: "<<sugar<<std::endl;
    std::cout<<"Temperature: "<<temperature<<std::endl;
    std::cout<<"Milk: "<<std::boolalpha<<withMilk<<std::endl;
}

int main()
{
    Drinkbuilder builder;
    builder.setName("Tea")
       .setSugar(2)
       .setTemperature(65)
       .setWithMilk(true)
       .print();
}