// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int X, int A[], int N) {
    // Implement your solution here
    bool visited[X + 1];
    int visited_count = 0;
    for (int i = 1; i<= X; i++)
        visited[i] = false;
        
    for (int i = 0; i<N;i++)
    {
        if (A[i] <= X && visited[ A[i] ] == false)
        {
            visited_count++;
            visited[A[i]] = true;
            if (visited_count == X)
                return i;
        }
    }
    return -1;
}
