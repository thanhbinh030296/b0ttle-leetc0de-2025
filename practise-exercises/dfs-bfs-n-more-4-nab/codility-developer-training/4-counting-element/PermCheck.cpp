int solution(int A[], int N) {
    // Implement your solution here
    bool visited[N+1];
    
    for (int i = 1; i<= N; i++)
        visited[i] = false;
    
    int visited_count = 0;

    for (int i = 0; i< N;i++ )
    {
        if (A[i] <= N && visited[A[i]] == false)
        {
            visited_count++;
            visited[A[i]] = true;
        }
        else if (A[i] > N)
            return 0;
    }

    if (visited_count == N)
        return 1;

    return 0;

}