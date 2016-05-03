#include "GUI/OthelloGUI.h"
#include "UserInterface.h"

#include "CLI/Othellocli.h" //just temp till not new main created

BoardField *board_fields[20][20];
ReversiRules *rules;
UserInterface *UserInt;

int main(int argc, char *argv[]){

    new OthelloGUI(argc, argv);
    //new OthelloCLI();
}
