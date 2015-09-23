#!/bin/sh

mkdir test1
echo Je cree un fichier > test/toto.txt
ln -s test/toto.txt test/toto1

./mdu test1
du -B512 test1
./mdu -L test1
du -B512 -L test1
./mdu -b test1
du -b test1
./mdu -b -L test1
du -b -L test1

mkdir test2
mkdir test2/test2_1
echo Je suis un fichier un peu plus long que dans le dossier de test1 test2/test2_1/toto.txt
echo Je suis un autre fichier un peu plus long que dans le dossier de test1 test2/test2_1/toto1.txt
mkdir test2/test2_2
mkdir test2/test2_3
