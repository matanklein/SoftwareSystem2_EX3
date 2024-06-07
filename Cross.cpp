#include "Cross.hpp"

namespace catan{

    void Cross::setData(vector<int> neighborsCross, int id){
        this->hasOwner = false;
        this->neighborsCross = neighborsCross;
        this->id = id;
    }
}