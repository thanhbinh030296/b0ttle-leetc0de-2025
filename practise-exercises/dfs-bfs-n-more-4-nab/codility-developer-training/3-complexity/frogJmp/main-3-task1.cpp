#include <stdio.h>

int main()
{
    int N1 = 100000;
    int sum1 = (N1 + 1)*N1;
    long sum2 = (N1 + 1)*N1;
    long long sum3 = (N1 + 1)*N1;

    printf("\n Sum = %d",sum1);
    printf("\n Sum = %lld",sum2);
    printf("\n Sum = %llu",sum3);

    return 0;
}