#ifndef ENTITY_H
#define ENTITY_H

#include "textFunctions.h"

class Entity
{
public:
    Entity(Text name, QString type);
    Entity();

    Text& getName()
    {
        return _name;
    }

protected:
    Text _name;
    QString _type;

};

class Searchable : public Entity
{
public:
    Searchable(Text name);
    Searchable();

    int search();

    bool& getSearched()
    {
        return _searched;
    }
private:
    bool _searched;

};

#endif // ENTITY_H
