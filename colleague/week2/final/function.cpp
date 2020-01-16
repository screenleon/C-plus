#include "struct.h"

inline int Randi(int N)
{
    return rand()%N;
}

void DealCard(Card *Deck)
{
    int CardNum = 0;
    const int CardMax = 52;
    while(CardNum < CardMax){
        Deck[CardNum].Suit = CardNum / 13;
        Deck[CardNum].Number = CardNum % 13;
        CardNum++;
    }
    Display(Deck,0,52);
//    cout<<" "<<Deck[NowCard].Suit<<" "<<Deck[NowCard].Number + 1<<endl;
}

void Shuffle( Card * const wDeck )
{
   int i, j;
   Card temp;

   for ( i = 0; i <= 51; i++ ) {
      j = rand() % 52;
      temp = wDeck[ i ];
      wDeck[ i ] = wDeck[ j ];
      wDeck[ j ] = temp;
   }
   Display(wDeck,0,52);
}

void SuitSpadesNumbig(Card * Deck)
{
    Card *Dptr = Deck;
    int NumSort = 0, NowCard = 0;
    const int NumMax = 52;
    while(NumSort < NumMax)
    {
//        cout<<NumSort<<"\t"<<NowCard<<endl;
        for(NowCard = 0;NowCard < NumMax-NumSort-1;++NowCard)
        {
            Card temp = Dptr[NowCard];
            if(Dptr[NowCard].Suit < Dptr[NowCard+1].Suit)
            {
//                cout<<Dptr[NowCard].Suit<<"\t"<<Dptr[NowCard+1].Suit<<endl;
                Dptr[NowCard] = Dptr[NowCard+1];
                Dptr[NowCard+1] = temp;
            }
            else if(Dptr[NowCard].Suit == Dptr[NowCard+1].Suit)
            {
                if(Dptr[NowCard].Number < Dptr[NowCard+1].Number)
                {
 //                   cout<<" "<<Deck[NowCard].Suit<<" "<<Deck[NowCard].Number + 1<<"\t";
 //                   cout<<" "<<Deck[NowCard+1].Suit<<" "<<Deck[NowCard+1].Number + 1<<endl<<endl;
                    Dptr[NowCard] = Dptr[NowCard+1];
                    Dptr[NowCard+1] = temp;
  //                  cout<<" "<<Deck[NowCard].Suit<<" "<<Deck[NowCard].Number + 1<<"\t";
  //                  cout<<" "<<Deck[NowCard+1].Suit<<" "<<Deck[NowCard+1].Number + 1<<endl<<endl;
                }
            }
        }
        NumSort = NumSort + 1;
    }
    Display(Deck,0,52);
    return;
}

void NumbigSuitSpades(Card * Deck)
{
    Card *Dptr = Deck;
    int NumSort = 0, NowCard = 0;
    const int NumMax = 52;
    while(NumSort < NumMax)
    {
//        cout<<NumSort<<"\t"<<NowCard<<endl;
        for(NowCard = 0;NowCard < NumMax-NumSort-1;++NowCard)
        {
            Card temp = Dptr[NowCard];
            if(Dptr[NowCard].Number < Dptr[NowCard+1].Number)
            {
//                cout<<Dptr[NowCard].Suit<<"\t"<<Dptr[NowCard+1].Suit<<endl;
                Dptr[NowCard] = Dptr[NowCard+1];
                Dptr[NowCard+1] = temp;
            }
            else if(Dptr[NowCard].Number == Dptr[NowCard+1].Number)
            {
                if(Dptr[NowCard].Suit < Dptr[NowCard+1].Suit)
                {
 //                   cout<<" "<<Deck[NowCard].Suit<<" "<<Deck[NowCard].Number + 1<<"\t";
 //                   cout<<" "<<Deck[NowCard+1].Suit<<" "<<Deck[NowCard+1].Number + 1<<endl<<endl;
                    Dptr[NowCard] = Dptr[NowCard+1];
                    Dptr[NowCard+1] = temp;
  //                  cout<<" "<<Deck[NowCard].Suit<<" "<<Deck[NowCard].Number + 1<<"\t";
  //                  cout<<" "<<Deck[NowCard+1].Suit<<" "<<Deck[NowCard+1].Number + 1<<endl<<endl;
                }
            }
        }
        NumSort = NumSort + 1;
    }
    Display(Deck,0, 52);
    return;
}

