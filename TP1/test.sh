#!/bin/sh

if [ ! -e '0' ] 
then
    mkdir 0
fi

for i in `seq 1 41`
do
    a=$(($i - 1))
    ln -s $a $i
done

fichier=''
dossier='12341234'

for i in `seq 1 512`
do   
    mkdir ${fichier}${dossier}
    if [ ! $? -eq 0 ]
    then
	break
    fi

    if [ -d $fichier$dossier ]
    then
	fichier=${fichier}${dossier}'/'
    fi
done

touch ${fichier}'a'

./maccess -x maccess.c
echo 'Code d erreur si la permission du fichier est mauvaise :' $?

./maccess -r 41
echo 'Code d erreur si il y a trop de lien symbolique :' $?

./maccess -r ${fichier}'a'
echo 'Code d erreur si le lien du fichier est trop long :' $?

./maccess -r prlimit.c/maccess.c
echo 'Code d erreur si un composant du chemin n est pas un repertoire :' $?

./maccess -r TP1/cours/maccess.c
echo 'Code d erreur si un composant du chemin d acces n existe pas :' $?

rm -r '0'
./maccess -r '1'
echo 'Code d erreur si la cible du lien n exixte pas :' $?

for i in `seq 1 41`
do
    rm -r $i
done

rm -r 12341234
