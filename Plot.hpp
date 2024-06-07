#include <vector>
#include "Cross.hpp"
#include "Path.hpp"
#include "Definition.hpp"

using namespace std;

class Plot{
    private:
        vector<Cross> crossSections;
        //vector<catan::Path> pathes;
        int numberCircle;
        int type;
        bool hasRobber;
        //bool isNearSea;
    public:
        Plot();
        void setData(int numberCircle, int type, vector<Cross> crossSections);
        ~Plot();
        /**
         * @brief Adds a cross to the plot
         * 
         * @param cross 
         */
        void addCross(Cross cross);
        /**
         * @brief Adds a path to the plot
         * 
         * @param path 
         */
        void addPath(catan::Path path);
        /**
         * @brief Gets cube roll and gives resources to players 
         * if they have a settlement or city on the plot and the plot has the same numberCircle as the roll.
        */
        void getResourses(int roll);
};