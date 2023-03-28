#include <iostream>
using namespace std;
#include <string>

#pragma once
namespace ariel{
    class Player{
        public:
            Player(string);
            int stacksize();
            int cardesTaken();
            int winRate();
            bool inGame();
    };
}