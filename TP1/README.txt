DUBOIS Yann
MEYER Helene
Groupe 1
TP1 PdS

****************************************************
******QUESTION*3*****MACCESS************************
****************************************************

Les erreurs avec l'executable maccess :

	Acces aux fichiers refuse, il n'est pas permis d'acceder au sous dossier

		$ ./maccess -w /dev/mem ; echo $?
		13

	Acces au fichier refuse

		$ ./maccess -r /root ; echo $?
		13


	Trop de liens symboliques ont ete rencontres en parcourant le pathname :

		$ sh liens_symboliques.sh
		$ ./maccess -w lien_symbolique41 ; echo $?
		40

	Le pathname est trop long :

		On ne peut pas le tester car le systeme nous
		interdit la creation d'un d'un fichier avant
		qu'on puisse tester (avec le script shell on a pu le tester)

	Le lien symbolique pointe vers null :

		$ >bientot_supprime
		$ ln -s bientot_supprime lien_symb_pointant_vers_null
		$ rm bientot_supprime
		$ ./maccess -v -r lien_symb_pointant_vers_null ; echo $?
		2

	Un composant du chemin d'acces n'existe pas :

		$ ./maccess -r TP1/cours/maccess.c ; echo $?
		2

	Un composant du chemin n'est pas un repertoire :

		$ ./maccess -r prlimit.c/maccess.c ; echo $?
		20

	En demandant une ecriture sur un systeme de fichiers en lecture seule :

		$ ./maccess -v -w /media/meyer/Data\ disc\ \(06\ août\ 15\)/; echo $?
		On demande une ecriture sur un systeme de fichier en lecture seule
		30



PS : Nous avons cree un script shell mais celui ci ne semble pas fonctionner dans les salles de tp.
C'est pourquoi nous fournissons avec notre archive un dossier /img montrant les codes d'erreurs
que peut renvoyer la commande ./maccess

****************************************************
*******************MACCESS**************************
****************************************************

	$ >lecture_seule
	$ chmod 411 lecture_seule 
	$ ./maccess -v -w lecture_seule ;echo $?
	13

	$ ./maccess -r -x -v lecture_seule; echo $?
	Usage: ./maccess [-r,-w,-x] [-v] name
	1

	$ ./maccess -v -r lecture_seule
	0

	$ ./maccess -rv lecture_seule; echo $?
	Usage: ./maccess [-r,-w,-x] [-v] name
	1

	$ ./maccess -v -x lecture_seule; echo $?
	La permission indiquee n'est pas valide pour ce fichier
	13

	$ ./maccess -v -x lecture_seue; echo $?
	Le lien du fichier n'existe pas ou le lien symbolique est rompu
	2



****************************************************
****************MACCESS_PLUS************************
****************************************************

	$ ./maccess+ -v -w lecture_sule; echo $?
	Le lien du fichier n'existe pas ou le lien symbolique est rompu
	2

	$ ./maccess+ -v -w lecture_seule; echo $?
	La permission indiquee n'est pas valide pour ce fichier
	13

	$ ./maccess+ -v -w -x lecture_seule; echo $?
	La permission indiquee n'est pas valide pour ce fichier
	13
	
	$ ./maccess+ -vwx lecture_seule; echo $?
	Expected option of longueur 2
	1

	$ ./maccess_plus -r lecture_seule; echo $?
	0








