#pragma once
#include <iostream>
using namespace std;

class Defend {
  private:
    unsigned defendStrength;
    unsigned defendUse;
    string defendName;
  public:
    Defend();
    Defend(const string& defend);
    Defend(unsigned defend, const string& defendName);
    void increaseDefendUse();
    void increaseDefendStrength();
    bool checkDefendUse();
    int defend();
    const string getDefendName() const;
    void setDefendName(const string& name);
    void setDefendStrength(const unsigned num);
    void resetDefend();
};