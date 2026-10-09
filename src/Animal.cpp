#include "../Headers/Animal.h"

Animal::Animal()
  :animalName("none"), animalType("none"), attack(), defend(), health()
{
}

Animal::Animal(const string& name, const string& animalType, const string& attackName, 
            const string& specialAttackName, const string& defendName, const unsigned attackNum, 
            const unsigned sattackNum, const unsigned defendNum)
  :animalName(name), animalType(animalType), attack(attackNum, sattackNum, attackName, specialAttackName),
  defend(defendNum, defendName), health()
{
}

void Animal::setAnimalName(const string& name){
  animalName = name;
}

void Animal::setAnimalType(const string& name){
  animalType = name;
}

const int Animal::getHealth() const {
  return this->health.getCurrentHealth();
}

const string Animal::getName() const {
  return animalName;
}

const string Animal::getAnimalType() const {
  return animalType;
}

bool Animal::ifWon(Animal* opponent) const { //changing once we make array
  if (opponent->getHealth() == 0) { //add index here??
    return true;
  }
  return false;
}

bool Animal::ifLost() const {
  if (this->getHealth() == 0) {
    return true;
  }
  return false;
}

const string Animal::getAttackName() const {
  return this->attack.getAttackName();
}

const string Animal::getSpecialAttackName() const {
  return this->attack.getSpecialAttackName();
}

const string Animal::getDefendName() const {
  return this->defend.getDefendName();
}

void Animal::setAttackName(string& name){
  attack.setAttackName(name);
}

void Animal::setSpecialAttackName(string& name){
  attack.setSpecialAttackName(name);
}
    
void Animal::setDefendName(const string& name){
  defend.setDefendName(name);
}

void Animal::setInitialStrengths(){
  attack.setAttackStrength(10);
  attack.setSpecialAttackStrength(15);
  defend.setDefendStrength(10);
}


void Animal::restartHealtDefendAttack() {
  health.restart();
  attack.resetSpecialAttack();
  defend.resetDefend();
}