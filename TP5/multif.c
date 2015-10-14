#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#include "multif.h"

int multif(func_t f[], int args[], int n) {
  int i;
  int status;
  int res;
  
  for(i = 0; i < n; i++) {
    switch(fork()) {
    case -1:
      perror("Impossible de creer un processus fils");
      exit(EXIT_FAILURE);
    case 0:
      exit(f[i](args[i]));
    }
  }

  for(i = 0; i < n; i++) {
    wait(&status);
    if(i == 0) res = status;
    else res = status && res;
  }

  return res;
}

int fVal(int val) {
  return val;
}

int main(int argc, char *argv[]) {
  func_t *f;
  int *args;
  int res;
  int i;
  
  f = (func_t*)malloc(argc * sizeof(func_t));
  if(f == NULL) {
    perror("Une erreur s'est produite pendant la creation du tableau de fonction");
    exit(EXIT_FAILURE);
  }
  args = (int*)malloc(argc * sizeof(int));
  if(args == NULL) {
    perror("Une erreur s'est produite pendant la creation du tableau de valeur");
    exit(EXIT_FAILURE);
  }
  
  for(i = 1; i < argc; i++) {
    f[i] = fVal;
    args[i] = atoi(argv[i]);
  }
  
  res = multif(f, args, argc);

  free(f);
  free(args);
  
  return res;
}
