#include "gtest/gtest.h"
#include "../Headers/Attack.h"

TEST(AttackClassTest, setAndGetAttackName){
  Attack* attack = new Attack();
  attack->setAttackName("Punch");
  string name = attack->getAttackName();
  EXPECT_EQ(name, "Punch");
  delete attack;
}

TEST(AttackClassTest, setAndGetSpeicalAttackName){
  Attack* attack = new Attack();
  attack->setSpecialAttackName("Claw");
  string name = attack->getSpecialAttackName();
  EXPECT_EQ(name, "Claw");
  delete attack;
}

TEST(AttackClassTest, setAndGetAttackStrength){
  Attack* attack = new Attack();
  attack->setAttackStrength(20);
  unsigned strength = attack->attack();
  EXPECT_EQ(strength, 20);
  delete attack;
}

TEST(AttackClassTest, setAndGetSpecialAttackStrength){
  Attack* attack = new Attack();
  attack->setSpecialAttackStrength(40);
  unsigned strength = attack->specialAttack();
  EXPECT_EQ(strength, 40);
  delete attack;
}

TEST(AttackClassTest, increasingAttackStrength){
  Attack* attack = new Attack();
  unsigned initial = attack->attack();
  attack->increaseAttackStrength();
  EXPECT_GE(attack->attack(), initial); //attack should have increased
  EXPECT_LE(attack->attack(), initial + 10); //within range
  delete attack;
}

TEST(AttackClassTest, increasingSpecialAttackStrength){
  Attack* attack = new Attack();
  unsigned initial = attack->specialAttack();
  attack->increaseSpecialAttackStrength();
  EXPECT_GE(attack->specialAttack(), initial); //special attack should have increased
  EXPECT_LE(attack->specialAttack(), initial + 20); //within range
  delete attack;
} 

TEST(AttackClassTest, increasingSpecialAttackUses){
  Attack* attack = new Attack();
  EXPECT_TRUE(attack->checkSpecialAttackUse());
  unsigned strength = attack->specialAttack();
  EXPECT_FALSE(attack->checkSpecialAttackUse());
  attack->increaseSpecialAttackUses();
  EXPECT_TRUE(attack->checkSpecialAttackUse());
  delete attack;
}

TEST(AttackClassTest, checkingSpecialAttackUses){
  Attack* attack = new Attack();
  EXPECT_TRUE(attack->checkSpecialAttackUse());
  unsigned strength = attack->specialAttack();
  EXPECT_FALSE(attack->checkSpecialAttackUse());
  attack->increaseSpecialAttackUses();
  EXPECT_TRUE(attack->checkSpecialAttackUse());
  delete attack;
}

TEST(AttackClassTest, checkingSpecialAttackUsesWithNonZero){
  Attack* attack = new Attack(10, 20, "Punch", "Claw");
  EXPECT_TRUE(attack->checkSpecialAttackUse());
  unsigned strength = attack->specialAttack();
  EXPECT_EQ(strength, 20);
  EXPECT_FALSE(attack->checkSpecialAttackUse());
  strength = attack->specialAttack();
  EXPECT_EQ(strength, 10);
  attack->increaseSpecialAttackUses();
  EXPECT_TRUE(attack->checkSpecialAttackUse());
  delete attack;
}

TEST(AttackClassTest, defaultConstructor){
  Attack* attack = new Attack();
  unsigned attackStrength = attack->attack();
  EXPECT_EQ(attackStrength, 0);
  EXPECT_TRUE(attack->checkSpecialAttackUse());
  unsigned specialAttackStrength = attack->specialAttack();
  EXPECT_EQ(specialAttackStrength, 0);
  EXPECT_FALSE(attack->checkSpecialAttackUse());
  string attackName = attack->getAttackName();
  EXPECT_EQ(attackName, "none");
  string specialAttackName = attack->getSpecialAttackName();
  EXPECT_EQ(specialAttackName, "none");
  delete attack;
}

TEST(AttackClassTest, ParameterizedConstructor1){
  Attack* attack = new Attack("Punch", "Claw");
  unsigned attackStrength = attack->attack();
  EXPECT_EQ(attackStrength, 0);
  EXPECT_TRUE(attack->checkSpecialAttackUse());
  unsigned specialAttackStrength = attack->specialAttack();
  EXPECT_EQ(specialAttackStrength, 0);
  EXPECT_FALSE(attack->checkSpecialAttackUse());
  string attackName = attack->getAttackName();
  EXPECT_EQ(attackName, "Punch");
  string specialAttackName = attack->getSpecialAttackName();
  EXPECT_EQ(specialAttackName, "Claw");
  delete attack;
}

TEST(AttackClassTest, ParameterizedConstructor2){
  Attack* attack = new Attack(10, 20, "Punch", "Claw");
  unsigned attackStrength = attack->attack();
  EXPECT_EQ(attackStrength, 10);
  EXPECT_TRUE(attack->checkSpecialAttackUse());
  unsigned specialAttackStrength = attack->specialAttack();
  EXPECT_EQ(specialAttackStrength, 20);
  EXPECT_FALSE(attack->checkSpecialAttackUse());
  string attackName = attack->getAttackName();
  EXPECT_EQ(attackName, "Punch");
  string specialAttackName = attack->getSpecialAttackName();
  EXPECT_EQ(specialAttackName, "Claw");
  delete attack;
}

TEST(AttackClassTest, Rest){
  Attack* attackObject = new Attack();
  unsigned num = attackObject->specialAttack();
  EXPECT_FALSE(attackObject->checkSpecialAttackUse());
  attackObject->resetSpecialAttack();
  EXPECT_TRUE(attackObject->checkSpecialAttackUse());
  delete attackObject;
}