/*
   email- matank214@gmail.com
*/

#include "doctest.h"
#include "Board.hpp"
#include "Cross.hpp"
#include "Plot.hpp"
#include "Definition.hpp"
#include "Card.hpp"
#include "Player.hpp"
#include "Catan.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

TEST_CASE("test Player"){
    Player player("Player1", 1);
    CHECK(player.getName() == "Player1");
    CHECK(player.getId() == 1);
    CHECK(player.getPoints() == 0);
    CHECK(player.getAvailableRoads() == 2);
    CHECK(player.getAvailableSettlements() == 2);
    player.addAvailableRoads(1);
    CHECK(player.getAvailableRoads() == 3);
    player.setAvailableRoads(15);
    CHECK(player.getAvailableRoads() == 15);
    player.addAvailableRoads(2);
    CHECK(player.getAvailableRoads() == 17);
    player.addAvailableRoads(3);
    CHECK(player.getAvailableRoads() == 20);
    player.addAvailableRoads(4);
    CHECK(player.getAvailableRoads() == 24);
    player.addAvailableRoads(5);
    CHECK(player.getAvailableRoads() == 29);
    player.addAvailableRoads(6);
    CHECK(player.getAvailableRoads() == 35);
    player.addAvailableRoads(7);
    CHECK(player.getAvailableRoads() == 42);
    player.addAvailableRoads(8);
    CHECK(player.getAvailableRoads() == 50);
    player.addAvailableRoads(9);
    CHECK(player.getAvailableRoads() == 59);
    player.addAvailableRoads(10);
    CHECK(player.getAvailableRoads() == 69);
    player.addAvailableRoads(11);
    CHECK(player.getAvailableRoads() == 80);
    player.addAvailableRoads(12);
    CHECK(player.getAvailableRoads() == 92);
    player.addAvailableRoads(13);
    CHECK(player.getAvailableRoads() == 105);
    player.addAvailableRoads(14);
    CHECK(player.getAvailableRoads() == 119);
    player.addAvailableRoads(15);
    CHECK(player.getAvailableRoads() == 134);
    player.addAvailableRoads(16);
    CHECK(player.getAvailableRoads() == 150);
    player.addAvailableRoads(17);
    CHECK(player.getAvailableRoads() == 167);
    player.addAvailableRoads(18);
    CHECK(player.getAvailableRoads() == 185);
    player.addAvailableRoads(19);
    CHECK(player.getAvailableRoads() == 204);
    
    player.addResource(0);
    player.addResource(1);
    player.addResource(2);
    player.addResource(3);
    player.addResource(4);
    player.addResource(5);
    player.addResource(0, 2);
    player.addResource(1, 2);
    player.addResource(2, 2);
    player.addResource(3, 2);
    player.addResource(4, 2);
    player.addResource(5, 2);

    player.removeResource(0);
    player.removeResource(1);
    player.removeResource(2);
    player.removeResource(3);
    player.removeResource(4);
    player.removeResource(5);
    player.removeResource(0, 2);
    player.removeResource(1, 2);
    player.removeResource(2, 2);
    player.removeResource(3, 2);
    player.removeResource(4, 2);
    player.removeResource(5, 2);

}

TEST_CASE("test Board"){
    Board board;
    CHECK(board.getNumberOfPlots() == 19);
    CHECK(board.getNumberOfCrosses() == 54);
    CHECK(board.getNumberOfPaths() == 54);
    vector<Plot*> plots = board.getPlots();
    vector<Cross> crosses = board.getCrosses();
    //vector<vector<int>> paths = board.getPaths();
    CHECK(plots.size() == 19);
    CHECK(crosses.size() == 54);
    board.setPath(0, 1, 1);
    CHECK(board.getPath(0, 1) == 1);
    CHECK(board.getPath(1, 0) == 1);
    board.setPath(1, 2, 2);
    CHECK(board.getPath(1, 2) == 2);
    CHECK(board.getPath(2, 1) == 2);
    board.setPath(2, 3, 3);
    CHECK(board.getPath(2, 3) == 3);
    CHECK(board.getPath(3, 2) == 3);
    board.setPath(3, 4, 4);
    CHECK(board.getPath(3, 4) == 4);
    CHECK(board.getPath(4, 3) == 4);
    board.setPath(4, 5, 5);
    CHECK(board.getPath(4, 5) == 5);
    CHECK(board.getPath(5, 4) == 5);
    board.setPath(5, 6, 6);
    CHECK(board.getPath(5, 6) == 6);
    CHECK(board.getPath(6, 5) == 6);
    board.setPath(6, 7, 7);
    CHECK(board.getPath(6, 7) == 7);
    CHECK(board.getPath(7, 6) == 7);
    board.setPath(7, 8, 8);
    CHECK(board.getPath(7, 8) == 8);
    CHECK(board.getPath(8, 7) == 8);
    board.setPath(8, 9, 9);
    CHECK(board.getPath(8, 9) == 9);
    CHECK(board.getPath(9, 8) == 9);
    board.setPath(9, 10, 10);
    CHECK(board.getPath(9, 10) == 10);
    CHECK(board.getPath(10, 9) == 10);
    board.setPath(10, 11, 11);
    CHECK(board.getPath(10, 11) == 11);

}

TEST_CASE("test Cross"){
    Cross cross;
    cross.setData({1, 2, 3}, 4);
    CHECK(cross.getHasOwner() == false);
    CHECK(cross.getId() == 4);
    cross.setOwner(new Player("Player1", 1));
    CHECK(cross.getHasOwner() == true);
    CHECK(cross.getOwner()->getName() == "Player1");
    cross.setOwner(new Player("Player2", 2));
    CHECK(cross.getOwner()->getName() == "Player2");
    cross.setOwner(new Player("Player3", 3));
    CHECK(cross.getOwner()->getName() == "Player3");
    cross.setOwner(new Player("Player4", 4));
    CHECK(cross.getOwner()->getName() == "Player4");
    cross.setOwner(new Player("Player5", 5));
    CHECK(cross.getOwner()->getName() == "Player5");
    cross.setOwner(new Player("Player6", 6));
    CHECK(cross.getOwner()->getName() == "Player6");
    cross.setOwner(new Player("Player7", 7));
    CHECK(cross.getOwner()->getName() == "Player7");
    cross.setOwner(new Player("Player8", 8));
    CHECK(cross.getOwner()->getName() == "Player8");
    cross.setOwner(new Player("Player9", 9));
    CHECK(cross.getOwner()->getName() == "Player9");
    cross.setOwner(new Player("Player10", 10));
    CHECK(cross.getOwner()->getName() == "Player10");
    cross.setOwner(new Player("Player11", 11));
    CHECK(cross.getOwner()->getName() == "Player11");
    cross.setOwner(new Player("Player12", 12));
    CHECK(cross.getOwner()->getName() == "Player12");
    cross.setOwner(new Player("Player13", 13));
    CHECK(cross.getOwner()->getName() == "Player13");
    cross.setOwner(new Player("Player14", 14));
    CHECK(cross.getOwner()->getName() == "Player14");
    cross.setOwner(new Player("Player15", 15));
    CHECK(cross.getOwner()->getName() == "Player15");
    cross.setOwner(new Player("Player16", 16));
    CHECK(cross.getOwner()->getName() == "Player16");
    cross.setOwner(new Player("Player17", 17));
    CHECK(cross.getOwner()->getName() == "Player17");
    cross.setOwner(new Player("Player18", 18));
    CHECK(cross.getOwner()->getName() == "Player18");
}

