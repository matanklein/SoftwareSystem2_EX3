#include <vector>
#include "Plot.hpp"
#include "Cross.hpp"
#include "Path.hpp"
#include "Definition.hpp"
using namespace std;

class Board{
private:

    vector<vector<int>> boardPath;

    vector<Cross> boardCross;

    vector<int> numberInResources = {
        10, 2, 9, 12, 6, 4, 10, 9, 11, 0, 3, 8, 8, 3, 4, 5, 5, 6, 11
    };

    vector<int> typeInPlots = {
        mountain , pasture, forest, field, hill, pasture, hill, field, forest, desert,
        forest, mountain, forest, mountain, field, pasture, hill, field, pasture
    };

    vector<Plot> boardPlot;

    Board();

public:

    /**
     * @brief Get the Board object
     * 
     * @return Board 
     */
    Board getBoard(){
        return Board();
    }
    
    ~Board();
    
};