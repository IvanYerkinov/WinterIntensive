#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include <gameengine.h>
#include <logistics.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTextBrowser* getMainBrowser();
    QTextBrowser* getSideBrowser();

    void update_console();

private slots:
    void on_inputButton_clicked();

private:
    Ui::MainWindow *ui;
    GameEngine *_ge;
};
#endif // MAINWINDOW_H
