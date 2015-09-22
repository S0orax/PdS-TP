#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  printf("NAME_MAX : %d, PATH_MAX : %d\n", NAME_MAX, PATH_MAX);
  return 0;
}
