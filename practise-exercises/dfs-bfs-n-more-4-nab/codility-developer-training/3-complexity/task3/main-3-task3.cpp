// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

long long abs_minus(long long a, long long b)
{
    if (a > b) return a - b;
    else return b- a;
}

int solution(int A[], int N) {
    // Implement your solution here
    if (N == 2)
        return abs_minus(A[0], A[1]);
    if (N == 1)
        return abs_minus(A[0], 0);
    long long leftSum = 0;
    long long rightSum = 0;
    for (int i = 0; i < N; i++)
        rightSum+=A[i]; 
    bool isFirst = true;
    long long min_diff;
    for (int P = 1; P < N-1; P++)
    {
        leftSum+=A[P-1];
        rightSum-=A[P-1];
        if (isFirst ==true)
        {
            min_diff = abs_minus(leftSum, rightSum);
            isFirst = false;
        }
        else
        {
            if (min_diff > abs_minus(leftSum, rightSum))
                min_diff = abs_minus(leftSum, rightSum);
        }
    }
    return min_diff;
}
