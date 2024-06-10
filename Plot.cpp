#include "Plot.hpp"

void Plot::setData(int numberCircle, int type, vector<Cross>& crossSections)
{
    this->numberCircle = numberCircle;
    this->type = type;
}

void Plot::getResoursesOnRoll(int roll)
{
    if (numberCircle == roll && type != desert)
    {
        for (int i = 0; i < crossSections.size(); i++)
        {
            if (crossSections[i].getHasOwner())
            {
                if (crossSections[i].getId() == city)
                {
                    crossSections[i].getOwner().addResource(type, 2);
                }
                else
                {
                    crossSections[i].getOwner().addResource(type);
                }
            }
        }
    }
}