#ifndef ROOM_H
#define ROOM_H

#include<QString>
#include<QVector>
#include"entity.h"


class Room
{
public:
    Room(QString name, QString desc, QString prev, int numExit, int numInter);
    Room();

    void init();
    void output();
    void preview();

    QString& getName()
    {
        return _name;
    }

    int& getSearchables()
    {
        return _numInter;
    }

    int& getExits()
    {
        return _numExit;
    }

    QVector<Room>& getExitRooms()
    {
        return _exits;
    }

    QVector<Searchable>& getInterior()
    {
        return _interior;
    }

private:
    QString _name;
    QString _description;
    QString _preview;
    QVector<Searchable> _interior;

    int _numExit;
    int _numInter;

    QVector<Room> _exits;

};

#endif // ROOM_H
