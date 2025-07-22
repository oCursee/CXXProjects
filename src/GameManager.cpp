#include "GameManager.h"
#include <QDebug>
#include "mainwindow.h"


GameManager::GameManager(MainWindow* mainWindow):mainWindow(mainWindow)
{
    mainWindow->toggleRestartButton(false);
}

void GameManager::MakeSelection(QString selectionName)
{   
    
    for (const auto& pair: ChoiceMap)
    {
        if (pair.first == selectionName)
        {
            this->PlayingChoice = pair.second;
            break;
        }
    }
    this->BeginGame();
    
}

void GameManager::BeginGame()
{
    qDebug() << static_cast<int>(this->LastUserPlay);

    if (this->LastUserPlay == e_Options::None){
        qDebug() << "Firstt user play randomize choice";
    }
    else
    {
        qDebug() <<"Not first choice";
    }
}

GameManager::~GameManager()
{
    delete this;
}