//00457116--------������---------p1-3
#include <stdio.h>
#include <stdlib.h>

int function_funwhile(int, int, int);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int start = 0;
	int high = 0;
	int total = 0;
	int diff = 0;
	printf("��J�Ĥ@��Ӽ�:		");
	scanf("%d", &start);
	printf("��J��ΰ���:		");
	scanf("%d", &high);
	printf("�C�檺�t��(�����):	");
	scanf("%d", &diff);
	total = function_fun3For(start, high, diff);
	printf("*�`�ƥئ�%d��", total);
	return 0;
}

int function_fun3For(int start, int high, int diff)
{
	int star , c1, c2;
	for(c2 = 1;c2<=high;c2++)
	{
		for(c1 = high-c2;c1>0;c1--)
		{
			printf(" ");
		}
		for(c1 = 1;c1<=start;c1++)
		{
			printf("*");
		}
		star = star + start;
		printf("\n");
		c1 = 0;
		start = start + diff * 2;
	}
	return star;
}

