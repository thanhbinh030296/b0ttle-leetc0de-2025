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


char* intToRoman2(int num)
{
	char* result = (char*)malloc(10*sizeof(char));
	int len  =0;
	int n_multiple = 0;
	// thounsand
	if (num/1000 > 0)
	{
		n_multiple = num / 1000;
		for (int i = 1; i<=n_multiple;i++)
			{
				result[len++] = 'M';
			}
	}
	// hundreds
	num = num%1000;
	n_multiple = num/500;
	if (n_multiple  > 0)
	{
		if (num/ 100 == 9)
			{
				result[len++] = 'C';
				result[len++] = 'M';
			} 
		else {
			result[len++] = 'D';
			for (int i = 6; i<= num/100;i++)
			{
				result[len++] = 'C';
			}
		}
	}
	else
	{
		n_multiple = num/100;
		if (n_multiple == 4)
			{
				result[len++] = 'C';
				result[len++] = 'D';
			}
		else
		{
			for (int i = 1; i<=n_multiple;i++)
				result[len++] = 'C';
		}

	}
	
	// dozen

	result[len++] = '\0';
	return result;
}


int main()
{
	printf("\nhaha = %d ",4321%1000);
	printf("\ns = %s\n",intToRoman2(3749));
	return 0;
}