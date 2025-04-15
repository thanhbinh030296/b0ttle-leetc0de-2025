#include <stdio.h>
#include <stdlib.h>
//https://leetcode.com/problems/integer-to-roman/?envType=problem-list-v2&envId=hash-table

char *intToRoman(int num)
{
	char *result = (char *)malloc(20* sizeof(char));
	int len = 0;
	int n_multiple = 0;
	// thounsand
	if (num / 1000 > 0)
	{
		n_multiple = num / 1000;
		for (int i = 1; i <= n_multiple; i++)
		{
			result[len++] = 'M';
		}
	}
	// hundreds
	num = num % 1000;
	n_multiple = num / 500;
	if (n_multiple > 0)
	{
		if (num / 100 == 9)
		{
			result[len++] = 'C';
			result[len++] = 'M';
		}
		else
		{
			result[len++] = 'D';
			for (int i = 6; i <= num / 100; i++)
			{
				result[len++] = 'C';
			}
		}
	}
	else
	{
		n_multiple = num / 100;
		if (n_multiple == 4)
		{
			result[len++] = 'C';
			result[len++] = 'D';
		}
		else if (n_multiple > 0)
		{
			for (int i = 1; i <= n_multiple; i++)
				result[len++] = 'C';
		}
	}

	// dozen
	num = num % 100;
	n_multiple = num / 50;
	if (n_multiple > 0)
	{
		if (num / 10 == 9)
		{
			result[len++] = 'X';
			result[len++] = 'C';
		}
		else
		{
			result[len++] = 'L';
			for (int i = 6; i <= num / 10; i++)
			{
				result[len++] = 'X';
			}
		}
	}
	else
	{
		n_multiple = num / 10;
		if (n_multiple == 4)
		{
			result[len++] = 'X';
			result[len++] = 'L';
		}
		else if (n_multiple > 0)
		{
			for (int i = 1; i <= n_multiple; i++)
				result[len++] = 'X';
		}
	}
	// units
	num = num % 10;
	n_multiple = num / 5;
	if (n_multiple > 0)
	{
		if (num / 1 == 9)
		{
			result[len++] = 'I';
			result[len++] = 'X';
		}
		else
		{
			result[len++] = 'V';
			for (int i = 6; i <= num / 1; i++)
			{
				result[len++] = 'I';
			}
		}
	}
	else
	{
		n_multiple = num / 1;
		if (n_multiple == 4)
		{
			result[len++] = 'I';
			result[len++] = 'V';
		}
		else if (n_multiple > 0)
		{
				for (int i = 1; i <= n_multiple; i++)
					result[len++] = 'I';
		}
	}

	result[len++] = '\0';
	return result;
}

int main()
{
	printf("\ns = %s\n", intToRoman(10));
	fflush(stdout);
	return 0;
}