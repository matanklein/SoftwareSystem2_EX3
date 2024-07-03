/*
   email- matank214@gmail.com
*/

#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>

using namespace std;

class Card{
    protected:
        static int avail;
    public:
        Card(){};
        virtual ~Card(){};
        static int getAvailable();
        static void setAvailable(int avail);
        void decreaseAvailable();
        void increaseAvailable();
        virtual void use() = 0;
        virtual string getType() = 0;
        
};

class promotionCard : public Card{
    public:
        virtual void use() = 0;
        virtual string getType() = 0;
        virtual ~promotionCard(){};
};

class roadBuildingCard : public promotionCard{
    public:
        void use();
        string getType();
};

class monopolyCard : public promotionCard{
    public:
        void use();
        string getType();
};

class yearOfPlentyCard : public promotionCard{
    public:
        void use();
        string getType();
};

class knightCard : public Card{
    public:
        void use();
        string getType();
};

class victoryPointCard : public Card{
    public:
        void use();
        string getType();
};

#endif