/* VERBOSE(c)
   param c un caractere,
   affiche 0 si c est le caractere 'v',
   sinon ca renvoie une valeur differente de 0*/
#define VERBOSE(c) ((c) == 'v')

/* POSSIBLE_OPTION(c)
   param c un caractere,
   affiche 0 si c est le caractere 'r','w' ou 'x', 
   et renvoie une valeur differente de 0 sinon */
#define POSSIBLE_OPTION(c) (((c) == 'r') || ((c) == 'w') || ((c) == 'x'))

/* verification_parametres(int* verbose, int* option_index, int argc, char* argv[])
   param verbose est un pointeur sur un entier verifiant si l'option '-v' est prise en compte
   param option_index est un pointeur sur un entier representant l'index de l'option sur la ligne de commande
   param argc est un entier representant le nombre de parametres
   param argv est un pointeur sur des chaines de caracteres representant la liste des parametres
   renvoie 0 si on est dans la situation suivant : ./maccess [-v] [-w,-x,-r] fichier
   renvoie -1 sinon
 */
extern int verification_parametres(int* verbose, int* option_index, int argc, char* argv[]);

/* printError(int verbose)
   param verbose est un entier valant 0 si on veut des informations sur les erreurs et differente de 0 sinon 
   imprime les erreurs sur la sortie standard s'il y en a*/
extern void printError(int verbose);


/* renvoie 0 si la commande est bonne et si le fichier passe en parametre a bien le droit passe egalement en parametre et renvoie une valeur differente de 0 sinon 
   Usage: maccess [-r,-w,-x] [-v] name
   L'option -v permet a l'utilisateur de savoir quelle erreur il a obtenu 
   Les options -r, -w et -x correspondent aux droits de lecture, ecriture et execution respectivement*/
