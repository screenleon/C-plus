#include "struct.h"

inline int Randi(int N)
{
    return rand()%N+1;
}

void DealCard(Card *Deck)
{
    int CardNum = 0;
    const int CardMax = 52;
    while(CardNum < CardMax){
        Deck[CardNum].Suit = CardNum / 13;
        Deck[CardNum].Number = CardNum % 13;
        cout<<" "<<Deck[CardNum].Suit<<" "<<Deck[CardNum].Number + 1<<endl;
        CardNum++;
    }
//    cout<<" "<<Deck[NowCard].Suit<<" "<<Deck[NowCard].Number + 1<<endl;
}

void Shuffle(Card * const Deck)
{
    Card *Dptr = Deck;
    int ShuffleCardNumber = 0, RandCard;
    const int NumberMax = 13, CardMax = 52;
    int PokerCheck[52] = {0};
    srand(int(time(0)));
    while(ShuffleCardNumber < CardMax)
    {
        RandCard = Randi(CardMax);
        if(PokerCheck[RandCard]){}
        else
        {
            PokerCheck[RandCard] = 1;
            ShuffleCardNumber++;
            Deck[ShuffleCardNumber].Suit = RandCard / NumberMax;
            Deck[ShuffleCardNumber].Number = (RandCard % NumberMax) + 1;
        }
        ShuffleCardNumber++;
    }
    Display(Deck);
    return;
}

void SuitSpadesNumbig(Card * const Deck)
{
    Card *Dptr = Deck, temp;
    int NumSort = 1, NowCard = 0;
    const int NumMax = 52;
    while(NumSort <= NumMax)
    {
        if(Dptr[NowCard].Suit < Dptr[NowCard+1].Suit)
        {
                temp = Dptr[NowCard];
                Dptr[NowCard] = Dptr[NowCard+1];
                Dptr[NowCard+1] = temp;
        }
        else if(Dptr[NowCard].Suit = Dptr[NowCard+1].Suit)
        {
            if(Dptr[NowCard].Number <Dptr[NowCard+1].Number)
            {
                temp.Number = Dptr[NowCard].Number;
                Dptr[NowCard].Number = Dptr[NowCard+1].Number;
                Dptr[NowCard+1].Number = temp.Number;
            }
        }
        NowCard++;
        NumSort++;
    }
    Display(Deck);
    return;
}

void NumbigSuitSpades(Card * const Deck)
{
    Card *Dptr = Deck, temp;
    int NumSort = 1, NowCard = 0;
    const int NumMax = 52;
    while(NumSort <= NumMax)
    {
        if(Dptr[NowCard].Number < Dptr[NowCard+1].Number)
        {
                temp = Dptr[NowCard];
                Dptr[NowCard] = Dptr[NowCard+1];
                Dptr[NowCard+1] = temp;
        }
        else if(Dptr[NumSort].Number = Dptr[NowCard+1].Number)
        {
            if(Dptr[NowCard].Suit < Dptr[NowCard+1].Suit)
            {
                temp.Number = Dptr[NowCard].Suit;
                Dptr[NowCard].Suit = Dptr[NowCard+1].Suit;
                Dptr[NowCard+1].Suit = temp.Suit;
            }
        }
        NowCard++;
        NumSort++;
    }
    Display(Deck);
    return;
}

void TeamSuitSpadesNumbig(Card * const Deck)
{
    Card *Dptr = Deck, temp;
    int NowCard = 0, NumSort = 1;
    const int  NumMax = 13;
    while(NumSort <= NumMax)
    {
        if(Dptr[NowCard].Suit < Dptr[NowCard+1].Suit)
        {
            temp = Dptr[NowCard];
            Dptr[NowCard] = Dptr[NowCard+1];
            Dptr[NowCard+1] = temp;
        }
        else if(Dptr[NowCard].Suit = Dptr[NowCard+1].Suit)
        {
            if(Dptr[NowCard].Number < Dptr[NowCard+1].Number)
            {
               temp.Number = Dptr[NowCard].Number;
               Dptr[NowCard].Number = Dptr[NowCard+1].Number;
               Dptr[NowCard+1].Number = temp.Number;
            }
        }
        NowCard++;
        NumSort++;
    }
    Display(Deck);
    return;
}

void TeamNumbigSuitSpades(Card * const Deck)
{
    Card *Dptr = Deck, temp;
    int NowCard = 0, NumSort = 1;
    const int NumMax = 13;
    while(NumSort <= NumMax)
    {
        if(Dptr[NowCard].Number < Dptr[NowCard+1].Number)
        {
            temp = Dptr[NowCard];
            Dptr[NowCard] = Dptr[NowCard+1];
            Dptr[NowCard+1] = temp;
        }
        else if(Dptr[NowCard].Number = Dptr[NowCard+1].Number)
        {
            if(Dptr[NowCard].Suit < Dptr[NowCard+1].Suit)
            {
               temp.Suit = Dptr[NowCard].Suit;
               Dptr[NowCard].Suit = Dptr[NowCard+1].Suit;
               Dptr[NowCard+1].Suit = temp.Suit;
            }
        }
        NowCard++;
        NumSort++;
    }
    Display(Deck);
    return;
}

void Display(Card *Deck)
{
    int NowCard = 0;
    const int CardMax = 52;
    while(NowCard < CardMax)
    {
        switch(Deck[NowCard].Suit)
        {
            case 0:
                cout<<"Clubs:";
                break;
            case 1:
                cout<<"Diamands:";
                break;
            case 2:
                cout<<"Hearts:";
                break;
            case 3:
                cout<<"Spades:";
                break;

        }
        cout<<Deck[NowCard].Number + 1<<endl;
        NowCard++;
    }
}
