#include "gtest/gtest.h"
#include "../Headers/Animal.h"

TEST(AnimalClassTest, defaultConstructor){
  Animal* animal = new Animal();
  string name = animal->getName();
  EXPECT_EQ(name, "none");
  string type = animal->getAnimalType();
  EXPECT_EQ(type, "none");
  delete animal;
}

TEST(AnimalClassTest, ParameterizedConstructor){
  Animal* animal = new Animal("Bob", "Tiger", "Claw", "Power", "Run", 10, 20, 5);
  string name = animal->getName();
  EXPECT_EQ(name, "Bob");
  string type = animal->getAnimalType();
  EXPECT_EQ(type , "Tiger");
  string attack = animal->getAttackName();
  EXPECT_EQ(attack, "Claw");
  string specialAttack = animal->getSpecialAttackName();
  EXPECT_EQ(specialAttack, "Power");
  string defendN = animal->getDefendName();
  EXPECT_EQ(defendN, "Run");
  unsigned attackStrength = animal->attack.attack();
  EXPECT_EQ(attackStrength, 10);
  unsigned special = animal->attack.specialAttack();
  EXPECT_EQ(special, 20);
  unsigned defend = animal->defend.defend();
  delete animal;
}

TEST(AnimalClassTest, setAndGetAnimalName){
  Animal* animal = new Animal();
  animal->setAnimalName("Bob");
  string name = animal->getName();
  EXPECT_EQ(name, "Bob");
  delete animal;
}

TEST(AnimalClassTest, setAndGetAnimalType){
  Animal* animal = new Animal();
  animal->setAnimalType("Tiger");
  string name = animal->getAnimalType();
  EXPECT_EQ(name, "Tiger");
  delete animal;
}

TEST(AnimalClassTest, gettingHealth){
  Animal* animal = new Animal();
  unsigned health = animal->getHealth();
  EXPECT_EQ(health, 100);
  delete animal;
}

TEST(AnimalClassTest, won){
  Animal* animal = new Animal();
  unsigned health = animal->getHealth();
  EXPECT_FALSE(animal->ifWon(animal));
  animal->health.decreaseHealth(100);
  health = animal->getHealth();
  EXPECT_TRUE(animal->ifWon(animal));
  delete animal;
}

TEST(AnimalClassTest, lost){
  Animal* animal = new Animal();
  unsigned health = animal->getHealth();
  EXPECT_FALSE(animal->ifLost());
  animal->health.decreaseHealth(100);
  health = animal->getHealth();
  EXPECT_TRUE(animal->ifLost());
  delete animal;
}

TEST(AnimalClassTest, setAndGetAttackName){
  Animal* animal = new Animal();
  string punch = "Punch";
  animal->setAttackName(punch);
  string name = animal->getAttackName();
  EXPECT_EQ(name, "Punch");
  delete animal;
}

TEST(AnimalClassTest, setAndGetSpecialAttackName){
  Animal* animal = new Animal();
  string claw = "Claw";
  animal->setSpecialAttackName(claw);
  string name = animal->getSpecialAttackName();
  EXPECT_EQ(name, "Claw");
  delete animal;
}

TEST(AnimalClassTest, setAndGetDefendName){
  Animal* animal = new Animal();
  string run = "Run";
  animal->setDefendName(run);
  string name = animal->getDefendName();
  EXPECT_EQ(name, "Run");
  delete animal;
}

TEST(AnimalClassTest, initializingStrengths){
  Animal* animal = new Animal();
  animal->setInitialStrengths();
  unsigned num = animal->attack.attack();
  EXPECT_EQ(num, 10);
  num = animal->attack.specialAttack();
  EXPECT_EQ(num, 15);
  num = animal->defend.defend();
  EXPECT_EQ(num, 10);
  delete animal;
}
