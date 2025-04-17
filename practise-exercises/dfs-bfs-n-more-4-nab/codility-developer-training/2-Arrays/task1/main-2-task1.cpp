#include <stdio.h>
#include <stdlib.h>
struct Results {
    int *A;
    int N; // Length of the array
  };


struct Results solution(int A[], int N, int K) {
    // Implement your solution here
    struct Results result;
    //int arrayA[N];
    result.A = (int*) malloc( N* sizeof(int) );
    
    result.N = N;
    
    for (int i = 0; i<N;i++)
    {
        result.A[(i + K)%N] = A[i];
    }


    return result;
}

int main()
{
    int arrayA[] = {1,3,3};
    solution(arrayA,3,1);
    printf("\nhihi");
    return 0;
}