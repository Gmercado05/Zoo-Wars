#pragma once
#include <iostream>
using namespace std;

class Attack {
  private:
    unsigned attackStrength;
    unsigned specialAttackStrength;
    unsigned specialAttackUse;
    string attackName;
    string specialAttackName;
  public:
    Attack();
    Attack(const string& attackName, const string& specialAttackName);
    Attack(unsigned attack, unsigned specialAttack, const string& attackName, const string& specialAttackName);
    void increaseAttackStrength();
    void increaseSpecialAttackStrength();
    void increaseSpecialAttackUses();
    bool checkSpecialAttackUse() const;
    int attack() const;
    int specialAttack();
    const string getAttackName() const;
    const string getSpecialAttackName() const;
    void setAttackName(const string& name);
    void setSpecialAttackName(const string& name);
    void setAttackStrength(const unsigned n);
    void setSpecialAttackStrength(const unsigned n);
    void resetSpecialAttack();
};