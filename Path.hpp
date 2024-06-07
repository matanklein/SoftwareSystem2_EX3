//#include "Player.hpp"
#include "Definition.hpp"

namespace catan
{
    class Path
    {
    private:
        Player& owner;
        int numberOfPlot;
        int number;

    public:
        Path();
        Path(Player& owner, int numberOfPlot, int number): owner(owner), numberOfPlot(numberOfPlot), number(number){};
        ~Path();
    };
}