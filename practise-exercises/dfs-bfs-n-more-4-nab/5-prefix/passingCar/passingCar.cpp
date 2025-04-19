int solution(int A[], int N) {
    // Implement your solution here
    int zeroList[N];
    int oneList[N];
    int lenZero = 0;
    int lenOne = 0;
    for (int i = 0; i<N;i++)
    {
        if (A[i] == 0)
            zeroList[lenZero++]=i;
        else
            oneList[lenOne++] = i;
    }
    int countPassingCare = 0;
    for (int i = 0;i < lenZero;i++)
    {
        for (int j = 0; j < lenOne;j++)
        {
            if (oneList[j] > zeroList[i])
            {
                countPassingCare+=lenOne - j;
                break;
            }
        }
    }

    return countPassingCare;

}