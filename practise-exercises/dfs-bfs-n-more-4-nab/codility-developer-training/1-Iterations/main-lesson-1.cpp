#include <stdio.h>


/*

    a bin gap = positive integer N
    

*/
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int N) {
    // Implement your solution here
    bool start = false;
    if (N < 2)
      return 0;
    int max_gapLen = 0;
    int gaplen = 0;
    while (N >= 1) {
      if (N % 2 == 1) {
        if (start == false) {
          start = true;
          gaplen = 0;
        } else {
          if (gaplen > max_gapLen)
            max_gapLen = gaplen;
          gaplen = 0;
        }
      }
      else
      {
          if (start == true)
              gaplen++;
      }
      N/=2;
    }
    return max_gapLen;
  }
  
int main()
{
    
    printf("\ncount = %d",solution(1041));

    return 0;
}