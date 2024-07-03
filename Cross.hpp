/*
   email- matank214@gmail.com
*/

#ifndef CROSS_HPP
#define CROSS_HPP

#include <vector>
#include "Definition.hpp"
#include "Player.hpp"
using namespace std;

class Cross
{
private:
    Player* owner;
    bool hasOwner;
    vector<int> neighborsCross;
    int id; // the serial number of the cross
    int type; // settlement, city, empty

public:
    Cross() : owner(nullptr), hasOwner(false), id(0), type(isempty){};
    void setData(vector<int> neighborsCross, int id);
    Player* getOwner(){
        return owner;
    }
    void setOwner(Player* ownerp){
        this->owner = ownerp;
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
};

#endif