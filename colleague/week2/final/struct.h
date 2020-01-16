#ifndef STRUCT_H
#define STRUCT_H

#include<iostream>
#include<time.h>
#include<cstdlib>

using namespace std;

enum{Clubs, Diamands, Hearts, Spades};
enum{Jack = 11,Queen, King};

struct Card
{
    int Suit;
    int Number;
};

void DealCard(Card*);
inline int Randi(int);
void SuitSpadesNumbig(Card*);
void NumbigSuitSpades(Card*);
void TeamSuitSpadesNumbig(Card*, int);
void TeamNumbigSuitSpades(Card*, int);
void Shuffle(Card*);
void Display(Card*);
void Display(Card*, int, int);



#endif // STRUCT_H
