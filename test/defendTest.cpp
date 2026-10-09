#include "gtest/gtest.h"
#include "../Headers/Defend.h"

TEST(DefendClassTest, setAndGetDefendStrength){
  Defend* defend = new Defend();
  defend->setDefendStrength(10);
  unsigned strength = defend->defend();
  EXPECT_EQ(strength, 10);
  delete defend;
}

TEST(DefendClassTest, setAndGetDefendName){
  Defend* defend = new Defend();
  defend->setDefendName("Run");
  string name = defend->getDefendName();
  EXPECT_EQ(name, "Run");
  delete defend;
}

TEST(DefendClassTest, increasingDefendStrength){
  Defend* defend = new Defend();
  unsigned initial = defend->defend();
  defend->increaseDefendStrength();
  EXPECT_GE(defend->defend(), initial);
  EXPECT_LE(defend->defend(), initial + 10);
  delete defend;
}

TEST(DefendClassTest, increasingDefendUses){
  Defend* defend = new Defend();
  EXPECT_TRUE(defend->checkDefendUse());
  unsigned strength = defend->defend();
  EXPECT_FALSE(defend->checkDefendUse());
  defend->increaseDefendUse();
  EXPECT_TRUE(defend->checkDefendUse());
  delete defend;
}

TEST(DefendClassTest, checkingDefendUses){
  Defend* defend = new Defend();
  EXPECT_TRUE(defend->checkDefendUse());
  unsigned strength = defend->defend();
  EXPECT_FALSE(defend->checkDefendUse());
  defend->increaseDefendUse();
  EXPECT_TRUE(defend->checkDefendUse());
  delete defend;
}

TEST(DefendClassTest, checkingDefendUsesWithNonZero){
  Defend* defend = new Defend(10, "Run");
  EXPECT_TRUE(defend->checkDefendUse());
  unsigned strength = defend->defend();
  EXPECT_EQ(strength, 10);
  EXPECT_FALSE(defend->checkDefendUse());
  strength = defend->defend();
  EXPECT_EQ(strength, 0);
  defend->increaseDefendUse();
  EXPECT_TRUE(defend->checkDefendUse());
  delete defend;
}


TEST(DefendClassTest, defaultConstructor){
  Defend* defend = new Defend();
  EXPECT_TRUE(defend->checkDefendUse());
  unsigned strength = defend->defend();
  EXPECT_EQ(strength, 0);
  EXPECT_FALSE(defend->checkDefendUse());
  string name = defend->getDefendName();
  EXPECT_EQ(name , "none");
  delete defend;
}

TEST(DefendClassTest, ParameterizedConstructor1){
  Defend* defend = new Defend("Run");
  EXPECT_TRUE(defend->checkDefendUse());
  unsigned strength = defend->defend();
  EXPECT_EQ(strength, 0);
  EXPECT_FALSE(defend->checkDefendUse());
  string name = defend->getDefendName();
  EXPECT_EQ(name , "Run");
  delete defend;
}

TEST(DefendClassTest, ParameterizedConstructor2){
  Defend* defend = new Defend(10, "Run");
  EXPECT_TRUE(defend->checkDefendUse());
  unsigned strength = defend->defend();
  EXPECT_EQ(strength, 10);
  EXPECT_FALSE(defend->checkDefendUse());
  string name = defend->getDefendName();
  EXPECT_EQ(name , "Run");
  delete defend;
}

TEST(DefendClassTest, Rest){
  Defend* defendObject = new Defend();
  unsigned num = defendObject->defend();
  EXPECT_FALSE(defendObject->checkDefendUse());
  defendObject->resetDefend();
  EXPECT_TRUE(defendObject->checkDefendUse());
  delete defendObject;
}