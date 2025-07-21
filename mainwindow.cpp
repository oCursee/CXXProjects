#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GameManager.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Rock-Paper-Scissors");
    GameManager* GameInstance = new GameManager(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toggleRestartButton(bool toggleType)
{
    this->ui->restartButton->setVisible(toggleType);
}
