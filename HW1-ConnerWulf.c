#include<stdio.h>
int main(int argc, char const *argv[]) {
  int child1 = argv[1];
  int child2 = argv[1] + 3;
  printf("%d\n",child2);
  return 0;
}
