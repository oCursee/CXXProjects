#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QString>
#include <vector>
#include <map>
#include "mainwindow.h"

enum class e_GameState
{
    Ready,
    Ended
};
enum class e_Options
{ // For mapping
    Rock,
    Paper,
    Scissors
};
enum class e_PlayRock
{
    Scissors = 0,
    Rock = 1,
    Paper = 2,
};
const std::map<QString, e_Options> ChoiceMap{
    {"Rock", e_Options::Rock},
    {"Paper", e_Options::Paper},
    {"Scissors", e_Options::Scissors},
};

class GameManager
{
private:
    const MainWindow *mainWindow;
    e_GameState GameState = e_GameState::Ready; // Ready, Ended
    QString LastUserPlay;                       // Try and make some simple weighted pattern recoginition.

public:
    GameManager(MainWindow *mainWindow);
    void ResetGameState();
    void MakeSelection(QString selectionName);
};

#endif // GAMEMANAGER_H