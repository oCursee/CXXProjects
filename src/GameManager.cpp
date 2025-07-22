#include "GameManager.h"
#include <QDebug>
#include "mainwindow.h"
#include <cstdlib>
#include <ctime>


GameManager::GameManager(MainWindow* mainWindow):mainWindow(mainWindow)
{
    mainWindow->toggleRestartButton(false);
}

void GameManager::MakeSelection(QString selectionName)
{   
    if (this->GameState == e_GameState::inProgress){return;} // If game is already in progress stops selections for whatever race conditions.
    this->GameState = e_GameState::inProgress;
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
    this->botChoice = this->GenerateChoice();
    QString botChoicetoString = this->NameFromEnum(this->botChoice);
    bool userWon = this->IsUserWinner();
    if (userWon){
        qDebug() << "WINNER: Bot Picked" << botChoicetoString;
    }
    else
    {
        qDebug() << "LOSER: Bot Picked " << botChoicetoString;
    }
    this->GameState = e_GameState::Ended;
}


e_Options GameManager::GenerateChoice()
{
    srand(time(0));
    int randomNum = 1 + (rand() % 4); 
    switch(randomNum){
       case 1: return e_Options::Rock; 
       case 2: return e_Options::Paper; 
       case 3: return e_Options::Scissors; 
    }   
}

bool GameManager::IsUserWinner()
{
    switch(this->PlayingChoice)
    {
        case e_Options::Rock: 
            if (this->botChoice == e_Options::Rock){return false;} else 
            if (this->botChoice == e_Options::Paper){return false;} else
            if (this->botChoice == e_Options::Scissors){return true;}
        case e_Options::Paper: 
            if (this->botChoice == e_Options::Rock){return true;} else 
            if (this->botChoice == e_Options::Paper){return false;} else
            if (this->botChoice == e_Options::Scissors){return false;}
        case e_Options::Scissors: 
            if (this->botChoice == e_Options::Rock){return false;} else 
            if (this->botChoice == e_Options::Paper){return true;} else
            if (this->botChoice == e_Options::Scissors){return false;}
        
    }
}

QString GameManager::NameFromEnum(e_Options inputEnum)
{
     for (const auto& pair: ChoiceMap)
    {
        if (pair.second == inputEnum)
        {
            return pair.first;
        }
    }
}
GameManager::~GameManager()
{
    delete this;
}