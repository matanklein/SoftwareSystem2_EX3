#include <vector>
#include "Definition.hpp"
#include "Player.hpp"
using namespace std;

class Cross
{
private:
    catan::Player owner;
    vector<int> neighborsCross;
    int id;

public:
    Cross();
    // Cross(int owner, int type, int numberOfPlot, int number): owner(owner), type(type), numberOfPlot(numberOfPlot), number(number){};
    void setData(int owner, vector<int> neighborsCross, int id);
    ~Cross();
};
