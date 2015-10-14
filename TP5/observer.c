int main(int argc, char *argv[]) {
  int i;
  int nb_processus;

  if(argc != 2) {
    perror("Usage : %s <nb_processus>", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  nb_processus = atoi(argv[1]);

  for(int i = 0; i < nb_processus; i++) {
    switch(fork()) {
    case -1:
      perror("Une erreur s'est produite pendant le fork");
      exit(EXIT_FAILURE);
    case 0:
      while(1) {
	printf("%d\n", getpid());
	sleep(5);
      }
    }
  }

  
}
