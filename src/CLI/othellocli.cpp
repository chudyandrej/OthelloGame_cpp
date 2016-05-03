#include "Othellocli.h"


OthelloCLI::OthelloCLI(){
    //default
    player1Name = "Player1";
    player2Name = "Player2";
    computerName = "Computer";

    getSettings();

    //create board
    for(int i=0; i<boardSize; i++){
        for(int j=0; j<boardSize; j++){
            boardFields[i][j] = '-';
        }
    }

    //init game
    newGame = new Game(boardSize, 0, 0, 0, this);

    player1 = new Player(true, player1Name);
    newGame->addPlayer(player1);

    if(singlePlayer){
        player2 = new Player(false, gameMode, computerName);
    }
    else{
        player2 = new Player(false, player2Name);
    }

    newGame->addPlayer(player2);


    //initialize game state
    setGameState(2, 2, false);

    commandListener();

    std::cout << "wtf\n";
}


void OthelloCLI::getSettings(){
    std::cout << "Do you want to play single player? [y/n]\n";

    char choice;
    std::cin >> choice;
    if(choice == 'y'){
        singlePlayer = true;

        while(true){
            std::cout << "Choose mode:\n 1 - beginner\n 2 - advanced\n";
            std::cin >> gameMode;
            if(gameMode == 1 || gameMode == 2 ){
                break;
            }
            else{
                std::cout << "Wrong value!\n";
            }
        }


    }

    while(true){
        std::cout << "Set board size\n [6/8/10/12]\n";
        std::cin >> boardSize;
        if(boardSize == 6 || boardSize == 8 || boardSize == 10 || boardSize == 12){
            break;
        }
        else{
            std::cout << "Wrong value!\n";
        }
    }

}

void OthelloCLI::commandListener(){
    int x;
    char y;

    while(true){
        printBoard();

        std::cout << "Where would you like to put disc?\n";

        while(true){
            while(true){
                std::cout << "Write a letter of column\n";
                std::cin >> y;

                y = y-65; //convert char to number
                if(y < 0 || y > boardSize){
                    std::cout << "Wrong column\n";
                }else{
                    break;
                }
            }

            while(true){
                std::cout << "Write number of row\n";
                std::cin >> x;
                if(x < 0 || x > boardSize){
                    std::cout << "Wrong row\n";
                }else{
                    break;
                }
            }


            Player *tmp = newGame->getCurrentPlayer();

            if(tmp->putDisc(x, y)){
                newGame->nextPlayer();

                if(newGame->getIsGameOver()){
                    //showGameOverDialog();
                }
                break;
            }
            else{
                std::cout << "Can't put disc there! Try again\n";
                printBoard();
            }
        }

    }

}

void OthelloCLI::printBoard(){
    std::cout << "\n";

    std::string name = newGame->getCurrentPlayer()->getName();
    std::cout << "On turn: " << name << "\n";
    std::string disc = (newGame->getCurrentPlayer()->getIsWhite()) ? "o" : "x";
    std::cout << "Player's disc: " << disc << "\n";

    std::cout << "SCORE: " << player1->getName() << " " << score1 << " : "
                           << score2 << " " << player2->getName() << "\n";

    for(int i=0; i < boardSize; i++){
        std::cout << (char)(i+65) << " ";
    }
    std::cout << "\n";
    for(int i=0; i<boardSize; i++){
        for(int j=0; j<boardSize; j++){
            std::cout << boardFields[i][j] << " ";
        }
        std::cout << " " << i << "\n";
    }

    std::cout << "\n";
}



void OthelloCLI::changeDisc(int x, int y, bool isWhite){
    boardFields[x][y] = (isWhite) ? 'o' : 'x';
}

void OthelloCLI::deleteDisc(int x, int y){
    boardFields[x][y] = '-';
}

void OthelloCLI::freezeField(int x, int y){
    //friezing fields is for CLI not supported
}

void OthelloCLI::unFreezeField(int x, int y){
    //friezing fields is for CLI not supported
}

void OthelloCLI::setGameState(int score1, int score2, bool isWhite){
    this->score1 = score1;
    this->score2 = score2;
    this->onTurn = isWhite;
}
