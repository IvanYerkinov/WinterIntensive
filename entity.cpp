#include "entity.h"

Entity::Entity(Text name, QString type)
    : _name(name), _type(type)
{

}

Entity::Entity()
{

}


Searchable::Searchable(Text name) : Entity(name, "SEARCH"), _searched(false)
{

}

Searchable::Searchable()
{

}
