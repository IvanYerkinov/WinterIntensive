#ifndef TEXTFUNCTIONS_H
#define TEXTFUNCTIONS_H
#include<QTextBrowser>
#include<QString>
#include<QColor>
#include<QVector>
#include<QThread>

class Text
{
public:
    Text(QString text = "", QColor color = QColor(190, 190, 190))
        : _text(text), _textcolor(color)
    {
    }

    QString& getText()
    {
        return _text;
    }

    QColor& getColor()
    {
        return _textcolor;
    }

    static QVector<Text>* getList()
    {
        return _list;
    }

private:
    QString _text;
    QColor _textcolor;

    static QVector<Text> *_list;

};

namespace Textmanip
{

void insertText(QTextBrowser *textdisplay, Text text, bool indent=0);

void insertText(Text text, bool indent=0);

void clearText();

void clearText(QTextBrowser *textdisplay);

void showText(QTextBrowser *textdisplay);


}

#endif // TEXTFUNCTIONS_H
