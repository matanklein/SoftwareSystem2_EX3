#include "Player.hpp"
#include "Board.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "Definition.hpp"
#include <cstdlib>
#include <ctime>
#include <random>
#include "Card.hpp"
using namespace std;


class Catan{
    Player p1;
    Player p2;
    Player p3;
    catan::Board board;
    vector<Player> Players;
    int turn;
    bool isGameEnd;

    public:
        Catan(string name1, string name2, string name3);
        ~Catan();
        void rollDice();

        void endTurn();

        void buildRoad(Player& player, int i, int j);
        void buildSettlement(Player& player, int place);
        void buildCity(Player& player, int place);

        void startGame();
        
        // trade between players of resources
        void trade(Player& player1, Player& player2, int resource1,int amount1, int resource2, int amount2);
        
        void buyDevelopmentCard(Player& player);

        int getAvailableDevelopmentCard(int card);

        void printBoard();

        void useDevelopmentCard(Player& player, int card);

        void Monopoly(Player& player, int resource);

};