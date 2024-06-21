#include "Player.hpp"

namespace catan
{
    Player::Player()
    {
        resources = {0, 0, 0, 0, 0};
        points = 0;
        availableRoads = 2;
        availableSettlements = 2;
    }

    Player::Player(string name, int id)
    {
        this->name = name;
        this->id = id;
        resources = {0, 0, 0, 0, 0};
        points = 0;
        availableRoads = 2;
        availableSettlements = 2;
    }

    void Player::addResource(int resource){
        if(resource < 0 || resource > 4 || resource == desert)
            return;
        resources[resource]++;
    }

    void Player::addResource(int resource, int amount){
        if(resource < 0 || resource > 4 || resource == desert)
            return;
        resources[resource] += amount;
    }

    void Player::removeResource(int resource){
        if(resource < 0 || resource > 4 || resource == desert)
            return;
        resources[resource]--;
    }

    void Player::removeResource(int resource, int amount){
        if(resource < 0 || resource > 4 || resource == desert)
            return;
        resources[resource] -= amount;
    }

    void Player::buildSettlement(){
        if(availableSettlements > 0){
            availableSettlements--;
            points++;
            return;
        }
        if(resources[brick] > 0 && resources[wood] > 0 && resources[oat] > 0 && resources[wool] > 0){
            resources[brick]--;
            resources[wood]--;
            resources[oat]--;
            resources[wool]--;
            points++;
            return;
        }
    
        cout << "Player: " << name << "doesn't have enough resources to build a settlement" << endl;
        throw "Player doesn't have enough resources";
    }

    void Player::buildCity(){
        if(resources[iron] >= 3 && resources[oat] >= 2){
            resources[iron] -= 3;
            resources[oat] -= 2;
            points++;
            return;
        }

        cout << "Player: " << name << "doesn't have enough resources to build a city" << endl;
        throw "Player doesn't have enough resources";
    }

    void Player::buildRoad(){
        if(availableRoads > 0){
            availableRoads--;
            return;
        }

        if(resources[wood] > 0 && resources[brick] > 0){
            resources[wood]--;
            resources[brick]--;
            return;
        }

        cout << "Player: " << name << "doesn't have enough resources to build a road" << endl;
        throw "Player doesn't have enough resources";
    }

    void Player::buyDevelopmentCard(){
        if(resources[iron] > 0 && resources[wool] > 0 && resources[oat] > 0){
            resources[iron]--;
            resources[wool]--;
            resources[oat]--;
            return;
        }

        cout << "Player: " << name << "doesn't have enough resources to buy a development card" << endl;
        throw "Player doesn't have enough resources";
    }

    int Player::amountOfallResources(){
        int sum = 0;
        for(int i = 0; i < 5; i++){
            sum += resources[i];
        }
        return sum;
    }

    void Player::addDevelopmentCard(Card* card){

        if(card->getType() == "knight"){
            knights++;
            return;
        }
        if(card->getType() == "victoryPoint"){
            points++;
            return;
        }
        developmentCards.push_back(card);
    }

    void Player::useDevelopmentCard(string type){

        if(type == "knight"){
            cout << "You cannot use a knight card, it already been activated." << endl;
            return;
        }
        if(type == "victoryPoint"){
            cout << "You cannot use a victoryPoint card, it already been activated." << endl;
            return;
        }
        for(int i = 0; i < developmentCards.size(); i++){
            if(developmentCards[i]->getType() == type){
                developmentCards.erase(developmentCards.begin() + i);
                return;
            }
        }
    }

    bool Player::hasDevelopmentCard(string type){

        if(type == "knight"){
            return knights > 0;
        }
        for(int i = 0; i < developmentCards.size(); i++){
            if(developmentCards[i]->getType() == type){
                return true;
            }
        }
        return false;
    }

    void Player::removeDevelopmentCard(string type){

        if(type == "knight"){
            knights--;
            return;
        }
        if(type == "victoryPoint"){
            cout << "You cannot remove a victoryPoint card." << endl;
            return;
        }
        for(int i = 0; i < developmentCards.size(); i++){
            if(developmentCards[i]->getType() == type){
                developmentCards.erase(developmentCards.begin() + i);
                return;
            }
        }
    }

    void Player::printResources(){
        cout << "Player: " << name << " has: " << endl;
        cout << "Brick: " << resources[brick] << endl;
        cout << "Wood: " << resources[wood] << endl;
        cout << "Iron: " << resources[iron] << endl;
        cout << "Oat: " << resources[oat] << endl;
        cout << "Wool: " << resources[wool] << endl;
    }

    void Player::addKnight(){
        knights++;
        if(knights == 3){
            points += 2;
        }
    }  

    void Player::removeKnight(){
        knights--;
        if(knights == 2){
            points -= 2;
        }
    } 
}