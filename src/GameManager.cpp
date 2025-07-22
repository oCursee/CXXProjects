#include "GameManager.h"
#include <QDebug>
#include "mainwindow.h"


GameManager::GameManager(MainWindow* mainWindow):mainWindow(mainWindow)
{
    mainWindow->toggleRestartButton(false);
}

void GameManager::MakeSelection(QString selectionName)
{

}