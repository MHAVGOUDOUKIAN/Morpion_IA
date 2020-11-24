#include "uvu.h"


void uvu(morpion tab)
{
	int x,y,res,player = 0;
	int out = 1;

	// Nettoyage terminal
  	system("clear");

	while (out) {  // While nécessaire en cas de 'n' non conforme
		printf("\nEntrer la taille du morpion supérieur ou égale à 3 :\n");
    	scanf("%d", &n);

    	if (n > 2) {
    		initGame(tab);

    		// Nettoyage terminal
  			system("clear");

    		while (out) {  // Permet de jouer en boucle
    			printBoard(tab);

    			player++; // Juste pour l'affichage
		        printf("Joueur %d à toi de jouer !\n", player);
		        player--; // Juste pour l'affichage
		        // Demande à l'utilisateur de rentrer les coordonnées X Y
		        printf("\nEntrer les coordonnées X Y :\n");
		        printf("X = ");
		        scanf("%d", &x);
		        printf("Y = ");
		        scanf("%d", &y);

		        if (jouer(tab, x, y, player) == 0) {
		        	// Tests conditions vainqueur 
		        	res = gagnant(tab, player);
					// Si res == 0 , rien ne se passe
					if (res != 0) {
						// Affichage final du morpion 
						printBoard(tab);
						if (res == 1) {  // Si gagné res = 1, player gagné
							out = 0;
							player++;  // Pour l'affichage
							printf("\nJoueur %d a gagné !\n\n", player);
						}
						else if (res == -1) {  // Si match nul
							out = 0;
							printf("\nMatch nul\n\n");
						}
					}
					// Changement de joueur
					if (player == 0)
						player++;
					else
						player--;
		        }
		        else
		        	erreur();
    		}
    		out = 0;  // On sort de la boucle
    	}
    	else
    		erreur();
	}
}
