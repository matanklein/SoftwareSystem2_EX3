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
        vector<Cross> crossSections;
        int numberCircle;
        int type;
    public:
        Plot(){};
        void setData(int numberCircle, int type, const vector<Cross>& crossSections);
        ~Plot();

        /**
         * @brief Adds a cross to the plot
         * 
         * @param cross 
         */
        void addCross(Cross cross);

        /**
         * @brief Gets cube roll and gives resources to players 
         * if they have a settlement or city on the plot and the plot has the same numberCircle as the roll.
        */
        void getResoursesOnRoll(int roll);
        int getType();

        //void operator=(Plot& plot);
};

#endif