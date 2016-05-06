#-------------------------------------------------
#
# Project created by QtCreator 2016-04-24T22:57:18
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hra2016
TEMPLATE = app


SOURCES +=\  
    src/board/BoardField.cpp \
    src/gameObj/Game.cpp \
    src/gameObj/ReversiRules.cpp \
    src/GUI/OthelloGUI.cpp \
    src/board/Board.cpp \
    src/board/Disc.cpp \
    src/GUI/Chooseboardsize.cpp \
    src/GUI/GameLevel.cpp \
    src/GUI/MainMenu.cpp \
    src/GUI/PlayArea.cpp \
    src/GUI/PlayAreaIcon.cpp \
    src/GUI/Settings.cpp \
    src/gameObj/Backup.cpp \
    src/GUI/BoardFieldLabel.cpp \
    src/GUI/Images.cpp \
    src/CreateGameOverMsg.cpp \
    src/main-gui.cpp
  

HEADERS  += \
    src/board/Board.h \
    src/gameObj/Game.h \
    src/board/Disc.h \
    src/GUI/ChooseBoardSize.h \
    src/GUI/GameLevel.h \
    src/GUI/MainMenu.h \
    src/GUI/OthelloGUI.h \
    src/GUI/PlayArea.h \
    src/GUI/PlayAreaIcon.h \
    src/GUI/Settings.h \
    src/UserInterface.h \
    src/gameObj/Backup.h \
    src/GUI/BoardFieldLabel.h \
    src/GUI/Images.h \
    src/CreateGameOverMsg.h
    

FORMS    += \
    src/GUI/ChooseBoardSize.ui \
    src/GUI/GameLevel.ui \
    src/GUI/MainMenu.ui \
    src/GUI/PlayArea.ui \
    src/GUI/Settings.ui
    

RESOURCES += \
    src/resources.qrc
