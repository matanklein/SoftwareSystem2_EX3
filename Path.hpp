#include "Definition.hpp"

namespace catan
{
    class Path
    {
    private:
        bool hasOwner;
        Player& owner;
        int owner;
        

    public:
        Path();
        ~Path();
    };
}