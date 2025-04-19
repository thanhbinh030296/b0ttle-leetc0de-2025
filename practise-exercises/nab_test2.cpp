#include<stdio.h>
#include<stdlib.h>

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int abs_minus(int a, int b)
{
    if (a > b) return a - b;
    else return b-a;
}
int solution(int D[], int N, int X) {
    // Implement your solution here
    // N mission (0 -> N-1)
    /*
    mission K-th  => D[K]
    1 day = do any given mission 
    list miss  = A,b,c,d (a,b, finished => can do c)
    differenc in a same day <= X
    D = day list
    N = N mission
    X = difficult level
    D = [5,8,2,7], X = 3
    D[0] = mission 0 th, difficult level = 5
      1                         8
      2                        2
      3                        7

      day
      1st = 5,8 (because 5-8 <=3)
      2nd = 2 (cannot add 7 because 7-2 = 5 > X)
      3rd = 7

      2. [2,5,9,2,1,4], X = 4
        1st = 2,5 (cannot 9 because 9-2 = 7 > 4)

    */
    int day = 1;
    int min_difference = D[0];
    int max_difference = D[0];
    for (int i = 1;  i< N;i++)
    {
        if (D[i] > max_difference)
                max_difference = D[i];
            if (D[i] < min_difference)
                min_difference = D[i];
        if (abs_minus(max_difference, min_difference) >X)
        {
            max_difference = D[i];
            min_difference = D[i];
            day++;
        }
    }
    
    return day;
}



int main()
{
    int arraA[] = {1000000000};
    int N = 1;
    int X = 0;
    printf("\naha = %d",solution(arraA,N,X));

    return 0;
}