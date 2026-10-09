#pragma once
#include <iostream>
#include "../Headers/Animal.h"
#include "../Headers/Screen.h"
using namespace std;

class PlayGame {
  private:
    Animal* you;
    Animal* opponent[6]; //change this number?
    Screen screen;
    string userName;
  public:
    PlayGame();
    //need a deconstructor and rule of 3!!
    ~PlayGame();
    PlayGame(const PlayGame& copy); //copy constrcutor
    PlayGame& operator=(const PlayGame& rhs); //assignment operator
    void setUsername(const string& name);
    void initializeGame();
    void setAnimal();
    bool checkGameOver(Animal* you, Animal* opponenet);
    bool checkRoundOver() const;
    void play();
    bool confirmCharacter() const ; 
};
