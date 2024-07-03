/*
   email- matank214@gmail.com
*/

#ifndef PLOT_HPP
#define PLOT_HPP

#include <vector>
#include "Cross.hpp"
#include "Definition.hpp"

using namespace std;

class Plot{
    private:
        vector<Cross*> crossSections;
        int numberCircle;
        int type;
    public:
        Plot(){
            crossSections = {};
            numberCircle = 0;
            type = 0;
        }
        void setData(int numberCircle, int type, const vector<Cross*> crossSections);
        ~Plot();

        /**
         * @brief Gets cube roll and gives resources to players 
         * if they have a settlement or city on the plot and the plot has the same numberCircle as the roll.
        */
        void getResoursesOnRoll(int roll, vector<Player*>& players);
        int getType();

        void operator=(const Plot& plot);
};

#endif