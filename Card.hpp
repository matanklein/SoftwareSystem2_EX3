#include <iostream>
#include <string>

using namespace std;

class Card{
    protected:
        static int available;
    public:
        Card();
        ~Card();
        static int getAvailable();
        static void setAvailable(int available);
        void decreaseAvailable();
        void increaseAvailable();
        virtual void use() = 0;
        virtual string getType() = 0;
        
};

class promotionCard : public Card{
    public:
        virtual void use() = 0;
        virtual string getType() = 0;
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
