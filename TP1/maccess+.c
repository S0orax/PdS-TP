#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


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

int main(int argc, char* argv[]) {
  int opt;
  int verbose = 0;
  int permission_octet = 0;

  while((opt = getopt(argc, argv, "vrwx")) != -1) {
    if (strlen(argv[optind-1]) != 2) {
      fprintf(stderr, "Expected option of longueur 2\n");
      exit(EXIT_FAILURE);
    }
    switch(opt) {
    case 'v':
      verbose = 1;
      break;
    case 'r':
      permission_octet = permission_octet | R_OK;
      break;
    case 'w':
      permission_octet = permission_octet | W_OK;
      break;
    case 'x':
      permission_octet = permission_octet | X_OK;
      break;
    default:
      fprintf(stderr, "Usage: %s [-r] [-w] [-x] [-v] name\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  if (!argv[optind]) {
    fprintf(stderr, "Expected argument after options\n");
    exit(EXIT_FAILURE);
  }
  
  access(argv[argc - 1], permission_octet);

  printError(verbose);

  return errno;
}
