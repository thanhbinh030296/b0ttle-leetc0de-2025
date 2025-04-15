#include <stdio.h>
#define FLOOR '.'
#define WALL '#'
#define MAGIC_NUMBER 10000
#define MAX_FLOORS 1000
/*
    n*m map
    . = a block of floor
    # = a block of wall

    |           |  x - 1,0  |       |
    |  0,y-1    |  x        | 0,y+1 |
    |           | x + 1,0   |       |
*/

int x_move[] = {-1, 0, 0, 1};
int y_move[] = {0, -1, 1, 0};
//int MAGIC_NUMBER = 1000;
int queue[MAX_FLOORS];

int main()
{
    FILE *f = fopen("input.txt","r");
    char token;
    int m, n;
    fscanf(f, "%d", &m);
    fscanf(f, "%d", &n);

    printf("\n m = %d, n = %d", m,n);
    char floors[m][n];
    bool isCount[m][n];
    fgetc(f);

    int list_floor[n*m];
    int floor_len = 0;

    for (int  i = 0; i< m;i ++)
    {
        for (int j = 0; j< n; j++)
        {
            fscanf(f, "%c", &floors[i][j]);
            //floors[i][j] = fgetc(f);
            isCount[i][j] = false;
            if (floors[i][j] == FLOOR)
                list_floor[floor_len++] = i*MAGIC_NUMBER + j;
        }
        fgetc(f);
    }

    fclose(f);

    
    int start = 0;
    int len = 0;
    // print them
    for (int i = 0; i< m;i ++)
    {
        printf("\n");
        for (int j = 0; j<n;j++)
            printf("%c",floors[i][j]);
    }
    int n_floor = 0;
    // counting the room
    int x, y;
    for (int floor_indx = 0; floor_indx < floor_len; floor_indx++)
    {
        x = list_floor[floor_indx]/ MAGIC_NUMBER;
        y = list_floor[floor_indx] % MAGIC_NUMBER;
        
        if (isCount[x][y] == true)
            continue;
        
        n_floor ++;

        //isCount[x][y] = true;
        start = 0;
        len  = 0;
        queue[len++] = x*MAGIC_NUMBER + y;
        //loop to count room via queue
        while (start < len)
        {
            x = queue[start] / MAGIC_NUMBER;
            y = queue[start] % MAGIC_NUMBER;
            start++;
            if (isCount[x][y]== true)
                continue;
            isCount[x][y] = true;

            for (int i_move = 0; i_move < 4; i_move++)
            {
                if ( x +x_move[i_move] >=0 && x_move[i_move] <m &&
                     y+ y_move[i_move] >=0 && y +y_move[i_move]<n && 
                     (floors[x + x_move[i_move]][y + y_move[i_move]] == FLOOR) && 
                     (isCount[x + x_move[i_move]][y + y_move[i_move]]== false))
                {
                    queue[len++] = (x + x_move[i_move]) * MAGIC_NUMBER + y + y_move[i_move];
                }
            }
        }

    }
    printf("\n n_floor = %d",n_floor);
    return 0;
}