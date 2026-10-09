#include "../Headers/PlayGame.h"

#include <cstdlib>

PlayGame::PlayGame()
    :you(nullptr), screen(), userName("none")
{
  //make the array in here!
  opponent[0] = new Animal("Albert", "Armadillo", "Angry Claws", "Swinging Tail", "Curl Up", 10, 15, 5);
  opponent[1] = new Animal("Bobby", "Bobcat", "Claw Mark", "Skull Bite", "Duck", 14, 19, 9);
  opponent[2] = new Animal("Carl", "Crocodile", "Power Bite", "Death Roll", "Tail Thrust", 18, 23, 13);
  opponent[3] = new Animal("Dillon", "Diamondback Rattlesnake", "Tail Slap", "Poisonous Fang Bite", "Rattle", 22, 27, 17);
  opponent[4] = new Animal("Emmanuel", "Elephant", "Stomp", "Tusk Throw", "Trunk Alert", 26, 31, 21);
  opponent[5] = new Animal("Leo", "Lion", "Pounce", "Ambush", "Roar", 30, 35, 25);
}

PlayGame::~PlayGame(){
  for(int i= 0; i < 6; ++i){
    delete opponent[i];
    opponent[i] = nullptr;
  }
  delete you;
  you = nullptr;
}

void PlayGame::setUsername(const string& name){
    screen.setName(name);
}

void PlayGame::initializeGame(){
//prints welcome, prints description, prints the output for creating your character 
  screen.printWelcomeMessage();

  char input;
  cin >> input;
  //check this input!!

  while(input != 'x' && input != 'X'){
    cout << "Press 'x' to start" << endl;
    cin >> input;
  }

  cout << "Enter a username: ";
  string user;
  cin >> user;
  if (!cin){
    //check this...figure it out :)
    throw "oh oh";
  }

  cout << endl;
  cout << "Press 'r' to read description" << endl;
  cout << "Press 'q' to quit" << endl;
  cout << "Press 'c' to create your character" << endl;
  char ch;
  cin >> ch;
  while(ch != 'r' && ch != 'q' && ch != 'c'){
    cout << "Press 'r' to read description" << endl;
    cout << "Press 'q' to quit" << endl;
    cout << "Press 'c' to create your character" << endl;
    cin >> ch;
  } //check if cin is still good? valid input!!

  if(ch == 'r'){
    screen.printDescription(user);
    char choose;
    cin >> choose;
    while(choose != 'c' && choose != 'C'){
      cout << "Press \'c\' to create your character" << endl;
      cin >> choose;
    }
  }
  else if (ch == 'q'){
    return;
  }

  setAnimal();
}

void PlayGame::setAnimal() {
  //creates the attributes the animal
  //name, type, name of attack, name of specialattack, name of defend
  //setting attack to 10, special attack to 15, defend to 10
  bool run = true;
  while (run){
    you = new Animal();
    cout << "Time to create your character!" << endl;
    cout << "Enter a name for your animal: " ;
    //check these inputs!!
    string name;
    cin >> name;
    you->setAnimalName(name);
    cout << endl << "Enter an animal type: ";
    string type;
    cin >> type;
    you->setAnimalType(type);
    cout << endl << "Enter name for your attack power: ";
    string attack;
    cin >> attack;
    you->setAttackName(attack);
    cout << endl << "Enter name for your special attack: ";
    string sa;
    cin >> sa;
    you->setSpecialAttackName(sa);
    cout << endl << "Enter a name for your defense power: ";
    string defend;
    cin >> defend;
    you->setDefendName(defend);
    you->setInitialStrengths();
    if(confirmCharacter()){
      run = false;
    } 
  }
}

bool PlayGame::checkGameOver(Animal* you, Animal* opponenet){
  return you->getHealth() == 0;
}

