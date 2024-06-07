#include <vector>
#include <string>
#include "Definition.hpp"
using namespace std;

namespace catan
{
    class Player
    {
    private:
        string name;
        vector<int> resources;

    public:
        Player(){
            resources = {0, 0, 0, 0, 0};
        }
        Player(string name): name(name){};
        ~Player();
        void addResource(int resource);
        
    };
}
