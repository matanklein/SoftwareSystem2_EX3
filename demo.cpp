/*
   email- matank214@gmail.com
*/

#include <iostream>
#include <vector>
#include <string>
#include "Definition.hpp"
#include "Cross.hpp"
#include "Plot.hpp"
#include "Player.hpp"
#include "Card.hpp"
#include "Catan.hpp"
#include "Board.hpp"

using namespace std;


int main(){

    Catan catan("Player1", "Player2", "Player3");

    for(size_t i = 0; i < 3; i++){
        cout << "Choose the place for the settlement for Player " << i+1 << endl;
        int place;
        cin >> place;
        catan.buildSettlement(catan.getPlayer(i), place);

        cout << "Choose the place for the road for Player " << i+1 << endl;
        int l, m;
        cin >> l >> m;
        catan.buildRoad(catan.Players[i], l, m);
        cout << catan.getPlayer(i)->getName() << " has " << catan.getPlayer(i)->getPoints() << " points" << endl;
    }

    for(size_t i = 0; i < 3; i++){
        cout << "Choose place for the second settlement of Player " << i+1 << endl;
        int place;
        cin >> place;
        catan.buildSettlement(catan.Players[i], place);

        cout << "Choose place for the second road of player  " << i+1 << endl;
        int l, m;
        cin >> l >> m;
        catan.buildRoad(catan.Players[i], l, m);
        cout << catan.getPlayer(i)->getName() << " has " << catan.getPlayer(i)->getPoints() << " points" << endl;
    }

    cout << "-=-=-=-=-=-=-=-=-" << endl;
    catan.startGame();
    cout << "-=-=-=-=-=-=-=-=-" << endl;
    

    // first round
    for(size_t i = 0; i < 3; i++){
        catan.rollDice();
        catan.Players[i]->printResources();
        int choice = -1;
        while(choice != 0){
            cout << "Player " << i+1 << " choose an option: " << endl;
            cout << "1. Build Road" << endl;
            cout << "2. Build Settlement" << endl;
            cout << "3. Build City" << endl;
            cout << "4. Buy Development Card" << endl;
            cout << "5. Use Development Card" << endl;
            cout << "6. Trade" << endl;
            cout << "0. End Turn" << endl;

            cin >> choice;
            int place;

            switch(choice){
                case 1:
                    cout << "Choose the place for the road" << endl;
                    int l, m;
                    cin >> l >> m;
                    catan.buildRoad(catan.Players[i], l, m);
                    break;
                case 2:
                    cout << "Choose the place for the settlement" << endl;
                    cin >> place;
                    catan.buildSettlement(catan.Players[i], place);
                    break;
                case 3:
                    cout << "Choose the place for the city" << endl;
                    cin >> place;
                    catan.buildCity(catan.Players[i], place);
                    break;
                case 4:
                    catan.buyDevelopmentCard(catan.Players[i]);
                    break;
                case 5:
                    cout << "Choose the development card to use" << endl;
                    int card;
                    cin >> card;
                    catan.useDevelopmentCard(catan.Players[i], card);
                    break;
                case 6:
                    cout << "Choose the player to trade with" << endl;
                    int player;
                    cin >> player;
                    cout << "Choose the resource to give" << endl;
                    int resource1;
                    cin >> resource1;
                    cout << "Choose the amount to give" << endl;
                    int amount1;
                    cin >> amount1;
                    cout << "Choose the resource to take" << endl;
                    int resource2;
                    cin >> resource2;
                    cout << "Choose the amount to take" << endl;
                    int amount2;
                    cin >> amount2;
                    catan.trade(catan.Players[i], catan.Players[player-1], resource1, amount1, resource2, amount2);
                    break;
                case 0:
                    catan.endTurn();
                    break;
                default:
                    cout << "Invalid choice" << endl;
            }
        }
    }


    return 0;
}