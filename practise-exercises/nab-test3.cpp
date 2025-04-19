
#include <stdio.h>
#include<stdlib.h>

int abs_minus(int a, int b)
{
    if (a >b) return a - b;
    else  return b- a;
}

int solution(int N, int A[], int B[], int M) {
    if (M == 0)
        return 0;
    bool *checkPath = (bool*)calloc(N, sizeof(bool)); // all = false
        int count = 0;

        for (int i = 0; i < M;i++)
        {
            if (abs_minus(A[i], B[i]) == 1) // 2 vertex is closed or distjoint
            {
                if (A[i] < B[i] && checkPath[A[i] == false])
                    {
                        checkPath[A[i]] = true;
                        count++;
                    }
                else if (checkPath[B[i]] == false)
                {
                    checkPath[A[i]] = true;
                    count++;
                }
            }
        }

        if (count  == N-1)
            return 1;
}
int main()
{
    int N = 3;
    int M  = 0;
    int A[] = {};
    int B[] = {};
    printf("\nhaha = %d", solution(N,A,B,M));

    return 0;
}