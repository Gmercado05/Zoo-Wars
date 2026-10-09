#include "gtest/gtest.h"
#include "../Headers/Screen.h"
#include <sstream>
using namespace std;

class ScreenTest : public ::testing::Test {
protected:
    Screen screen;
    ostringstream out;
    void SetUp() override {
        cout.rdbuf(out.rdbuf());
    }
    void TearDown() override {
        cout.rdbuf(nullptr);
    }
};

TEST_F(ScreenTest, printWelcomeMessage) {
    screen.printWelcomeMessage(out);
    EXPECT_EQ(out.str(), " Welcome to Zoo Wars! \n Press ‘x’ to start \n");
}

TEST_F(ScreenTest, printWonMessage) {
    screen.printWonMessage(out);
    EXPECT_EQ(out.str(), "YOU WON THIS ROUND!!!! Moving on to the next round... >:)\n");
}

TEST_F(ScreenTest, printLoseMessage) {
    screen.printLoseMessage(out);
    EXPECT_EQ(out.str(), "Game Over!");
}

TEST_F(ScreenTest, printDescription) {
    screen.printDescription("Wendy", out);
    string expect =
        " Welcome Wendy!\n"
        "You will now choose your character.\n"
        "You will face 7 opponents throughout the duration of your journey.\n"
        "Your strength will increase as you win each fight.\n"
        "You have available 1 block and 1 special power to use in each fight.\n"
        "Once you win, your health and all abilities will be reset/upgraded.\n"
        "However, if you lose, its GAME OVER and you have the option to start over.\n"
        "Ready to fight?\n"
        "Press 'c' to choose your character \n";
    EXPECT_EQ(out.str(), expect);
}

TEST_F(ScreenTest, displayStats) {
    screen.displayStats(55, out);
    EXPECT_EQ(out.str(), "Current Health: 55\n");
}

TEST_F(ScreenTest, printActionChoices) {
    screen.printActionChoices(out);
    string expect =
        " Press 'a' for attack \n"
        " Press 's' for special attack \n"
        " Press 'd' to defend \n";
    EXPECT_EQ(out.str(), expect);
}

TEST_F(ScreenTest, printRestartingChoices) {
    screen.printRestartingChoices(out);
    string expect =
        "GAME OVER \n"
        "Press 'r' to restart\n"
        "Press 'q' to quit\n";
    EXPECT_EQ(out.str(), expect);
}

TEST_F(ScreenTest, printFinalWonMessage) {
    screen.printFinalWonMessage(out);
    string expect =
        " CONGRATS\n"
        " You beat the final boss!\n"
        " You are the king of the zoo.\n"
        " Press ‘y’ to play again\n"
        " Press ‘q’ to quit\n";
    EXPECT_EQ(out.str(), expect);
}

TEST_F(ScreenTest, setName) {
    screen.setName("Naima");
    EXPECT_EQ(screen.PlayerName, "Naima");
}
