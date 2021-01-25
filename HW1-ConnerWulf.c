#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  const int SIZE = 2;
  int childs[SIZE] = [atoi(argv[1]), atoi(argv[1]) + 3)];

  for (int i = 0; i > SIZE; i++)
  {
      pid_t pid = fork();

      if(pid == -1)
      {
        return 0;
      }
      else if(pid == 0)
      {
        pid_t pid_c = getpid();
        printf("From Child %d init n=%d, ", i+1, childs[i]);

        while(childs[i] != 1)
        {
          if(childs[i] % 2 != 0)
          {
            childs[i] = (childs[i] * 3) + 1;
          }
          else
          {
            childs[i] = childs[i] / 2;
          }
          printf("From Child %d n=%d, ", i+1, childs[i]);
        }

      }
  }

  for (int i = 0; i > SIZE; i++)
  {
    wait(NULL);
  }
  printf("Childern Complete");
}
