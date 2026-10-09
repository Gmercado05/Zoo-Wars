# Zoo Wars
 Authors:
 *[Wendy Vargas](https://github.com/wendyyvargas)
 *[Gonzalo Mercado](https://github.com/Gmercado05)
 *[Unnati Italia](https://github.com/unnatiitalia)
 *[Naima Cano](https://github.com/naimacano)

## Project Description  
Our game setting is in a zoo, where you are an animal and must fight to the top to become the zoo's king. When you start the game, you create and customize your character and each animal has a different attack, special attack, and defend. You are given the option to attack, defend, or use your special attack when it's your turn in the round. There are 5 rounds of the game, each being a different animal and your abilities strengths increase after you win each one. If you lose a round it's game over, and you are given the option of starting over or just quitting the game. Now win, and you become the king of the zoo.


It is interesting because we get to combine all our skills like object-oriented programming, inheritance, conditional statements, randomization, unit testing, compiling object files, and overall learning how to use Git to collaborate on one final project. We can use all these old skills and learn new ones to create a fun and interactive game as a team.

The language we plan to use is C++. The tools we will be using are VSCode and GitHub. 
If time allows, we can add a visual component to the game. 

Inputs: through the keyboard
* Input: x - to start
* Input: r - read description
* Input: s - skip to game
* Input: q - quit
* Input: c - choose character
* Input: y - to confirm character
* Input: n - to create character again
* Input when fighting character
    * a - attack
    * s - use special attack
    * d - defend
* Input when losing game
    * r - restart
    * q - quit
* Input when win game
    * y - play again
    * q - quit
* Input when creating character
    * a string - animal name
    * a string - animal type
    * a string - attack name
    * a string - special attack name
    * a string - defend 
  
Outputs: through the terminal 
* An introductory message to the game will be displayed
* Before the game starts, the player will asked to enter a username, an animal name, an animal type, an attack name, a special attack, and defend name
* Each round number and your health will be displayed
* When it’s your turn, in the round; you’d be asked to either, attack the opponent or defend from your opponent’s attack, which would be displayed
* After each attack you will see your health and your opponent’s health will be outputted
* After each turn there will be an output message describing what you did would be outputted
* If you win after each round there will be a message congratulating you 
* If you lose a message will be displayed stating if you want to try again

Features
* 5 total opponents to reach the final level to become king of the zoo
* The opponents in the game are different animals that would be found in the zoo; starting from the animal you create, until the strongest animal (the lion). 
* You can attack an opponent with your special power that is custom to each animal (once a round)
* You can defend from an opponent’s attack a limited number of times (once a round)
* Each animal has a special attack that will be unlocked once you defeat them


## Phase II
 
## User Interface Specification
### Navigation Diagram
The navigation diagram represents the stages of our game. They are the stages that will be outtped to the terminal where our game will be played. The user gets a welcome message and then is prompted to enter a username. After that they are given three options on how to continue. Then they are given a brief description and prompted to enter inforamation to create their character. Once they create their character they are asked to confirm it. In each of the fights that follow, they are prompted for actions. At any point of any fight, if the player loses, they are given option to quit or start over. If they win, they are given the same option but with a different messagae. 
 [Zoo Wars Navigation Diagram .pdf](https://docs.google.com/drawings/d/1GrPBk4WaaNFpygvm8O8I_mPXEjYWbvEmKoqj3sdguhc/edit)

### Screen Layouts
When the fights happen, the user will be given information after each of their attacks and after each of the opponent's attack. The stats of each character will be displayed. After each fight, if the user wins, they will be told what their new strengths are. At any point in any fight, if the player loses, they are taken to the game over output. 
[Zoo Wars Screen Layouts](https://docs.google.com/drawings/d/1uTdymclumBMBb528Is19LvEI26Ev7AFL5q-9E4QtrJ0/edit?usp=sharing)

## Class Diagram
PlayGame class will manage the game play. We will create an array of pointer Rounds in PlayGame to manage each round of the game. We will create instances of Screen in PlayGame that will manage each screen of the game and what to output to each one. We will create an array of pointers to different animals we create within PlayGame. Health, Defend, and Attack will be parts of Animal where they will control each aspect withtin their classes to Animal.  
 [Zoo Wars UML Diagram](https://docs.google.com/drawings/d/1AQaVNFiGCfhLkq0emgXhNlK2zDoayMKR2UAUw8xEB-s/edit?usp=sharing)
 
## Phase III
* The solid principles used to change our class diagram:
  * The solid principle we applied to our code was the single responsibility principle. Our class Animal and PlayGame had too many responsibilities so we added other classes to help with those responsibilities. We added Health, Attack, and Defend for the Animal class and we added Screen and Round to help PlayGame. This change will help us write better code because we can focus on small aspects of a class without touching the larger components. It allows us to focus on just pieces and then just use those in a bigger whole (abstraction). Lastly, it helps when we are writing code because we could just change one part of the code and we will not have to worry about its larger effect on the whole so it makes testing easier as well.
  * We applied the Open/Close principle to the Animal.cpp class. It’s set in stone meaning it cannot be changed once it’s written. We have the base classes within the Animal.cpp file and it’s open to extension but cannot be modified. We can add more classes and features within this class if we wish to. For example almost all the constructor parameters are set to const so we can’t modify them once we’ve declared them. This helps us write better code by adding new functionality through extending rather than changing the existing behavior of the classes. It also helps reduce bugs this way and lead to less breaks in code since the previous code is unmodified, letting us focus on just the extended code.
  * We applied the Dependency Inversion Principle to Attack.cpp where SpecialAttack and HiddenAttack subclasses are derived from the Attack superclass. These subclasses depend on the Attack superclass to implement their functions since the Attack class defines the functionalities for its derived subclasses. This helps us write better code as it increases flexibility, testability, and scalability.

 

 ## Final deliverable
 ## Screenshots
  Screenshots of the input/output after running your application
> ![image](https://github.com/user-attachments/assets/bc9ca34a-4458-46fd-8b73-3ab7fccce0a2)
> ![image](https://github.com/user-attachments/assets/e250ee12-9fae-40a0-863f-7b022962f8c8)
> ![image](https://github.com/user-attachments/assets/106b3353-0c46-4f6a-bb24-7d5ab32f30de)
> ![image](https://github.com/user-attachments/assets/1547b986-7d1f-4ac6-8185-06c682ff30db)
> ![image](https://github.com/user-attachments/assets/e09009e1-4a76-4e2f-8f77-197cda8a199c)

 ## Installation/Usage
  Instructions on installing and running your application
  c++, c++ compiler, and terminal
 ## Testing
 * How was your project tested/validated?
    * The approach was to run unit testing with google test. We made a test file for each class running every function at least once. Then we ran all our tests with the help of a cmake file.
 * We tested using google tests. We made a cmake file and then ran an executable
  
 * Attack, Defend, Health, Animal - Wendy
 * Screen - Gonzalo
 * PlayGame - Unnati (not finished)
 
