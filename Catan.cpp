#include "Catan.hpp"
#include <iostream>

using namespace std;

Catan::Catan(string name1, string name2, string name3)
{
    p1 = Player(name1,1);
    p2 = Player(name2,2);
    p3 = Player(name3,3);
    turn = 0;
    Players = {p1, p2, p3};
    board = Board();
    isGameEnd = false;
    
    srand(static_cast<unsigned int>(time(0)));
}

void Catan::rollDice()
{
    if(isGameEnd){
        cout << "The game is over" << endl;
        throw "Game is over";
    }

    for(size_t i = 0; i < Players.size(); i++){
        if(Players[i].getAvailableRoads() > 0){
            cout << "Player: " << Players[i].getName() << "didn't built all the roads that he got. left: " << Players[i].getAvailableRoads() << endl;
            throw "Player has available roads";
        }
        if(Players[i].getAvailableSettlements() > 0){
            cout << "Player: " << Players[i].getName() << "didn't built all the settlements that he got. left: " << Players[i].getAvailableSettlements() << endl;
            throw "Player has available settlements";
        }
    }
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    int sum = dice1 + dice2;
    cout << "The roll dice is: " << sum << endl;
    if (sum == 7) // needs to cut in half the resources of the player
    {
        cout << "7 activated" << endl;
    }

    vector<Plot> plots = board.getPlots();

    for(size_t i = 0; i < plots.size(); i++){
        plots[i].getResoursesOnRoll(sum);
    }
    
}

void Catan::endTurn()
{
    if(Players[turn].getPoints() >= 10){
        cout << "The winner is: " << Players[turn].getName() << endl;
        cout << "The game is over" << endl;
        isGameEnd = true;
        return;
    }
    turn++;
    if (turn == 3)
    {
        turn = 0;
    }
}

void Catan::buildSettlement(Player& player, int place){

    if(place < 0 || place >= board.getNumberOfCrosses()){
        cout << "The place is out of bounds" << endl;
        throw "build settlement out of bounds";
    }

    vector<Cross> crosses = board.getCrosses();
    if(crosses[place].getHasOwner()){
        cout << "The place is already taken by: " << crosses[place].getOwner().getName() << endl;
        throw "build settlement on taken place";
    }

    player.buildSettlement();
    crosses[place].setOwner(player);
    crosses[place].setType(settlement);
}

void Catan::buildCity(Player& player, int place){

    if(place < 0 || place >= board.getNumberOfCrosses()){
        cout << "The place is out of bounds" << endl;
        throw "build city out of bounds";
    }

    vector<Cross> crosses = board.getCrosses();
    if(!crosses[place].getHasOwner()){
        cout << "The place is not taken by anyone" << endl;
        throw "build city on empty place";
    }

    if(crosses[place].getOwner().getId() != player.getId()){
        cout << "The place is taken by: " << crosses[place].getOwner().getName() << endl;
        throw "build city on taken place";
    }

    player.buildCity();
    crosses[place].setType(city);
}

void Catan::startGame(){
    for(size_t i = 0; i < Players.size(); i++){
        if(Players[i].getAvailableRoads() > 0){
            cout << "Player: " << Players[i].getName() << "didn't built all the roads that he got. left: " << Players[i].getAvailableRoads() << endl;
            throw "Player has available roads";
        }
        if(Players[i].getAvailableSettlements() > 0){
            cout << "Player: " << Players[i].getName() << "didn't built all the settlements that he got. left: " << Players[i].getAvailableSettlements() << endl;
            throw "Player has available settlements";
        }
    }
    // run once on the board and give each player resources based on their settlements
    vector<Plot> plots = board.getPlots();
    for(int i = 2; i <= 12 ; i++){ // run for all the possible rolls
        if(i == 7){ // skip the 7 roll
            continue;
        }

        for(size_t j = 0; j < plots.size(); j++){
            plots[j].getResoursesOnRoll(i);
        }
    }

    knightCard::setAvailable(14);
    monopolyCard::setAvailable(5);
    roadBuildingCard::setAvailable(2);
    yearOfPlentyCard::setAvailable(2);
    victoryPointCard::setAvailable(2);

    cout << "The game has started" << endl;
}

void Catan::trade(Player& player1, Player& player2, int resource1,int amount1, int resource2, int amount2){
    if(resource1 < 0 || resource1 > 4 || resource2 < 0 || resource2 > 4){
        cout << "The resource is out of bounds" << endl;
        throw "trade failed";
    }

    if(player1.getResources()[resource1] < amount1 || player2.getResources()[resource2] < amount2){
        cout << "The player doesn't have enough resources" << endl;
        throw "trade failed";
    }

    if(player1.getId() == player2.getId()){
        cout << "The player can't trade with himself" << endl;
        throw "trade failed";
    }

    if(amount1 < 0 || amount2 < 0){
        cout << "The amount is negative" << endl;
        throw "trade failed";
    }

    player1.removeResource(resource1, amount1);
    player1.addResource(resource2, amount2);
    
    player2.removeResource(resource2, amount2);
    player2.addResource(resource1, amount1);
    
}

