#pragma once
#include <iostream>
#include "../Headers/Animal.h"
using namespace std;

class Screen {

  public:
    Screen();
    string PlayerName;
    void printWelcomeMessage(ostream& out = cout) const;
    void printWonMessage(ostream& out = cout) const;
    void printFinalWonMessage(ostream& out = cout) const;
    void printLoseMessage(ostream& out = cout) const;
    void printDescription(const string& PlayerName, ostream& out = cout) const;
    void setName(const string& name);
    void displayStats(unsigned health, ostream& out = cout) const;
    void printActionChoices(ostream& out = cout) const;
    void printRestartingChoices(ostream& out = cout)const;
};