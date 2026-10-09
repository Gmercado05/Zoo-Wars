//include google test here
//we will run all our tests with this :)

#include "gtest/gtest.h"
//inlcude all classes here!
#include "../Headers/Attack.h"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}