void Catan::buildRoad(Player& player, int i, int j){
    if(i < 0 || i >= board.getNumberOfCrosses() || j < 0 || j >= board.getNumberOfCrosses()){
        cout << "The path is out of bounds" << endl;
        throw "add path failed";
    }

    vector<vector<int>> paths = board.getPaths();
    if(paths[i][j] != noneP || paths[j][i] != noneP){
        cout << "The path is already taken" << endl;
        throw "add path failed";
    }

    bool isPathConnected = false;
    bool isSettlementConnected = false;

    vector<Cross> crosses = board.getCrosses();

    // check if the path is connected to player's settlements
    if(crosses[i].getOwner().getId() == player.getId() || crosses[j].getOwner().getId() == player.getId()){
        isSettlementConnected = true;
    }

    // check if the path is connected to player's paths
    vector<int> neighborsi = crosses[i].getNeighborsCross();
    vector<int> neighborsj = crosses[j].getNeighborsCross();

    // if there is a player's path with the serial number i or j then the path is connected to the player's paths 
    for(size_t k = 0; k < neighborsi.size(); k++){
        if(paths[i][neighborsi[k]] == player.getId()){
            isPathConnected = true;
            break;
        }
    }

    for(size_t k = 0; k < neighborsj.size(); k++){
        if(paths[j][neighborsj[k]] == player.getId()){
            isPathConnected = true;
            break;
        }
    }

    if(!isPathConnected && !isSettlementConnected){
        cout << "The path is not connected to the player's paths or settlements" << endl;
        throw "add path failed";
    }

    player.buildRoad();
    board.setPath(i, j, player.getId());
}

void Catan::buyDevelopmentCard(Player& player){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 4);

    int card = dis(gen);

    if(getAvailableDevelopmentCard(card) == -1){
        for(int i = 0; i < 5; i++){
            if(getAvailableDevelopmentCard(i % 5) != -1){
                card = i;
                break;
            }
        }
    }
    switch (card)
    {
    case knight:
        player.addDevelopmentCard(new knightCard());
        break;
    case monopoly:
        player.addDevelopmentCard(new monopolyCard());
        break;
    case roadBuilding:
        player.addDevelopmentCard(new roadBuildingCard());
        break;
    case yearOfPlenty:
        player.addDevelopmentCard(new yearOfPlentyCard());
        break;
    case victoryPoint:
        player.addDevelopmentCard(new victoryPointCard());
        break;
    default:
        cout << "There is no left development cards" << endl;
        return;
    }
    player.buyDevelopmentCard();
}

int Catan::getAvailableDevelopmentCard(int card){
    switch (card)
    {
    case knight:
        return knightCard::getAvailable();
    case monopoly:
        return monopolyCard::getAvailable();
    case roadBuilding:
        return roadBuildingCard::getAvailable();
    case yearOfPlenty:
        return yearOfPlentyCard::getAvailable();
    case victoryPoint:
        return victoryPointCard::getAvailable();
    default:
        return -1;
    }
}

void Catan::useDevelopmentCard(Player& player, int card){

    switch (card)
    {
    case knight:
        cout << "You don't need to use a knight card, it's automatically used when you play it" << endl;
        break;
    case monopoly:
        if(!player.hasDevelopmentCard("monopoly")){
            cout << "You don't have a monopoly card" << endl;
            return;
        }
        player.useDevelopmentCard("monopoly");
        cout << "Choose a resource to take from all the players" << endl;
        int resource;
        cin >> resource;
        Monopoly(player, resource);
        endTurn();
        break;
    case roadBuilding:
        if(!player.hasDevelopmentCard("roadBuilding")){
            cout << "You don't have a roadBuilding card" << endl;
            return;
        }
        player.useDevelopmentCard("roadBuilding");
        player.addAvailableRoads(2);
        cout << "You can build 2 roads for free" << endl;
        endTurn();
        break;
    case yearOfPlenty:
        if(!player.hasDevelopmentCard("yearOfPlenty")){
            cout << "You don't have a yearOfPlenty card" << endl;
            return;
        }
        int resource1, resource2;
        cout << "Choose 2 resources to take from the bank" << endl;
        cin >> resource1 >> resource2;
        player.addResource(resource1, 1);
        player.addResource(resource2, 1);
        player.useDevelopmentCard("yearOfPlenty");
        endTurn();
        break;
    case victoryPoint:
        cout << "You don't need to use a victory point card, it's automatically used when you buy it" << endl;
        break;
    default:
        cout << "That card doesn't exist" << endl;
        return;
    }
}

void Catan::Monopoly(Player& player, int resource){
    for(size_t i = 0; i < Players.size(); i++){
        if(Players[i].getId() == player.getId()){
            continue;
        }
        int amount = Players[i].getResources()[resource];
        Players[i].removeResource(resource, amount);
        player.addResource(resource, amount);
    }
}
