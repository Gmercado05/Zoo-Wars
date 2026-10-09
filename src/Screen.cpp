#include "../Headers/Screen.h"

Screen::Screen()
: PlayerName("none")
{}

void Screen::printWelcomeMessage(ostream& out)const{
    out << " Welcome to Zoo Wars! " << endl;
    out << " Press ‘x’ to start " << endl;
}


void Screen::printWonMessage(ostream& out) const{
    out << "YOU WON THIS ROUND!!!! Moving on to the next round... >:)\n";
}

void Screen::printLoseMessage(ostream& out) const{
  out << "Game Over!";
}

void  Screen::printDescription(const string &PlayerName, ostream& out)const{
    out << " Welcome " << PlayerName << "!\n"
    <<"You will now choose your character.\n"
    << "You will face 6 opponents throughout the duration of your journey.\n"
    << "Your strength will increase as you win each fight.\n"
    << "You have available 1 block and 1 special power to use in each fight.\n"
    << "Once you win, your health and all abilities will be reset/upgraded.\n"
    << "However, if you lose, its GAME OVER and you have the option to start over.\n"
    << "Ready to fight?\n"
    << "Press \'c\' to choose your character \n";
}

void Screen::setName(const string& name){
    PlayerName = name; 
}

void Screen::displayStats(unsigned health, ostream& out)const{
  out << "Current Health: " <<  health << "\n";
}

void Screen::printActionChoices(ostream& out)const{
  out << " Press \'a\' for attack \n"
  << " Press \'s\' for special attack \n"
  << " Press \'d\' to defend \n"; 
}

void Screen::printRestartingChoices(ostream& out)const{
  out << "GAME OVER \n"
  << "Press \'r\' to restart\n"
  << "Press \'q\' to quit\n";
}


void Screen::printFinalWonMessage(ostream& out)const{
  out << " CONGRATS\n"
  <<" You beat the final boss!\n"
  << " You are the king of the zoo.\n"
  << " Press ‘y’ to play again\n"
  << " Press ‘q’ to quit\n";
}
