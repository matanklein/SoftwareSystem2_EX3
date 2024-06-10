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
    int id;
    int type;

public:
    Cross();
    void setData(vector<int> neighborsCross, int id);
    Player& getOwner(){
        return owner;
    }
    void setOwner(Player& owner){
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
    ~Cross();
};
