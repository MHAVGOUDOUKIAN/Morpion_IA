/*  Projet IA : Programmation du jeu morpion en C intégrant l'IA
*
*   Membres du groupe: 
*       HAVGOUDOUKIAN Maxime
*		THO Yann
*
*   Fichier: morpion.c
*/
#include "board.h"
#include "ia.h"
#include "uvu.h"

int main(void)
{
	morpion tab;	
	int out = 1;  

	// Nettoyage terminal
  	system("clear");
  	
  	printf("---- JEU DU MORPION ----\n\n");	

  	while (out) {
  		printf("-- Menu --\n\n");
		printf("Sélectionner option :\n");
	  	printf("-1- Solo\n");
	  	printf("-2- 2 joueurs\n");
	  	printf("-3- Quitter\n\n");

	  	scanf("%d", &n);

	  	if (n == 1)
	  		vsIA(tab);
	  	else if (n == 2)
	  		dvd(tab);
	  	else if (n == 3)
	  		out = 0;
	  	else
	  		erreur();
  	}
}
