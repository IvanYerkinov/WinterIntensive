#ifndef PLAYER_H
#define PLAYER_H

#include"entity.h"
#include<QString>
#include<QRandomGenerator>
#include"textFunctions.h"


class Player
{
public:
    Player(QString name);
    Player();
    void initialise();
    void generateStats();



    int& getmaxhp()
    {
        return _maxhp;
    }
    int& getmaxmp()
    {
        return _maxmp;
    }
    int& getstr()
    {
        return _str;
    }
    int& getdex()
    {
        return _dex;
    }
    int& getcon()
    {
        return _con;
    }
    int& getint()
    {
        return _int;
    }
    int& getwis()
    {
        return _wis;
    }
    int& getcha()
    {
        return _cha;
    }

private:
    QString _name, _class;
    int _hp, _maxhp, _mp, _maxmp, _str, _dex, _con, _int, _wis, _cha;

};

#endif // PLAYER_H
