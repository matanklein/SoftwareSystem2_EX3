#include "Plot.hpp"

void Plot::setData(int numberCircle, int type, vector<Cross> crossSections)
{
    this->numberCircle = numberCircle;
    this->type = type;
    if (type == desert)
    {
        hasRobber = true;
    }
    else
    {
        hasRobber = false;
    }
}