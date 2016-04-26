#include "src/GUI/othellogui.h"
#include "src/board/Board.h"
#include "src/gameObj/Game.h"

BoardField *board_fields[20][20];
ReversiRules *rules;

int main(int argc, char *argv[]){

    new OthelloGUI(argc, argv);

}
