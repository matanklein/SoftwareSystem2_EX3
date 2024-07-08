/*
   email- matank214@gmail.com
*/

#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Plot.hpp"
#include "Cross.hpp"
#include "Definition.hpp"
using namespace std;

class Board
{
private:
    vector<vector<int>> boardPath;
    vector<Cross> boardCross;
    vector<int> numberInResources = {
        10, 2, 9, 12, 6, 4, 10, 9, 11, 0, 3, 8, 8, 3, 4, 5, 5, 6, 11};
    vector<int> typeInPlots = {
        mountain, pasture, forest, field, hill, pasture, hill, field, forest, desert,
        forest, mountain, forest, mountain, field, pasture, hill, field, pasture};
    vector<Plot*> boardPlot;

public:
    Board();

    ~Board();

    int getNumberOfPlots()
    {
        return boardPlot.size();
    }

    int getNumberOfCrosses()
    {
        return boardCross.size();
    }

    int getNumberOfPaths()
    {
        return boardPath.size();
    }

    vector<Plot*>& getPlots()
    {
        return boardPlot;
    }

    vector<Cross>& getCrosses()
    {
        return boardCross;
    }

    vector<vector<int>> &getPaths()
    {
        return boardPath;
    }

    int getPath(int i, int j)
    {
        return boardPath[i][j];
    }

    void setPath(int i, int j, int value)
    {
        boardPath[i][j] = value;
        boardPath[j][i] = value;
    }

    void setCross(int i, int type, Player* owner)
    {
        cout << "Setting cross " << i << " to type " << type << " with owner " << owner->getName() << endl;
        boardCross[i].setType(type);
        boardCross[i].setOwner(owner);
    }

    void setCross(int i, int type)
    {
        boardCross[i].setType(type);
    }

    void putResourceInPlotWithRoll(int j, int roll, vector<Player*> &players)
    {
        if(boardPlot[j] == nullptr){
            return;
        }
        boardPlot[j]->getResoursesOnRoll(roll, players);
    }
   
};

#endif