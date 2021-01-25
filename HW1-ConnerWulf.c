#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {

  //Intialization
  const int SIZE = 2;
  int value = atoi(argv[1]);

  //Bound Check
  if(value < 0 || value > 40)
  {
    printf("Value must be between 0 and 40\n");
    return 0;
  }

  //Main Code - Where Parent creates Childern
  for (int i = 1; i <= SIZE; i++)
  {
    //Childern Created
      pid_t pid = fork();

      //Start of Child process
      if(pid == 0)
      {
        printf("\tFrom Child %d init n=%d, ", i, value);

        //Collatz algorithm
        while(value != 1)
        {
          if(value % 2 != 0)
          {
            value = (value * 3) + 1;
          }
          else
          {
            value = value / 2;
          }
          printf("From Child %d n=%d, ", i, value);
        }
        printf("\n");
        return 0;
      }
      else
      {
        value += 3;
      }
  }

  //Parent process waits for each child.
  for(int j = 0; j < SIZE; j++)
  {
    wait(NULL);
  }
  //Parent process Competed
  printf("\tChildern Complete\n");
  return 0;
}
