int solution(int A, int B, int K) {
    // Implement your solution here
    int count=0;
    if (A == 0)
        count++;
    if (B < K)
        return count;
    int starting = A/K;
    if (starting == 0)
        starting++;
    if (B / K > 0)
        count += B/K - A/K;

    return count;
}