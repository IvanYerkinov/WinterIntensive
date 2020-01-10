#include "gameengine.h"

class MainWindow;

GameEngine::GameEngine()
    : _command(""), _gamerun(true)
{

}

void GameEngine::run()
{
    initialise_player();

    _current = Room("Starting Area", "A moderatly big room. Plainly decorated with a small lamp that provides light.", "test", 2, 2);

    _current.init();

    while(_gamerun == true)
    {
        loadRoomHud();
        QString choice = Cin();

        if(choice == "Search")
        {
            loadSearchHub();
        }
        else if (choice == "Go")
        {
            loadMoveHub();
        }
    }
}

void GameEngine::initialise_player()
{
    bool temp = 1;

    while(temp == 1){
    Textmanip::clearText();


    Textmanip::insertText(Text("Please name your character."));
    QString name = Cin();

    Textmanip::insertText(Text(name + "\n", QColor(200, 100, 200)), 1);
    _player = Player(name);
    QString stat;

    stat = QString::number(_player.getmaxhp());
    Textmanip::insertText(Text("HP: " + stat + "\n", QColor(200, 180, 180)));

    stat = QString::number(_player.getmaxmp());
    Textmanip::insertText(Text("MP: " + stat + "\n", QColor(180, 180, 200)));

    stat = QString::number(_player.getstr());
    Textmanip::insertText(Text("Strength: " + stat + "\n", QColor(205, 180, 180)));

    stat = QString::number(_player.getdex());
    Textmanip::insertText(Text("Dexterity: " + stat + "\n", QColor(180, 205, 180)));

    stat = QString::number(_player.getcon());
    Textmanip::insertText(Text("Constitution: " + stat + "\n", QColor(200, 200, 180)));

    stat = QString::number(_player.getint());
    Textmanip::insertText(Text("Intelligence: " + stat + "\n", QColor(200, 180, 200)));

    stat = QString::number(_player.getwis());
    Textmanip::insertText(Text("Wisdom: " + stat + "\n", QColor(180, 180, 220)));

    stat = QString::number(_player.getcha());
    Textmanip::insertText(Text("Charisma: " + stat + "\n", QColor(200, 200, 180)));

    Wait();



        Textmanip::insertText(Text("Are these stats ok? Y/N"), 1);

        QString choice = Cin();

        if(choice == "Y")
        {
            return;
        }
    }


}


void GameEngine::getCommand(QString com)
{
    _command = com;
}


QString GameEngine::Cin()
{
    while(_command == "")
    {
    }

    QString ret = _command;
    _command = "";
    return ret;
}

void GameEngine::Wait()
{
    _command = "wait83291";

    while(_command == "wait83291")
    {
    }

    _command = "";
    return;
}


void GameEngine::loadRoomHud()
{
    Textmanip::clearText();
    _current.output();

    Textmanip::insertText(Text(""), 1);
    Textmanip::insertText(Text("What would you like to do?"), 1);
    Textmanip::insertText(Text("'Search'   'Go'", QColor(80, 200, 80)), 1);
}

void GameEngine::loadSearchHub()
{
    while(true)
    {
    Textmanip::clearText();
    Textmanip::insertText(Text(""), 1);

    Textmanip::insertText(Text("Which of these would you like to search?"), 1);
    for(int i = 0; i < _current.getSearchables(); i++)
    {
        if(_current.getInterior()[i].getSearched() == 0)
        {
            Textmanip::insertText(Text(QString::number(i) + ": "), 1);
            Textmanip::insertText(Text(_current.getInterior()[i].getName()));
        }
    }
    Textmanip::insertText(Text("Choose one to search."), 1);

    QString choice = Cin();
    int ch = choice.toInt();
    if (ch < 0 || ch > _current.getSearchables())
    {
        return;
    }
    else
    {
        _current.getInterior()[ch].getSearched() = 1;
        _current.getInterior()[ch].getName().getColor() = QColor(180, 180, 180);
        return;
    }
    return;
    }
}


void GameEngine::loadMoveHub()
{
    Textmanip::clearText();
    Textmanip::insertText(Text(""), 1);

    Textmanip::insertText(Text("Where would you like to go?"), 1);
    for(int i = 0; i < _current.getExits(); i++)
    {
        Textmanip::insertText(Text(QString::number(i) + ": "), 1);
        Textmanip::insertText(Text(_current.getExitRooms()[i].getName(), QColor(200, 50, 50)));
    }
    QString choice = Cin();
    int ch = choice.toInt();
    if(ch < 0 || ch > _current.getExits())
    {
        return;
    }
    else
    {
        _current = _current.getExitRooms()[ch];
        _current.init();
        return;
    }
}
