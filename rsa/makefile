##############################################################################
#									     #
#  Software zum Buch "Kryptographie in C und C++"                            #
#  Autor: Michael Welschenbach						     #
#									     #
#  Quelldatei makefile fuer RSADEMO					     #
#									     #
#  Copyright (C) 1998-2001 by Michael Welschenbach			     #
#  Copyright (C) 1998-2001 by Springer-Verlag Berlin, Heidelberg	     #
#									     #
#  All Rights Reserved							     #
#									     #
#  Die Software darf fuer nichtkommerzielle Zwecke frei verwendet und	     #
#  veraendert werden, solange die folgenden Bedingungen anerkannt werden:    #
#									     #
#  (1) Alle Aenderungen muessen als solche kenntlich gemacht werden, so dass #
#      nicht der Eindruck erweckt wird, es handle sich um die Original-      #
#      Software.							     #
#									     #
#  (2) Die Copyright-Hinweise und die uebrigen Angaben in diesem Feld	     #
#      duerfen weder entfernt noch veraendert werden.			     #
#									     #
#  (3) Weder der Verlag noch der Autor uebernehmen irgendeine Haftung fuer   #
#      eventuelle Schaeden, die aus der Verwendung oder aus der Nicht-       #
#      verwendbarkeit der Software, gleich fuer welchen Zweck, entstehen     #
#      sollten, selbst dann nicht, wenn diese Schaeden durch Fehler verur-   #
#      sacht wurden, die in der Software enthalten sein sollten.             #
#									     #
##############################################################################


CFLAGS = -c -O2 -Wall -ansi -I../src -o $@

#Parameter fuer Unix/Linux
#STDCPP=stdc++
#EXECUTABLE = -o rsademo

#STDCPP=stdcpp
EXECUTABLE = -o rsatest.exe


rsatest:  rsatest.o flint.o ripemd.o
	gcc $(EXECUTABLE) rsatest.o flint.o ripemd.o

rsatest.o: rsatest.c
	gcc $(CFLAGS) rsatest.c

flint.o: ../src/flint.c
	gcc $(CFLAGS) ../src/flint.c

ripemd.o: ../src/ripemd.c
	gcc $(CFLAGS) ../src/ripemd.c

