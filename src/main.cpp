#include "GUI/OthelloGUI.h"
#include "board/Board.h"
#include "gameObj/Game.h"
#include "UserInterface.h"

BoardField *board_fields[20][20];
ReversiRules *rules;
UserInterface *UserInt;

int main(int argc, char *argv[]){

    new OthelloGUI(argc, argv);
}
