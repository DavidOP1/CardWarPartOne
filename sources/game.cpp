#include <iostream>
#include "game.hpp"
#include "player.hpp"
namespace ariel{
        Game::Game(Player & p1,Player & p2){int i =0;};
        bool Game::playTurn(){return false;};
        string Game::printLastTurn(){return "";};
        bool Game::playAll(){return false;};
        string Game::printWiner(){return "";};
        string Game::printLog(){return "";};
        string Game::printStats(){return "";};
}