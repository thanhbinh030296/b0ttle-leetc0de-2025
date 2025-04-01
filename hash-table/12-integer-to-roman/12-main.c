#include <stdio.h>
#include <stdlib.h>

int value[] = {1, 5, 10, 50, 100, 500, 1000};
char symbol[] = {'I','V','X','L','C','D','M'};

char* intToRoman(int num) {
 // num <=3999
	char* result = (char*)malloc(10*sizeof(char));
	int len  =0;

	int thounsand  = num/1000;
	int symbol_len = 6;

	while (thounsand > 0 && symbol_len > -1)
	{
		if (thounsand - value[symbol_len] >=0)
		{
			result[len++] = symbol[symbol_len];
			thounsand-= value[symbol_len];
		}
		else 
			symbol_len--;
	}
	result[len++] = 'M';

	int hundreds = (num - thounsand*1000)/500;

	symbol_len = 6;


	result[len++] = 0;
	return result;
}





int main()
{
	printf("s = %s",intToRoman(5230));
	return 0;
}