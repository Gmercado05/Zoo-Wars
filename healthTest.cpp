#include "gtest/gtest.h"
#include "../Headers/Health.h"

TEST(HealthClassTest, defaultConstructor){
  Health* health = new Health();
  unsigned num = health->getCurrentHealth();
  EXPECT_EQ(num, 100);
  num = health->getMaxHealth();
  EXPECT_EQ(num, 100);
  delete health;
}

TEST(HealthClassTest, restarting){
  Health* health = new Health();
  unsigned num = health->getCurrentHealth();
  EXPECT_EQ(num, 100);
  health->decreaseHealth(100);
  num = health->getCurrentHealth();
  EXPECT_EQ(num, 0);
  health->restart();
  num = health->getCurrentHealth();
  EXPECT_EQ(num, 100);
  delete health;
}

TEST(HealthClassTest, gettingHealth){
  Health* health = new Health();
  unsigned num = health->getCurrentHealth();
  EXPECT_EQ(num, 100);
  num = health->getMaxHealth();
  EXPECT_EQ(num, 100);
  delete health;
}

TEST(HealthClassTest, decreasingHealth){
  Health* health = new Health();
  unsigned max = health->getCurrentHealth();
  EXPECT_EQ(max, 100);
  health->decreaseHealth(50);
  max = health->getMaxHealth();
  EXPECT_EQ(max, 100);
  unsigned currHealth = health->getCurrentHealth();
  EXPECT_EQ(currHealth, 50);
  health->decreaseHealth(100);
  currHealth = health->getCurrentHealth();
  EXPECT_EQ(currHealth, 0);
  delete health;
}