#include "../Headers/Attack.h"

Attack::Attack()
  :attackStrength(0), specialAttackStrength(0), specialAttackUse(1), attackName("none"), specialAttackName("none")
{
}

Attack::Attack(const string& attackName, const string& specialAttackName)
  :attackStrength(0), specialAttackStrength(0), specialAttackUse(1), attackName(attackName), specialAttackName(specialAttackName)
{
}

Attack::Attack(unsigned attack, unsigned specialAttack, const string& attackName, const string& specialAttackName)
  :attackStrength(attack), specialAttackStrength(specialAttack), specialAttackUse(1), attackName(attackName), specialAttackName(specialAttackName)
{}

void Attack::increaseAttackStrength() {
  //increase by some factor
  //by random with range 0-10
  attackStrength += rand() % 11;
}

void Attack::increaseSpecialAttackStrength(){
  //increase by some factor
  //by random with range 0-20
  specialAttackStrength += rand() % 21;
}

void Attack::increaseSpecialAttackUses(){
  ++specialAttackUse;
}

bool Attack::checkSpecialAttackUse()const{
  return specialAttackUse > 0;
}

int Attack::attack() const {
  //just return strength
  return attackStrength;
}

int Attack::specialAttack(){
  //decrease opponent health by specialattackstrength of you
  //check if you can use special attack
  //decrease specialattackuse
  if (!checkSpecialAttackUse()) return attackStrength;
  --specialAttackUse;
  return specialAttackStrength;
}

const string Attack::getAttackName() const{
  return attackName;
}

const string Attack::getSpecialAttackName() const {
  return specialAttackName;
}

void Attack::setAttackName(const string& name) {
  attackName = name;
}

void Attack::setSpecialAttackName(const string& name) {
  specialAttackName = name;
}

void Attack::setAttackStrength(const unsigned n){
  attackStrength = n;
}

void Attack::setSpecialAttackStrength(const unsigned n){
  specialAttackStrength = n;
}

void Attack::resetSpecialAttack() {
  specialAttackUse = 1;
}