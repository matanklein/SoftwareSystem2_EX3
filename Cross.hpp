#ifndef CROSS_HPP
#define CROSS_HPP

#include <vector>
#include "Definition.hpp"
#include "Player.hpp"
using namespace std;

class Cross
{
private:
    Player& owner;
    bool hasOwner;
    vector<int> neighborsCross;
    int id; // the serial number of the cross
    int type; // settlement, city, empty

public:
    Cross();
    Cross(const Cross& cross);
    void setData(vector<int> neighborsCross, int id);
    Player& getOwner(){
        return owner;
    }
    void setOwner(Player& owner){
        delete &this->owner;
        this->owner = owner;
        this->hasOwner = true;
    }
    bool getHasOwner(){
        return hasOwner;
    }
    int getId(){
        return id;
    }
    int getType(){
        return type;
    }
    void setType(int type){
        this->type = type;
    }

    vector<int>& getNeighborsCross(){
        return neighborsCross;
    }
    ~Cross();
    Cross& operator=(const Cross& cross);
};

#endif