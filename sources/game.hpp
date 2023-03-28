#pragma once
#include"player.hpp"
#include <iostream>
namespace ariel{
    class Game{
       public:
        Game(Player&,Player&);
        bool playTurn();
        string printLastTurn();
        bool playAll();
        string printWiner();
        string printLog();
        string printStats();
    };
}