#pragma once
#include <iostream>
using namespace std;

class Health {
  private:
    int maxHealth;
    int currentHealth;
  public:
    Health();
    void restart();
    const int getCurrentHealth() const;
    const int getMaxHealth() const;
    void decreaseHealth(int amountDecreased);
};