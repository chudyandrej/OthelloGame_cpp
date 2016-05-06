/**
 * Defines user interface pure virtual methods.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#ifndef USERINTERFACE_H
#define USERINTERFACE_H


class UserInterface{
public:
    UserInterface(){}
    virtual ~UserInterface(){}
    virtual void changeDisc(int x, int y, bool isWhite)=0;
    virtual void deleteDisc(int x, int y)=0;
    virtual void freezeField(int x, int y)=0;
    virtual void unFreezeField(int x, int y)=0;
    virtual void setGameState(int score1, int score2, bool isWhite)=0;

};

#endif // USERINTERFACE_H
