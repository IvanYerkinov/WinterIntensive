#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include<QTextBrowser>
#include<QThread>
#include<QString>
#include"textFunctions.h"
#include"player.h"
#include"room.h"
#include"logistics.h"

class GameEngine : public QThread
{
public:
    GameEngine();

    void initialise_player();

    void getCommand(QString com);

    void loadRoomHud();

    void loadSearchHub();

    void loadMoveHub();

    QString Cin();

    void Wait();

protected:
       void run();

private:
    Room _current;
    Player _player;
    QString _command;

    bool _gamerun;


    QTextBrowser *_main;
    QTextBrowser *_side;


};

#endif // GAMEENGINE_H
