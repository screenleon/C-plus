/* Fig. 7.26: fig07_26.cpp
   Multipurpose sorting program using function pointers */
#include <stdio.h>
#define SIZE 10
void bubble( int [], const int, int (*)( int, int ) );
int ascending( int, int );
int descending( int, int );

int main()
{
   int order, 
       counter,
       a[ SIZE ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

   printf( "Enter 1 to sort in ascending order,\n" 
           "Enter 2 to sort in descending order: " );
   scanf( "%d",  &order );
   printf( "\nData items in original order\n" );
   
   for ( counter = 0; counter < SIZE; counter++ )
      printf( "%5d", a[ counter ] );

   if ( order == 1 ) {
      bubble( a, SIZE, ascending );
      printf( "\nData items in ascending order\n" );
   }
   else {
      bubble( a, SIZE, descending );
      printf( "\nData items in descending order\n" );
   }

   for ( counter = 0; counter < SIZE; counter++ )
      printf( "%5d", a[ counter ] );   

   printf( "\n" );

   return 0;
}

void bubble( int work[], const int size, 
             int (*compare)( int, int ) )
{
   int pass, count;

   void swap( int *, int * );

   for ( pass = 1; pass < size; pass++ )

      for ( count = 0; count < size - 1; count++ )

         if ( (*compare)( work[ count ], work[ count + 1 ] ) )			//////////////////////////////////

            swap( &work[ count ], &work[ count + 1 ] );							//////////////////////////////////
}

void swap( int *element1Ptr, int *element2Ptr )											//////////////////////////////////
{
   int temp;

   temp = *element1Ptr;
   *element1Ptr = *element2Ptr;
   *element2Ptr = temp;
}

int ascending( int a, int b )																				//////////////////////////////////
{
   return b < a;   /* swap if b is less than a */
}

int descending( int a, int b )																			//////////////////////////////////
{
   return b > a;   /* swap if b is greater than a */
}



 