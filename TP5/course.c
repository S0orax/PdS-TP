#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void compte_100_million() {
  int i;

  for(i = 0; i < 100000000; i++) {
    /* Compte jusque 100 millions */
  }
}

int main(int argc, char *argv[]) {
  int i;
  pid_t pid;
  
  for(i = 0; i < 10; i++) {
    switch(fork()) {
    case -1:
      perror("Une erreur se produit pendant le fork");
      exit(EXIT_FAILURE);
    case 0:
      compte_100_million();
      printf("%d a compter en %d\n", getpid(), i);
      compte_100_million();
      exit(EXIT_SUCCESS);
    }
  }

  for(i = 0; i < 10; i++) {
    pid = wait(NULL);
    printf("%d a termine\n", pid);
  }

  return 0;
}