void TeamSuitSpadesNumbig(Card * Deck, int Start)
{
    Card *Dptr = Deck;
    int NumSort = Start, NowCard = Start;
    const int NumMax = Start + 13;
    while(NumSort < NumMax)
    {
//        cout<<NumSort<<"\t"<<NowCard<<endl;
        for(NowCard = Start;NowCard < NumMax-NumSort+Start-1;++NowCard)
        {
            Card temp = Dptr[NowCard];
            if(Dptr[NowCard].Suit < Dptr[NowCard+1].Suit)
            {
//                cout<<Dptr[NowCard].Suit<<"\t"<<Dptr[NowCard+1].Suit<<endl;
                Dptr[NowCard] = Dptr[NowCard+1];
                Dptr[NowCard+1] = temp;
            }
            else if(Dptr[NowCard].Suit == Dptr[NowCard+1].Suit)
            {
                if(Dptr[NowCard].Number < Dptr[NowCard+1].Number)
                {
 //                   cout<<" "<<Deck[NowCard].Suit<<" "<<Deck[NowCard].Number + 1<<"\t";
 //                   cout<<" "<<Deck[NowCard+1].Suit<<" "<<Deck[NowCard+1].Number + 1<<endl<<endl;
                    Dptr[NowCard] = Dptr[NowCard+1];
                    Dptr[NowCard+1] = temp;
  //                  cout<<" "<<Deck[NowCard].Suit<<" "<<Deck[NowCard].Number + 1<<"\t";
  //                  cout<<" "<<Deck[NowCard+1].Suit<<" "<<Deck[NowCard+1].Number + 1<<endl<<endl;
                }
            }
        }
        NumSort++;
    }
    Display(Deck,Start, Start+13);
    return;
}

void TeamNumbigSuitSpades(Card * Deck, int Start)
{
    Card *Dptr = Deck;
    int NumSort = Start, NowCard = Start;
    const int NumMax = Start + 13;
    while(NumSort < NumMax)
    {
//        cout<<NumSort<<"\t"<<NowCard<<endl;
        for(NowCard = Start;NowCard < NumMax-NumSort+Start-1;++NowCard)
        {
            Card temp = Dptr[NowCard];
            if(Dptr[NowCard].Number < Dptr[NowCard+1].Number)
            {
//                cout<<Dptr[NowCard].Suit<<"\t"<<Dptr[NowCard+1].Suit<<endl;
                Dptr[NowCard] = Dptr[NowCard+1];
                Dptr[NowCard+1] = temp;
            }
            else if(Dptr[NowCard].Number == Dptr[NowCard+1].Number)
            {
                if(Dptr[NowCard].Suit < Dptr[NowCard+1].Suit)
                {
 //                   cout<<" "<<Deck[NowCard].Suit<<" "<<Deck[NowCard].Number + 1<<"\t";
 //                   cout<<" "<<Deck[NowCard+1].Suit<<" "<<Deck[NowCard+1].Number + 1<<endl<<endl;
                    Dptr[NowCard] = Dptr[NowCard+1];
                    Dptr[NowCard+1] = temp;
  //                  cout<<" "<<Deck[NowCard].Suit<<" "<<Deck[NowCard].Number + 1<<"\t";
  //                  cout<<" "<<Deck[NowCard+1].Suit<<" "<<Deck[NowCard+1].Number + 1<<endl<<endl;
                }
            }
        }
        NumSort++;
    }
    Display(Deck,Start, Start+13);
    return;
}


void Display(Card *Deck, int Start, int Last)
{
    int NowCard = Start;
    const int CardMax = 52;
    while(NowCard < CardMax && NowCard < Last)
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

