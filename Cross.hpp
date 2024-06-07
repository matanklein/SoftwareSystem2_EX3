#include <vector>
#include "Definition.hpp"
#include "Player.hpp"
using namespace std;

class Cross
{
private:
    catan::Player& owner;
    bool hasOwner;
    vector<int> neighborsCross;
    int id;

public:
    Cross();
    void setData(vector<int> neighborsCross, int id);
    catan::Player& getOwner();
    void setOwner(catan::Player& owner);
    bool getHasOwner();
    int getId();
    ~Cross();
};
