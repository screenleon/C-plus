//00457116--------陳里恩---------p1-1
#include <stdio.h>
#include <stdlib.h>

int function_funwhile(int, int);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int start = 0;
	int high = 0;
	int total = 0;
	printf("輸入第一行個數:	");
	scanf("%d", &start);
	printf("輸入梯形高度:	");
	scanf("%d", &high);
	total = function_funwhile(start, high);
	printf("*總數目有%d個", total);
	return 0;
}

int function_funwhile(int start, int high)
{
	int star = 0;
	int c1 = 1;
	int c2 = 1;
	while(c2<=high)
	{
		while(c1<=start)
		{
			printf("*");
			c1++;
		}
		star = star + start;
		printf("\n");
		c1 = 0;
		++start;
		c2 = c2 + 1;
	}
	return star;
}
