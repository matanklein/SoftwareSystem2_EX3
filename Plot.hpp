#include <vector>
#include "Cross.hpp"
#include "Path.hpp"
#include "Catan.hpp"
#include "Definition.hpp"

class Plot{
    private:
        std::vector<catan::Cross> crossSections;
        std::vector<catan::Path> pathes;
        int numberCircle;
        int type;
        bool hasRobber;
    public:
        Plot();
        Plot(int numberCircle, int type): numberCircle(numberCircle), type(type){
            if(type == desert){
                hasRobber = true;
            }else{
                hasRobber = false;
            }
        };
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
        void addPath(path path);
        /**
         * @brief Gets cube roll and gives resources to players 
         * if they have a settlement or city on the plot and the plot has the same numberCircle as the roll.
        */
        void getResourses(int roll);
};