#ifndef SECTION4_HPP
#define SECTION4_HPP
#include <iostream>
#include <string>

class Drinkbuilder
{
    private:
        std::string name;
        int sugar;
        int temperature;
        bool withMilk;

    public:
        Drinkbuilder& setName(const std::string& name);
        Drinkbuilder& setSugar(int sugar);
        Drinkbuilder& setTemperature(int temperature);
        Drinkbuilder& setWithMilk(bool withMilk);
        void print();
};
constexpr int MINIMUM_TEMPERATURE=1;
constexpr int MAXIMUM_TEMPERATURE=100;
constexpr int MAXIMUM_SUGAR=99;

    #endif

