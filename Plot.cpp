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

void Plot::getResoursesOnRoll(int roll)
{
    if (numberCircle == roll && !hasRobber && type != desert)
    {
        for (int i = 0; i < crossSections.size(); i++)
        {
            if (crossSections[i].getHasOwner())
            {
                if (crossSections[i].getId() == city)
                {
                    crossSections[i].getOwner().addResource(type);
                    crossSections[i].getOwner().addResource(type);
                }
                else
                {
                    crossSections[i].getOwner().addResource(type);
                }
            }
        }
    }
}