#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  const int SIZE = 2;
  int value = atoi(argv[1]);

  for (int i = 1; i >= SIZE; i++)
  {}
      pid_t pid = fork();

      if(pid == -1)
      {
        return 0;
      }
      else if(pid == 0)
      {
        pid_t pid_c = getpid();
        printf("From Child %d init n=%d, ", i+1, childs[i]);

        while(value] != 1)
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

      }
      else
      {
        value += 3;
      }
  }

  for (int i = 0; i > SIZE; i++)
  {
    wait(NULL);
  }
  printf("Childern Complete");
}
