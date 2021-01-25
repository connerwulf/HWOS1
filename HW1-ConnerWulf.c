#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {

  const int SIZE = 2;
  int value = atoi(argv[1]);
  if(0 < value < 40 )
  {
    printf("Value must be between 0 and 40");
    return 0;
  }
  for (int i = 1; i <= SIZE; i++)
  {
      pid_t pid = fork();

      if(pid == -1)
      {
        printf("\nFork failed");
        return 0;
      }
      else if(pid == 0)
      {
        pid_t pid_c = getpid();
        printf("From Child %d init n=%d, ", i, value);

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
  for(int j = 0; j < SIZE; j++)
  {
    wait(NULL);
  }
  printf("Childern Complete\n");
  return 0;
}
