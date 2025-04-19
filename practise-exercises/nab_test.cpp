#include<stdio.h>
#include<stdlib.h>

char * solution(char *S) {
    // Implement your solution here
    //codility
    //cdility
    int len_S = 0;
    while (S[len_S]!=0)
        len_S++;
    char *str_result = (char*)calloc(len_S-1, sizeof(char));
    int len_result = 0;
    int mark_to_remove = -1;
    for (int i = 0; i< len_S-1;i++)
    {
        if (S[i] > S[i+1])
            {
                mark_to_remove = i;
                break;
            }
    }
    if (mark_to_remove == -1)
        mark_to_remove = len_S-1;
    for (int i = 0; i< len_S;i++)
        if (i!=mark_to_remove)
        {
            str_result[len_result++] = S[i]; 
        }

    return str_result ;
}  


int main()
{

    printf("\n hihi = %s ",solution("abc"));
    printf("\naha");

    return 0;
}