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
};

class promotion : public Card{
    public:
        promotion();
        ~promotion();
};

class roadBuilding : public promotion{
    public:
        roadBuilding();
        ~roadBuilding();
};

class monopoly : public promotion{
    public:
        monopoly();
        ~monopoly();
};

class yearOfPlenty : public promotion{
    public:
        yearOfPlenty();
        ~yearOfPlenty();
};

class knight : public Card{
    public:
        knight();
        ~knight();
};

class victoryPoint : public Card{
    public:
        victoryPoint();
        ~victoryPoint();
};
