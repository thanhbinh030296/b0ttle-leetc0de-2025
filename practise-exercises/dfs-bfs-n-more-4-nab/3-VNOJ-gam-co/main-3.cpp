#include <stdio.h>
#define RANCHE 'B'
#define Bessie 'C'
#define GRASS '.'
#define ROCK '*'
#define MAX_SIZE 101
#define MAGIC_NUMBER 10000
/*
    R x C 100x100
    * = rock
    . = grass
    B = ranch of cows
    C =  Bessie
    find the path from C (Bessie) to B (ranch of cows)
    tai vi tri C co the tinh la 1 o grass
    can move 4 heads

               |   -1, 0    |
      0, -1    |    x,y     |   0, 1
               |    1, 0    |

*/
int main()
{
    FILE *f = fopen("input.txt","r");

    int x_move[] = {-1, 0, 0, 1};
    int y_move[] = {0, -1, 1, 0};

    int R, C;


    int starting_coord = -1;
    int ending_coord = -1;
    

    fscanf(f, "%d", &R);
    fscanf(f, "%d", &C);
    fgetc(f);
    char map[MAX_SIZE][MAX_SIZE];
    int visited[MAX_SIZE][MAX_SIZE];
    for (int i = 1; i<= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            map[i][j] = fgetc(f);
            printf("%c ",map[i][j] );
            // get Bessie coord
            if (map[i][j] == Bessie)
            {
                starting_coord = i*MAGIC_NUMBER + j;
                visited[i][j] = 1;
            }
            else if (map[i][j] == RANCHE)
            {
                ending_coord = i*MAGIC_NUMBER + j;
                visited[i][j] = MAX_SIZE*MAX_SIZE;
            }
            else if (map[i][j] == GRASS)
            {
                visited[i][j] = MAX_SIZE*MAX_SIZE;
            }
            else if (map[i][j] == ROCK)
            {
                visited[i][j] = -1;
            }
            
        }

        fgetc(f); // "\n"
        printf("\n");
    }

    //
    int queue[(C+1)*(R+1)];
    int start, len;
    int x,y, x_new, y_new;
    start = len = 0;
    
    queue[len++] = starting_coord;
    bool isStop = false;
    while (start < len && isStop == false)
    {
        x = queue[start] / MAGIC_NUMBER;
        y = queue[start] % MAGIC_NUMBER;
        start++;
        if (map[x][y] == -1 || map[x][y] == MAX_SIZE*MAX_SIZE) // map block is rock or  grass is visted
            continue;
        //
        for (int i_move = 0; i_move < 4; i_move++)
        {
            x_new = x + x_move[i_move];
            y_new = y + y_move[i_move];
            if (x_new >=1 && x_new <= R && y_new >=1 && y_new <= C && 
                visited[x_new][y_new] ==MAX_SIZE*MAX_SIZE &&
                 visited[x][y] +1 < visited[x_new][y_new]
                )
                {
                    queue[len++] = x_new*MAGIC_NUMBER + y_new;
                    visited[x_new][y_new] = visited[x][y] + 1;
                    if (map[x_new][y_new] == RANCHE)
                        isStop=true;
                }
        }
    }
    fclose(f);
    printf("\n ending coord  = %d \n", ending_coord);
    printf("\nResult = %d\n",visited[ending_coord/MAGIC_NUMBER][ending_coord%MAGIC_NUMBER] - 1);
    for (int i = 1; i<=R; i++)
    {
        for (int j = 1; j<=C;j++)
        {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
    return 0;
}