/**
 * Main file contains main method for GUI version of Othello.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#include "GUI/OthelloGUI.h"
#include "UserInterface.h"


BoardField *board_fields[20][20];
ReversiRules *rules;
UserInterface *UserInt;

/**
 * Main method which creates and runs OthelloGUI class.
 * @return 0 when ends without error
 */
int main(int argc, char *argv[]){

    new OthelloGUI(argc, argv);
    return 0;
}
