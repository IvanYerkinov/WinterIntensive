#include "player.h"


Player::Player(QString name)
    : _name(name)
{
    generateStats();
}

Player::Player()
{

}


void Player::generateStats()
{
    QRandomGenerator *gen = QRandomGenerator::global();
    _str = gen->generate() % 16 + 3;
    _dex = gen->generate() % 16 + 3;
    _con = gen->generate() % 16 + 3;
    _wis = gen->generate() % 16 + 3;
    _int = gen->generate() % 16 + 3;
    _cha = gen->generate() % 16 + 3;
    _maxhp = _con + 20;
    _hp = _maxhp;
    _maxmp = _wis + 10;
    _mp = _maxmp;

    delete gen;
}
