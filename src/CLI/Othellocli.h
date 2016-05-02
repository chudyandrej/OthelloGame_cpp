#ifndef OTHELLOCLI_H
#define OTHELLOCLI_H

#include <string>

class OthelloCLI{

public:
    OthelloCLI();

private:
    int boardSize;
    bool singlePlayer;
    int gameMode;
    std::string player1Name;
    std::string player2Name;
    std::string computerName;
    int discsToFreeze;
    int frozeTime;
    int changeTimer;

    void getSettings();
};

#endif // OTHELLOCLI_H
