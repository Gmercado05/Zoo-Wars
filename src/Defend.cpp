#include "../Headers/Defend.h"
#include <iostream>
using namespace std;

Defend::Defend()
  :defendStrength(0), defendUse(1), defendName("none")
{}

Defend::Defend(const string& defend)
  :defendStrength(0), defendUse(1), defendName(defend)
{}

Defend::Defend(unsigned defend, const string& defendName)
  :defendStrength(defend), defendUse(1), defendName(defendName)
{}

void Defend::increaseDefendUse() {
  defendUse++;
}

void Defend::increaseDefendStrength() {
  //increase defend of you by some factor
  //with random with range 0-10
  defendStrength += rand() % 11;
}

bool Defend::checkDefendUse() {
  return defendUse > 0;
}

int Defend::defend(){
  //check if can use defend
  //decrease defend left
  //return strength
  if(!checkDefendUse()) return 0;
  --defendUse;
  return defendStrength;
}

const string Defend::getDefendName() const{
  return defendName;
}

void Defend::setDefendName(const string& name){
  defendName = name;
}

void Defend::setDefendStrength(const unsigned num){
  defendStrength = num;
}

void Defend::resetDefend(){
  defendUse = 1;
}