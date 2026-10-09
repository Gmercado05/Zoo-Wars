#include "../Headers/Health.h"

Health::Health()
  :maxHealth(100), currentHealth(100) 
{}

void Health::restart() {
 currentHealth = maxHealth;
}

const int Health::getCurrentHealth() const {
  return currentHealth;
}

const int Health::getMaxHealth() const{
  return maxHealth;
}

//will not use for now
// void Health::increaseHealth() {
//  currentHealth increase by some factor
//  if (currentHealth > maxHealth ) {
//    currentHealth = maxHealth;
//  }
// }


void Health::decreaseHealth(int amountDecreased) {
 currentHealth -= amountDecreased;
 if (currentHealth < 0) {
   currentHealth = 0;
 }
}
