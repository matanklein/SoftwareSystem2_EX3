#include "Player.hpp"

namespace catan
{
    void Player::addResource(int resource){
        if(resource < 0 || resource > 4 || resource == desert)
            return;
        resources[resource]++;
    }
}