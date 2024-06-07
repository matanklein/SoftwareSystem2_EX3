#include <vector>
#include <string>

namespace catan
{
    class Player
    {
    private:
        string name;

    public:
        Player(string name): name(name){};
        ~Player();
        
    };
}
