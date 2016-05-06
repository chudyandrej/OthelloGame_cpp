#include "Backup.h"


Backup::Backup(int boardSize, Game *game){
    this->boardSize = boardSize;
    this->game = game;
}

void Backup::createNewTurn(int x, int y, Player *pOnTurn){

    Point *point = new Point(x, y);
    newTurn = new BackupTurn(point, pOnTurn);

}

void Backup::addTurnedDisc(std::vector <BoardField*> turnedDiscs){

    newTurn->turnedDiscs.insert(newTurn->turnedDiscs.end(), turnedDiscs.begin(), turnedDiscs.end());
}

void Backup::addFrozenDisc(std::list<BoardField*> points){
    newTurn->frozenPoints = points;
}


void Backup::saveBackupRecord(){
    this->backupTurns.push_back(newTurn);

}

void Backup::serializeBackup(){
    std::ofstream output;
    output.open("saved_game.txt");

    output << game->white->getName() << ":" << ((game->white->getIs_pc()) ? "bot":"hum") << ":";
    output << ((game->white->getIs_pc()) ? std::to_string(game->white->level) :"0") <<"\n";
    output << game->black->getName() << ":" << ((game->black->getIs_pc()) ? "bot":"hum") << ":";
    output << ((game->black->getIs_pc()) ? std::to_string(game->black->level) :"0") <<"\n";

    output << std::to_string(rules->getSize()) << "\n";


    for(std::vector<BackupTurn*>::iterator it = backupTurns.begin(); it != backupTurns.end(); ++it){
        output << (((*it)->playerOnTurn->getIsWhite()) ? "w":"b") << "$" ;
        output << std::to_string((*it)->basePoint->x) << "," << std::to_string((*it)->basePoint->y) << "$";

        for(std::list<BoardField*>::iterator it1 = (*it)->frozenPoints.begin(); it1 != (*it)->frozenPoints.end(); ++it1){
            output << std::to_string((*it1)->row) << "," << std::to_string((*it1)->col)<<";";
        }

        output << "$";
        for(std::vector<BoardField*>::iterator it2 = (*it)->turnedDiscs.begin(); it2 != (*it)->turnedDiscs.end(); ++it2){
            output << std::to_string((*it2)->row) << "," << std::to_string((*it2)->col)<<";";
        }

        output << "\n";
    }

    output.close();
}

std::tuple<int, std::string, int, std::string, int> Backup::loadSettings(){
    std::ifstream input("saved_game.txt");

    std::string line;

    std::getline(input, line);  //player1 information
    std::vector<std::string> player1 = split(line, ':');

    std::getline(input, line);  //player2 information
    std::vector<std::string> player2 = split(line, ':');

    std::getline(input, line);  //boardSize
    int size = std::stoi(line);


    int level1 = (player1[1] == "hum") ? 0 : std::stoi(player1[2]);
    int level2 = (player2[1] == "hum") ? 0 : std::stoi(player2[2]);

    input.close();

    return std::make_tuple(size, player1[0], level1, player2[0], level2);
}

void Backup::loadGame(){
    std::ifstream input("saved_game.txt");

    std::string line;

    std::getline(input, line);  //player1 information
    std::getline(input, line);  //player2 information
    std::getline(input, line);  //boardSize

    while (std::getline(input, line)){  // each line = each turn
        std::vector<std::string> turnElements = split(line, '$');
        std::vector<std::string> basePointCoords = split(turnElements[1], ',');
        int baseX = std::stoi(basePointCoords[0]);
        int baseY = std::stoi(basePointCoords[1]);

        if(turnElements[0] == "w"){
            board_fields[baseX][baseY]->putDisc(new Disc(true));
            game->backupGame->createNewTurn( baseX, baseY, game->white);

        }else{
            board_fields[baseX][baseY]->putDisc(new Disc(false));
            game->backupGame->createNewTurn( baseX, baseY, game->black);
        }

        std::vector<std::string> turnedPoints = split(turnElements[3], ';');
        std::vector<BoardField*> turnedDisc;
        for(std::vector<std::string>::iterator it = turnedPoints.begin(); it != turnedPoints.end(); ++it){
            std::vector<std::string> turnedPoint = split((*it), ',');
            turnedDisc.push_back(board_fields[std::stoi(turnedPoint[0])][std::stoi(turnedPoint[1])]);
        }
        game->backupGame->addTurnedDisc(turnedDisc);
        rules->turn_discs(turnedDisc);
        game->backupGame->saveBackupRecord();

    }

    input.close();

}


BackupTurn::BackupTurn(Point *basePoint, Player *pOnTurn){
    this->basePoint = basePoint;
    this->playerOnTurn = pOnTurn;
}

std::vector<std::string> Backup::split(std::string input, char delimiter) {
    std::stringstream stream_message(input);
    std::string segment;
    std::vector<std::string> seglist;

    while(std::getline(stream_message, segment, delimiter)) {
        seglist.push_back(segment);
    }
    return seglist;
}


