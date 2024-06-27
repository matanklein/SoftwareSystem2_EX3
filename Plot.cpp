#include "Plot.hpp"

void Plot::setData(int numberCircle, int type,const vector<Cross>& crossSections)
{
    this->numberCircle = numberCircle;
    this->type = type;
    this->crossSections = crossSections;
}

void Plot::getResoursesOnRoll(int roll)
{
    if (numberCircle == roll && type != desert)
    {
        for (size_t i = 0; i < crossSections.size(); i++)
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

void Plot::addCross(Cross cross)
{
    crossSections.push_back(cross);
}

int Plot::getType()
{
    return type;
}

Plot::~Plot()
{
    crossSections.clear();
}

