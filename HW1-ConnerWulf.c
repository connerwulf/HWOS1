#include<stdio.h>
int main(int argc, char const *argv[]) {
  int child1 = *(int)argv[1];
  //int child2 = argv[1] + 3;
  printf("%d\n",child1);
  return 0;
}
