#include "Cross.hpp"
#include "Path.hpp"
#include "Catan.hpp"

namespace catan
{
    class Player
    {
    private:
        vector<Path> pathes;
        vector<Cross> crosses;
    public:
        Player();
        ~Player();
        addPath(Path path);
        addCross(Cross cross);
        
    };
}
