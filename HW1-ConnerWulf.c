#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {

  int child1 = atoi(argv[1]);
  int child2 = child1 + 3
  //int child2 = argv[1] + 3;
  printf("%d, %d\n",child1, child2);
  return 0;
}
