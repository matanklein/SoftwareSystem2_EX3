class Card{
    int available;
    public:
        Card();
        ~Card();
        Card(int available): available(available){};
        int getAvailable();
        void decreaseAvailable();
        void increaseAvailable();
};