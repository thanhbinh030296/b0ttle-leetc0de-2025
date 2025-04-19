#include <stdio.h>



int main()
{
    for (int i = 0; i< 5;i++)
    {
        for (int j = 0; j< 5;j++)
        {
            if (j > i+1)
            {
                break;
            }
            printf("\ni = %d, j = %d",i,j);
        }
    }
    return 0;
}