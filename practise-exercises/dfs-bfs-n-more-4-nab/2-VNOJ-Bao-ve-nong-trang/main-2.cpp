#include <stdio.h>
#define MAGIC_NUMBER 10000
/*
    MAP N x M
    N <=700
    M <=700
    map[i][j] = h_ij  ------  height comparing to ocean float.
    0 <  h_ij <= 10000  
    
            |      -1,0        |    
      0,-1  |      x,y         |     0, 1
            |       1,0        |    
*/

int main()
{

    int x_move[] = {-1,  0, 0, 1, };
    int y_move[] = { 0, -1, 1, 0};
    FILE *f  = fopen("input.txt","r");
    int n,m;
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &m);
    int height[n][m];

    bool isCounting[n][m];

    for (int i =0; i < n ; i++)
    {
        for (int j = 0; j < m;j++)
        {
            fscanf(f, "%d", &height[i][j]);
            printf("%d  ", height[i][j]);
            if (height[i][j] > 0 )
                isCounting[i][j] = false;
            else
                isCounting[i][j] = true;
        }
        printf("\n");
    }
    //scan
    int queue[1400];
    int start, len;
    start = len = 0;
    int peakCount = 0;
    int x,y,x_new, y_new;
    for (int i = 0; i< n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (height[i][j] > 0 && isCounting[i][j] == false)
            {
                peakCount ++;
                start = len = 0;
                queue[len++] = i*10000 + j;
                while (start < len)
                {
                    x = queue[start] / MAGIC_NUMBER;
                    y = queue[start] % MAGIC_NUMBER;
                    start++;
                    isCounting[x][y] = true;
                    for (int i_move = 0; i_move < 4; i_move ++)
                    {
                        x_new = x+ x_move[i_move];
                        y_new = y + y_move[i_move];

                        if (x_new >=0 && x_new < n && y_new >=0 && y_new < m &&
                            height[x_new][y_new] >0 && (height[x_new][y_new] - height[x][y])*(height[x_new][y_new] - height[x][y]) <=1 &&
                            isCounting[x_new][y_new] ==false)
                            {
                                queue[len++] = x_new*MAGIC_NUMBER + y_new;
                            }
                    }

                }
            }
        }
    }
    printf("\nOutput = %d",peakCount);
    return 0;
}