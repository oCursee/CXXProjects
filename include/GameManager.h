#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QString>
#include <vector>
#include <map>
#include "mainwindow.h"

enum class e_GameState
{
    Ready,
    inProgress,
    Ended
};
enum class e_Options
{ // For mapping
    None,
    Rock,
    Paper,
    Scissors
};
const std::map<QString, e_Options> ChoiceMap{
    {"Rock", e_Options::Rock},
    {"Paper", e_Options::Paper},
    {"Scissors", e_Options::Scissors},
};

class GameManager
{
private:
    MainWindow *mainWindow;
    e_GameState GameState = e_GameState::Ready; // Ready, Ended
    e_Options LastUserPlay = e_Options::None;  // Try and make some simple weighted pattern recoginition.
    e_Options PlayingChoice;
    e_Options botChoice;
public:
    GameManager(MainWindow *mainWindow);
    ~GameManager();
    void ResetGameState();
    void MakeSelection(QString selectionName);
    void BeginGame();
    bool IsUserWinner();
    e_Options GenerateChoice();
    QString NameFromEnum(e_Options inputEnum);

   



};

#endif // GAMEMANAGER_H