void PlayGame::play(){
  initializeGame();
  if (you == nullptr) return; // The player quit before creating a character.
  //check for input of x;
  for (int challengerNum = 0; challengerNum < 6; ++challengerNum) {
    while (opponent[challengerNum]->health.getCurrentHealth() > 0 && you->health.getCurrentHealth() > 0) {
      screen.printActionChoices();
      //having actions a,s,d,
      char input;
      cin >> input;
      int robotDecision = rand() % 3;
      if (input == 'a' || input == 'A') {
        cout << endl;
        cout << "You have decided to attack with " << you->attack.getAttackName() << endl;
          if (robotDecision == 0) { //attacking
            cout << opponent[challengerNum]->getName() << " has decided to attack as well" << endl;
            opponent[challengerNum]->health.decreaseHealth(you->attack.attack());
            you->health.decreaseHealth(opponent[challengerNum]->attack.attack());
            screen.displayStats(you->health.getCurrentHealth());
            cout << "Opponent's ";
            screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
          }
          if (robotDecision == 1) { //defending
            if (opponent[challengerNum]->defend.checkDefendUse()) {
              cout << opponent[challengerNum]->getName() << " has decided to defend" << endl;
              int decrease = abs(you->attack.attack() - opponent[challengerNum]->defend.defend());
              opponent[challengerNum]->health.decreaseHealth(decrease);
              screen.displayStats(you->health.getCurrentHealth());
              cout << "Opponent's ";
              screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
            }
            else {
              opponent[challengerNum]->health.decreaseHealth(you->attack.attack());
              cout << "You have attacked " << opponent[challengerNum]->getName() << endl;
              screen.displayStats(you->health.getCurrentHealth());
              cout << "Opponent's ";
              screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
            }
          }
          if (robotDecision == 2) { //specialAttack
            if (opponent[challengerNum]->attack.checkSpecialAttackUse()) {
              cout << opponent[challengerNum]->getName() << " is going to use special attack" << endl;
              you->health.decreaseHealth(opponent[challengerNum]->attack.specialAttack());
              opponent[challengerNum]->health.decreaseHealth(you->attack.attack());
              screen.displayStats(you->health.getCurrentHealth());
              cout << "Opponent's ";
              screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
            }
            else {
              opponent[challengerNum]->health.decreaseHealth(you->attack.attack());
              you->health.decreaseHealth(opponent[challengerNum]->attack.attack());
              screen.displayStats(you->health.getCurrentHealth());
             cout << "Opponent's ";
             screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
            }
          }
      }
      if (input == 's' || input =='S'){
        cout << endl;
        if (you->attack.checkSpecialAttackUse()) {
          cout << "You have decided to use your special attack with " << you->attack.getSpecialAttackName() << endl;
          if (robotDecision == 0) { //attacking
              cout << opponent[challengerNum]->getName() << " has decided to attack" << endl;
              opponent[challengerNum]->health.decreaseHealth(you->attack.specialAttack());
              you->health.decreaseHealth(opponent[challengerNum]->attack.attack());
              screen.displayStats(you->health.getCurrentHealth());
              cout << "Opponent's ";
              screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
          }
          if (robotDecision == 1) { //defending
            if (opponent[challengerNum]->defend.checkDefendUse()) {
              cout << opponent[challengerNum]->getName() << " has decided to defend" << endl;
              int decrease = abs(you->attack.specialAttack() - opponent[challengerNum]->defend.defend());
              opponent[challengerNum]->health.decreaseHealth(decrease);
              screen.displayStats(you->health.getCurrentHealth());
              cout << "Opponent's ";
              screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
            }
            else {
              opponent[challengerNum]->health.decreaseHealth(you->attack.attack());
              you->health.decreaseHealth(opponent[challengerNum]->attack.attack());
              screen.displayStats(you->health.getCurrentHealth());
             cout << "Opponent's ";
             screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
            }
          }
          if (robotDecision == 2) { //specialAttack
            if (opponent[challengerNum]->attack.checkSpecialAttackUse()) {
              cout << opponent[challengerNum]->getName() << " is going to use special attack" << endl;
              you->health.decreaseHealth(opponent[challengerNum]->attack.specialAttack());
              opponent[challengerNum]->health.decreaseHealth(you->attack.specialAttack());
              screen.displayStats(you->health.getCurrentHealth());
              cout << "Opponent's ";
              screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
            }
            else {
              opponent[challengerNum]->health.decreaseHealth(you->attack.attack());
              you->health.decreaseHealth(opponent[challengerNum]->attack.attack());
              screen.displayStats(you->health.getCurrentHealth());
              cout << "Opponent's ";
              screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
            }
          }
        }
        else {
          cout << "Sorry you are out of special attack so you will now attack instead" << endl;
          opponent[challengerNum]->health.decreaseHealth(you->attack.attack());
          you->health.decreaseHealth(opponent[challengerNum]->attack.attack());
          screen.displayStats(you->health.getCurrentHealth());
          cout << "Opponent's ";
          screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
        }
      }
      if (input == 'd' || input == 'D'){
        if (you->defend.checkDefendUse()) {
          cout << endl << "You have decided to defend with" << you->defend.getDefendName() << endl;
          if (robotDecision == 0) {
            cout << opponent[challengerNum]->getName() << " has decided to attack" << endl;
            int defending = max(0, opponent[challengerNum]->attack.attack() - you->defend.defend());
            you->health.decreaseHealth(defending);
            screen.displayStats(you->health.getCurrentHealth());
            cout << "Opponent's ";
            screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
          }
          if (robotDecision == 1) {
              cout << "nothing happens, you guys both are defending no attack haha" << endl;
          }
          if (robotDecision == 2) {
            if (opponent[challengerNum]->attack.checkSpecialAttackUse()) {
              cout << opponent[challengerNum]->getName() << " is going to use special attack" << endl;
              int defending = opponent[challengerNum]->attack.specialAttack() - you->defend.defend();
              you->health.decreaseHealth(defending);
              screen.displayStats(you->health.getCurrentHealth());
              cout << "Opponent's ";
              screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
            }
            else {
              opponent[challengerNum]->health.decreaseHealth(you->attack.attack());
              you->health.decreaseHealth(opponent[challengerNum]->attack.attack());
              screen.displayStats(you->health.getCurrentHealth());
              cout << "Opponent's ";
              screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
            }
          }
        }
        else {
          cout << "Sorry you are out defends" << endl;
          you->health.decreaseHealth(opponent[challengerNum]->attack.attack());
          screen.displayStats(you->health.getCurrentHealth());
          cout << "Opponent's ";
          screen.displayStats(opponent[challengerNum]->health.getCurrentHealth());
        }
      }
    if (you->health.getCurrentHealth() <= 0) {
      cout << "You have been defeated by " << opponent[challengerNum]->getName() << "!" << endl;
      screen.printRestartingChoices();
      char lose;
      cin >> lose;
      if (lose == 'r' || input == 'R'){
        play();
      }
      if (lose == 'q' || input == 'Q'){
        cout << "Thank you for playing" << endl;
      }
      break;
    }
    else if (opponent[challengerNum]->health.getCurrentHealth() <= 0) {
      cout << "Congratulations! You defeated " << opponent[challengerNum]->getName() << "!" << endl;
      if (challengerNum == 5) {
        screen.printFinalWonMessage();
        char won;
        cin >> won;
        if (input == 'y' || input == 'Y'){
          play();
        }
        if (input == 'q' || input == 'Q') {
          cout << "Thanks for playing" << endl;
        }
      }
      cout << "Onto the next opponent!! One stop closer to becoming King" << endl;
      you->defend.increaseDefendStrength();
      you->attack.increaseAttackStrength();
      you->restartHealtDefendAttack();
    }
  } 
  }
}

bool PlayGame::confirmCharacter() const {
//output all character info and ask for confirmation
//if yes, return true
//if not, return false;
  //output all character info and ask for confirmation
  cout << "This is your character: " << endl;
  cout << "Name: " << you->getName() << endl;
  cout << "Type: " << you->getAnimalType() << endl;
  cout << "Attack Power: " << you->getAttackName() << endl;
  cout << "Special power: " << you->getSpecialAttackName() << endl;
  cout << "Defend power: " << you->getDefendName() << endl;

  cout << "y for yes, n for no" << endl;
  char input;
  cin >> input;
  while(input != 'y' && input != 'n'){
    cout << "y for yes, n for no" << endl;
    cin >> input;
  }
  if(input == 'y') return true;
  return false;
}