#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>
#include <iostream>
#include "Definition.hpp"
#include "Card.hpp"
using namespace std;

class Player
{
private:
    string name;
    vector<int> resources;
    int points;
    int availableRoads;
    int availableSettlements;
    int id;
    vector<Card*> developmentCards;
    int knights;

public:
    Player();
    Player(string name, int id);
    ~Player(){
    }

    void addResource(int resource);
    void addResource(int resource, int amount);
    void removeResource(int resource);
    void removeResource(int resource, int amount);
    
    int getPoints(){
        return points;
    }
    string getName(){
        return name;
    }
    int getId(){
        return id;
    }
    int getAvailableRoads(){
        return availableRoads;
    }
    void setAvailableRoads(int availableRoads){
        this->availableRoads = availableRoads;
    }
    void addAvailableRoads(int availableRoads){
        this->availableRoads += availableRoads;
    }
    int getAvailableSettlements(){
        return availableSettlements;
    }
    vector<int> getResources(){
        return resources;
    }
    void setPoints(int points){
        this->points = points;
    }

    void addDevelopmentCard(Card* card);

    void useDevelopmentCard(string type);

    bool hasDevelopmentCard(string type);

    void removeDevelopmentCard(string type);

    void buildRoad();

    void buildSettlement();

    void buildCity();

    void buyDevelopmentCard();

    int amountOfallResources();
    void roll7();

    void addKnight();
    void removeKnight();

    void printResources();

    void operator=(const Player& player);

};

#endif