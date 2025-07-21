#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QString>
#include <vector>
#include <map>

enum class e_GameState{
    Ready,
    Ended
};
enum class e_Options{ // For mapping
    Rock,
    Paper, 
    Scissors
};
enum class e_PlayRock{ 
    Scissors = 0,
    Rock = 1,
    Paper = 2, 
};

class GameManager{
    private:
        e_GameState GameState = e_GameState::Ready; // Ready, Ended
        QString LastUserPlay; // Try and make some simple weighted pattern recoginition.
        const std::map<std::string, e_Options> ChoiceMap{
            {"Rock", e_Options::Rock},
            {"Paper", e_Options::Paper},
            {"Scissors", e_Options::Scissors},
        };

    
    public: 
        GameManager(); // Constructor to hide button.
        void ResetGameState();
        void MakeSelection();

};




#endif //GAMEMANAGER_H