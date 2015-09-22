/* printError(int verbose)
   param verbose est un entier valant 0 si on veut des informations sur les erreurs et differente de 0 sinon 
   imprime les erreurs sur la sortie standard s'il y en a*/
extern void printError(int verbose);


/* renvoie 0 si la commande est bonne et si le fichier passe en parametre a bien le droit passe egalement en parametre et renvoie une valeur differente de 0 sinon
   Usage: maccess+ [-r] [-w] [-x] [-v] name
   L'option -v permet a l'utilisateur de savoir quelle erreur il a obtenu 
   Les options -r, -w et -x correspondent aux droits de lecture, ecriture et execution respectivement*/
