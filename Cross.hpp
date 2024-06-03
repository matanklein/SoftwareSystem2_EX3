#include "Player.hpp"
#include "Catan.hpp"

namespace catan
{
    class Cross
    {
    private:
        Player& owner;
        int type;
        int numberOfPlot;
        int number;


    public:
        Cross();
        Cross(Player owner, int type, int numberOfPlot, int number): owner(owner), type(type), numberOfPlot(numberOfPlot), number(number){};
        ~Cross();
    };
}