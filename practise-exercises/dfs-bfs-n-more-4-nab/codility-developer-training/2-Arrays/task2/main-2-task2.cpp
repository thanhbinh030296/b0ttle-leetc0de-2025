// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
//
/*
    N counters
    initialze = 0
    array A[M]
    A[K] = X; if 1 <=X <=N => increase(X) 
    A[K] = N+1 => operator K is max couinter

*/
struct Results solution(int N, int A[], int M) {
    // Implement your solution here
    struct Results result;
    
    result.C = (int*)malloc(N*sizeof(int));
    result.L = N;

    int current_max = 0;

    for (int i = 0; i< N;i++)
        result.C[i] = 0;
    
    for (int i = 0; i<M;i++)
    {
        if (A[i] <= N && A[i] >=1)
        {
            result.C[i]++;
            if (result.C[i] > current_max)
                current_max = result.C[i];
        }
        else if (A[i] == N+1)
        {
            result.C[i] = current_max;
        }

    }


    return result;
}
