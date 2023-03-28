#include "doctest.h"
#include <iostream>
#include "sources/player.hpp"
#include "sources/game.hpp"
using namespace std;
using namespace ariel;
// Create two players with their names 

TEST_CASE("TEST CASE 1"){
    Player p1("Alice");
    Player p2("Bob");
    Player p3("David");
    Player p4("TAl");
    Game game(p1,p2);
    Game game2(p3,p4); 
    CHECK(((p1.stacksize()==26&&p1.cardesTaken()==0)&&(p2.stacksize()==26&&p2.cardesTaken()==0)));
    CHECK(game.playTurn());
    CHECK(game2.playAll());
    game.playAll();
    CHECK((p1.inGame()&&p2.inGame()&&!p3.inGame()));
    CHECK(!game.playTurn());//since the game is done cant play more turns.
    if(p1.cardesTaken()==p2.cardesTaken()){ //A tie is only possible if both players have same amount of cards, 
                                    //meaning they won same amount of cards. doesnt mean they have the same
                                    //winRate , can win multiple cards in war which is one win.
        CHECK((p1.stacksize()==0&&p1.stacksize()==0));
        CHECK((game.printWiner()=="TIE"));
        CHECK((p1.winRate()==p2.winRate()));
    }else{
    CHECK((game.printWiner()=="Alice" || game.printWiner()=="Bob"));
    CHECK((p1.cardesTaken() == 26 || p2.cardesTaken() == 26));
    CHECK(((p1.stacksize()+p1.cardesTaken()==26)||(p2.stacksize()+p2.cardesTaken()==26)));
    }
    //CHECK((game.playTurn()==result));
    
}
TEST_CASE("TEST CASE 2"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();
    string lastTurns=game.printLastTurn();
    CHECK((game.printLog()==lastTurns));
    CHECK(((p1.stacksize()==25 && p1.cardesTaken()==1)||(p2.stacksize()==25 && p2.cardesTaken()==1)));

    for(int i=0 ; i<5;i++){
        game.playTurn();
        lastTurns = "\n" + game.printLastTurn();
        CHECK((game.printLog()==lastTurns));
    }

    CHECK((game.printWiner()=="")); //empty string since there are still no winners.

}

TEST_CASE("FULL GAME"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK(game.playTurn());
    for(int i=0;i<26;i++){//checking if the game lasts maximum 26 turns.
        if(game.printWiner()!=""){
            break;
        }
        game.playTurn();
    }
    CHECK(!game.playAll());//cant play anymore
    CHECK((game.printWiner()=="Alice"||game.printWiner()=="Bob" || game.printWiner()=="TIE"));
    CHECK((!p1.stacksize()&&!p2.stacksize()));
}