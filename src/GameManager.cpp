#include "GameManager.h"
#include <QDebug>
#include "mainwindow.h"


GameManager::GameManager(MainWindow* mainWindow):mainWindow(mainWindow)
{
    mainWindow->toggleRestartButton(false);
}

void GameManager::MakeSelection(QString selectionName)
{   
    QString toPrint;
     switch(ChoiceMap.at(selectionName))
     {
        case e_Options::Rock: toPrint = "Rock";
        case e_Options::Paper: toPrint = "Paper";
        case e_Options::Scissors: toPrint =  "Scissors";
        default: toPrint =  "Unknown";
    }
    qDebug() << "Selection made: "<< selectionName<< toPrint;
}