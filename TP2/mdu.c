#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <limits.h>
#include <dirent.h>

static int opt_follow_links = 0;
static int opt_apparent_size = 0;

/*
 * ./mdu --- [-L] -> du -B512 [-L]
 * ./mdu -b [-L] -> du -b [-L]
 */

void printError(const char* filename) {
  printf("Impossible d'acceder a \"%s\": Aucun fichier ou dossier de ce type\n", filename);
  exit(EXIT_FAILURE);
}

int du_file(const char* pathname) {
  struct stat st;
  int taille;
  char filename[PATH_MAX + 1];
  
  if(opt_follow_links) {
    if(lstat(pathname, &st)) printError(pathname);
  } else {
    if(stat(pathname, &st)) printError(pathname);
  }
  
  taille = opt_apparent_size ? st.st_size : st.st_blocks;

  if(S_ISDIR(st.st_mode)) {
    DIR* rep = opendir(pathname);
    if(rep != NULL) {
      struct dirent* de;
      while((de = readdir(rep)) == 0) {
	if(strcmp(pathname, ".") && strcmp(pathname, "..")) {
	  snprintf(filename, PATH_MAX + 1, "%s/%s", pathname, de->d_name);
	  taille += du_file(filename);
	}
      }
    }
    closedir(rep);
  }
  
  return taille;
}

int main(int argc, char* argv[]) {
  int taille, opt;

  while((opt = getopt(argc, argv, "bL")) != -1) {
    switch(opt) {
    case 'b':
      opt_apparent_size = 1;
      break;
    case 'L':
      opt_follow_links = 1;
      break;
    default:
      printf("Usage: %s [-b][-L] %s", argv[0], argv[argc - 1]);
      exit(EXIT_FAILURE);
    }
  }
  
  taille = du_file(argv[argc - 1]);
  printf("%d\n", taille);
  return 0;
}
