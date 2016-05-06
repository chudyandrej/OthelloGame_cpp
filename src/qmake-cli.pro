#-------------------------------------------------
#
# Project created by QtCreator 2016-04-24T22:57:18
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hra2016-cli
TEMPLATE = app
 

SOURCES +=\  
    src/board/BoardField.cpp \
    src/gameObj/Game.cpp \
    src/gameObj/ReversiRules.cpp \
    src/board/Board.cpp \
    src/CLI/othellocli.cpp \
    src/board/Disc.cpp \
    src/gameObj/Backup.cpp \
    src/CreateGameOverMsg.cpp \
    src/main-cli.cpp 
  

HEADERS  += \
    src/board/Board.h \
    src/gameObj/Game.h \
    src/board/Disc.h \
    src/CLI/Othellocli.h \
    src/UserInterface.h \
    src/gameObj/Backup.h \
    src/CreateGameOverMsg.h
    

