#include "textFunctions.h"

using namespace Textmanip;

QVector<Text> *Text::_list = new QVector<Text>;

void Textmanip::insertText(QTextBrowser *textdisplay, Text text, bool indent)
{
    textdisplay->setTextColor(text.getColor());
    textdisplay->insertPlainText(text.getText());
    if(indent == 1){ textdisplay->insertPlainText("\n"); }

    return;
}

void Textmanip::insertText(Text text, bool indent)
{
    if(indent == 1){ Text::getList()->push_back(Text("\n")); }
    Text::getList()->push_back(text);
}

void Textmanip::clearText()
{
    Text::getList()->clear();
}

void Textmanip::clearText(QTextBrowser *textdisplay)
{
    textdisplay->setText("");
}

void Textmanip::showText(QTextBrowser *textdisplay)
{
    textdisplay->setText("");
    for(Text t : *Text::getList())
    {
        insertText(textdisplay, t);
    }
}
