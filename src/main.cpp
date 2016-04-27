#include "GUI/othellogui.h"
#include "board/Board.h"
#include "gameObj/Game.h"
#include "userinterface.h"

BoardField *board_fields[20][20];
ReversiRules *rules;
UserInterface *UserInt;

int main(int argc, char *argv[]){

    new OthelloGUI(argc, argv);
}
