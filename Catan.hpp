#include "Player.hpp"
#include "Board.hpp"

class catan{
    catan::Player p1;
    catan::Player p2;
    catan::Player p3;
    Board board;

    public:
        catan(string name1, string name2, string name3);
        ~catan();
        void rollDice();
};