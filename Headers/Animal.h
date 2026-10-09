#pragma once
#include <iostream>
#include "../Headers/Attack.h"
#include "../Headers/Defend.h"
#include "../Headers/Health.h"
using namespace std;


class Animal {
  private:
    string animalName;
    string animalType; 
  public:
    Attack attack;
    Defend defend;
    Health health;
    Animal();
    Animal(const string& name, const string& animalType, const string& attackName, 
            const string& specialAttackName, const string& defendName, const unsigned attackNum, 
            const unsigned sattackNum, const unsigned defendNum);
    void setAnimalName(const string& name);
    void setAnimalType(const string& name);
    const int getHealth()const;
    const string getName() const;
    const string getAnimalType() const;
    bool ifWon(Animal* opponent) const;
    bool ifLost() const;
    const string getAttackName() const;
    const string getSpecialAttackName() const;
    const string getDefendName() const;
    void setAttackName(string& name);
    void setSpecialAttackName(string& name);
    void setDefendName(const string& name);
    void setInitialStrengths();
    void restartHealtDefendAttack();
};
