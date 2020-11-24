#include "board.h"

void printBoard(morpion tab)
{
	int i,j,k;

	printf("\n-- Morpion de taille %dx%d --\n\n", n, n);

	// Affiche les coordonées X
	printf(" ");
 	for (i = 0; i < n; i++) 
 		printf(" %d", i);
 	// Juste affichage
  	printf("\n ");
  	for (k = 0; k <= (2*n); k++)
  		printf("-");
  	printf("\n");
  	for (i = 0; i < n; ++i) {
  		printf(" |");
  		for (j = 0; j < n; j++) {
  			if (tab[i][j] == -1)
  				printf(" |");
  			else {
  				if (tab[i][j] == 1)
  					printf("o|");
  				else
  					printf("x|");
  			}
  		}
  		// affiche les coordonnées Y
    	printf(" %d", i);
    	// Juste affichage
	    printf("\n ");
	    for (k = 0; k <= (2*n); k++)
	    	printf("-");
	    printf("\n");
  	}
  	printf("\n");
}

void erreur()
{
	// Nettoyage terminal
	system("clear");
	printf("! ATTENTION ERREUR DE SAISIE !\n\n");		
}
