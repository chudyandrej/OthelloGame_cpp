#include "Othellocli.h"


OthelloCLI::OthelloCLI(){
    //default
    player1Name = "Player1";
    player2Name = "Player2";
    computerName = "Computer";

    int load = getSettings();
    initNewGame();

    if(load == 1){
        newGame->backupGame->loadGame();
    }

    commandListener();
}


int OthelloCLI::getSettings(){
    std::cout << "1 = Single Player\n2 = Multiplayer\n3 = Load Game\n";

    int choice;
    std::cin >> choice;
    if(choice == 1){
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
    else if(choice == 3){

        int level1, level2;

        //init loading of game
        std::tie(boardSize, player1Name, level1, player2Name, level2) = Backup::loadSettings();

        if(level2 != 0){    //it's computer player
            gameMode = level2;
            computerName = player2Name;
        }

        return 1;
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
    return 0;
}

void OthelloCLI::initNewGame(){

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
}

void OthelloCLI::commandListener(){
    int x;
    char y;

    while(true){
        printBoard();

        std::cout << "Where would you like to put disc?\n";

        while(true){
            while(true){
                std::cout << "Write a letter of column. [x = exit game; s = save game]\n";
                std::cin >> y;

                if(otherOption(y)){ continue; }

                y = y-65; //convert char to number
                if(y < 0 || y > boardSize){
                    std::cout << "Wrong column\n";
                }else{
                    break;
                }
            }

            while(true){                
                std::cout << "Write number of row. [x = exit game; s = save game]\n";
                std::cin >> x;

                 if(otherOption((char)y)){ continue; }

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
                std::cout << "\nCan't put disc there!!! Try again\n";
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

void OthelloCLI::printGameOverMessage(){
    std::string msg;
    if (score1 == score2){      //stalemate
        msg = "Stalemate! Winners:\n  -"+player1->getName()+"\n  -"+player2->getName()+"\nScore: "+std::to_string(score1);
    }
    else if(player1->getIs_pc() || player2->getIs_pc()){
        msg = PlayArea::createSinglePlayerGameOverMsg(score1, score2, player1, player2);
    }else{
        msg = PlayArea::createMultiPlayerGameOverMsg(score1, score2, player1, player2);
    }
    //std::replace( msg.begin(), msg.end(), '<br>', '\n');
    std::cout << msg << "\nWould you like to play again? [y/n]";

    char choice;
    std::cin >> choice;
    if(choice == 'y'){
        initNewGame();
    }
    exit(0);
}

bool OthelloCLI::otherOption(char x){

    if(x == 'e'){
        exit(0);
    }
    else if(x == 's'){
        //save game
        newGame->backupGame->serializeBackup();
        std::cout << "Game was successfuly saved\n";
        return true;
    }
    return false;
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
