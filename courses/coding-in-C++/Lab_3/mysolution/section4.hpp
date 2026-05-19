#ifndef SECTION4.HPP
#define SECTION4.HPP
#include <iostream>
class Character
{
    private: 
        std::string items;
        int maxSlots;
    public:
        bool isEmpty();
        bool isFull();
        bool addItem();
        bool removerLastItem();
        int getItemCount();
        int getMaxSlots();


        
};


class Warrior:public Character
{
    private:
        int weaponSkill;
    public:
        void regeneration();
        int getWeaponSkill();
        void displayStatus();
};

class Mage:public Character
{
    private:
        int manaPoint;
    public: 
        void regenerate();
        int getMana();
        void displayStatus();

};

class Thief:public Warrior
{
    public:
         

};

class Healer:public Mage
{

};

class Inventory
{

};

class Weapon
{
    private:
        std::string name;
        int damage;
    public:
        std::string getName();
        int getDamage();


};

#endif