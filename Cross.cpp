#include "Cross.hpp"

    void Cross::setData(vector<int> neighborsCross, int id){
        this->hasOwner = false;
        this->neighborsCross = neighborsCross;
        this->id = id;
        this->type = isempty;
    }

    Cross& Cross::operator=(const Cross& cross){
        this->owner = cross.owner;
        this->hasOwner = cross.hasOwner;
        this->neighborsCross = cross.neighborsCross;
        this->id = cross.id;
        this->type = cross.type;
        return *this;
    }

    Cross::Cross(const Cross& cross) : owner(cross.owner), hasOwner(cross.hasOwner), neighborsCross(cross.neighborsCross), id(cross.id), type(cross.type)
    {
    }

    Cross::Cross(): owner(*(new Player())){
        this->hasOwner = false;
    }

    Cross::~Cross(){
        delete &owner;
    }
