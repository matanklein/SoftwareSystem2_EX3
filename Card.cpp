/*
   email- matank214@gmail.com
*/

#include "Card.hpp"

int Card::avail = 0;

int Card::getAvailable()
{
    return avail;
}

void Card::setAvailable(int avail)
{
    Card::avail = avail;
}

void Card::decreaseAvailable()
{
    avail--;
}

void Card::increaseAvailable()
{
    avail++;
}

void roadBuildingCard::use()
{
    cout << "Using a roadBuilding card, now you can build 2 road for free." << endl;
}

string roadBuildingCard::getType()
{
    return "roadBuilding";
}

void monopolyCard::use()
{
    cout << "Using a monopoly card, now you can take one resource of one type from all the players." << endl;
}

string monopolyCard::getType()
{
    return "monopoly";
}

void yearOfPlentyCard::use()
{
    cout << "Using a yearOfPlenty card, now you can take 2 resources of any type from the bank." << endl;
}

string yearOfPlentyCard::getType()
{
    return "yearOfPlenty";
}

void knightCard::use()
{
    cout << "Using a knight card." << endl;
}

string knightCard::getType()
{
    return "knight";
}

void victoryPointCard::use()
{
    cout << "Using a victoryPoint card, now you have one more victory point." << endl;
}

string victoryPointCard::getType()
{
    return "victoryPoint";
}