#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mainBrowser->setText("Startup.\n");

    _ge = new GameEngine();
    _ge->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_inputButton_clicked()
{
    QString comm = ui->CommandInput->text();
    ui->CommandInput->setText("");
    _ge->getCommand(comm);

    update_console();

}

QTextBrowser* MainWindow::getMainBrowser()
{
    return ui->mainBrowser;
}

QTextBrowser* MainWindow::getSideBrowser()
{
    return ui->PlayerStatistics;
}


void MainWindow::update_console()
{
    Textmanip::showText(ui->mainBrowser);
}
