#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GameManager.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Rock-Paper-Scissors");
    GameManager* GameInstance =  new GameManager(this);
    connect(this->ui->rockButton, &QPushButton::clicked, this, [GameInstance](){
        GameInstance->MakeSelection("Rock");
    });
    connect(this->ui->paperButton, &QPushButton::clicked, this, [GameInstance](){
        GameInstance->MakeSelection("Paper");
    });
    connect(this->ui->scissorsButton, &QPushButton::clicked, this, [GameInstance](){
        GameInstance->MakeSelection("Scissors");
    });
    connect(this->ui->restartButton, &QPushButton::clicked, this, [GameInstance](){
        GameInstance->ResetGameState();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetResponseText()
{
    this->ui->responseLine->setText("Make your move!");
}
void MainWindow::setResponseText(QString headerText)
{
    this->ui->responseLine->setText(headerText);
}
void MainWindow::toggleRestartButton(bool toggleType)
{
    this->ui->restartButton->setVisible(toggleType);
}
