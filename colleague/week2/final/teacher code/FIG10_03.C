/* Fig. 10.3: fig10_03.c
   The card shuffling and dealing program using structures */
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

struct card { 
   const char *face;
   const char *suit;
};


typedef struct card Card;

void fillDeck( Card * const, const char *[], const char *[] );	// �]�P��l��
void shuffle( Card * const );																		// �~�P
void deal( const Card * const );																// �C�L�P

int main()
{ 
   Card deck[ 52 ];
   const char *face[] = { "Ace", "Deuce", "Three", 
                          "Four", "Five",
                          "Six", "Seven", "Eight", 
                          "Nine", "Ten",
                          "Jack", "Queen", "King"};

   const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};			////////////////////

   srand( time( NULL ) );

   fillDeck( deck, face, suit );																		// �]�P��l��
   shuffle( deck );																									// �~�P
   deal( deck );																										// �C�L�P
   return 0;
}

void fillDeck( Card * const wDeck, const char * wFace[], 
               const char * wSuit[] )
{ 
   int i;

   for ( i = 0; i <= 51; i++ ) { 
      wDeck[ i ].face = wFace[ i % 13 ];
      wDeck[ i ].suit = wSuit[ i / 13 ];
   }
}

void shuffle( Card * const wDeck )
{ 
   int i, j;
   Card temp;

   for ( i = 0; i <= 51; i++ ) { 
      j = rand() % 52;
      temp = wDeck[ i ];
      wDeck[ i ] = wDeck[ j ];
      wDeck[ j ] = temp;
   }
}

void deal( const Card * const wDeck )
{ 
   int i;

   for ( i = 0; i <= 51; i++ )
      printf( "%d \t %5s of %-8s%c", i+1, wDeck[ i ].face, 
              wDeck[ i ].suit, '\n' );
           //   ( i + 1 ) % 2 ? '\t' : '\n' );
}


 