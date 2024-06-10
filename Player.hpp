#include <vector>
#include <string>
#include <iostream>
#include "Definition.hpp"
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

public:
    Player();
    Player(string name, int id);
    ~Player();

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
    int getAvailableSettlements(){
        return availableSettlements;
    }
    vector<int> getResources(){
        return resources;
    }
    void setPoints(int points){
        this->points = points;
    }

    void buildRoad();

    void buildSettlement();

    void buildCity();

};
