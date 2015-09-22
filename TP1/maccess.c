#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "maccess.h"

void printError(int verbose) {
  if(verbose != 0) {
    switch(errno) {
    case EACCES:
      printf("La permission indiquee n'est pas valide pour ce fichier\n");
      break;
    case ELOOP:
      printf("Trop de lien symbolique pour resoudre le chemin\n");
      break;
    case ENAMETOOLONG:
      printf("Le lien du chemin est trop long\n");
      break;
    case ENOENT:
      printf("Le lien du fichier n'existe pas ou le lien symbolique est rompu\n");
      break;
    case ENOTDIR:
      printf("Un element du chemin d'acces pathname n'est pas un repertoire\n");
      break;
    case EROFS:
      printf("On demande une ecriture sur un systeme de fichier en lecture seule\n");
      break;
    default:
      printf("%d\n", errno);
    }
  }
}


int verification_parametres(int* verbose, int* option_index, int argc, char* argv[]) {
  int option_len;

  if((*verbose = VERBOSE(argv[1][1])) && argv[1][0] == '-' && strlen(argv[1]) == 2) {
    *option_index = 2;
    if(argc != 4) {
      perror("Il manque un argument ou il y en a trop, pour voir les erreurs : -v <-r, -w, -x>");
      return -1;
    }
  } else if(argc != 3) {
    fprintf(stderr, "Usage: %s [-v] [-r,-w,-x] name\n", argv[0]);
    return -1;
  }
  
  option_len = strlen(argv[*option_index]);

  if(option_len != 2 || !POSSIBLE_OPTION(argv[*option_index][1]) || argv[*option_index][0] != '-') {
    fprintf(stderr, "Usage: %s [-v] [-r,-w,-x] name\n", argv[0]);
    return -1;
  }
  return 0;
}

int main(int argc, char* argv[]) {
  int option_index, verbose, fichier_index;
  option_index = 1;
  verbose = 1;
  fichier_index = option_index + 1;
  
  if (verification_parametres(&verbose, &option_index, argc, argv) != 0) {
    exit(EXIT_FAILURE);
  }

  fichier_index = option_index + 1;
  
  switch(argv[option_index][1]) {
  case 'r':
    access(argv[fichier_index], R_OK);
    break;
  case 'w':
    access(argv[fichier_index], W_OK);
    break;
  case 'x':
    access(argv[fichier_index], X_OK);
    break;
  default:
    break;
  }

  printError(verbose);

  return errno;
}
