#include "room.h"

Room::Room(QString name, QString desc, QString prev, int numExit, int numInter)
    : _name(name), _description(desc), _preview(prev), _numExit(numExit), _numInter(numInter)
{

}

Room::Room()
{

}

void Room::init()
{

    for(int i = 0; i < _numExit; i++)
    {
        _exits.append(Room("TEST", "test", "test2", 2, 2));
    }

    for(int i = 0; i < _numInter; i++)
    {
        _interior.append(Searchable(Text("Searchable", QColor(230, 230, 100))));
    }

}


void Room::output()
{
    Textmanip::insertText(Text("Room: " + _name));
    Textmanip::insertText(Text(_description), 1);
    Textmanip::insertText(Text(""), 1);
    Textmanip::insertText(Text("In this room there is: "), 1);
    for (int i = 0; i < _numInter; i++)
    {
        Textmanip::insertText(Text("a "));
        Textmanip::insertText(_interior[i].getName());
        Textmanip::insertText(Text(", "));
    }
    Textmanip::insertText(Text("This room connects to: "), 1);
    for (int i = 0; i < _numExit; i++)
    {
        Textmanip::insertText(Text(_exits[i].getName(), QColor(220, 60, 60)));
        Textmanip::insertText(Text(", "));
    }

}
