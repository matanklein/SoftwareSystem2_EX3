/*
   email- matank214@gmail.com
*/

#include "Plot.hpp"

void Plot::setData(int numberCircle, int type, const vector<Cross *> crossSections)
{
    for(size_t i = 0; i < crossSections.size(); i++){
        this->crossSections.push_back(crossSections[i]);
    }
    this->numberCircle = numberCircle;
    this->type = type;
}

void Plot::getResoursesOnRoll(int roll, vector<Player *> &players)
{
    if (numberCircle == roll && type != desert)
    {
        for (size_t i = 0; i < crossSections.size(); i++)
        {
            if(crossSections[i] == nullptr){
                continue;
            }
            if (crossSections[i]->getHasOwner() == true)
            {
                if (crossSections[i]->getId() == city)
                {
                    int id = crossSections[i]->getOwner()->getId();
                    players[id - 1]->addResource(type, 2);
                }
                else
                {
                    int id = crossSections[i]->getOwner()->getId();
                    players[id - 1]->addResource(type);
                }
            }
        }
    }
}

int Plot::getType()
{
    return type;
}

Plot::~Plot()
{
}

void Plot::operator=(const Plot &plot)
{
    this->numberCircle = plot.numberCircle;
    this->type = plot.type;
    this->crossSections = plot.crossSections;
}
