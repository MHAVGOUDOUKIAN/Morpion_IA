#include "ia.h"


coord MinMax(morpion tab)
{
    int score,valeur,i,j;
    coord crdxy;

    score = INFINI;
    crdxy.x = 0;
    crdxy.y = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (tab[i][j] == -1) {
                tab[i][j] = 1;
                valeur = Max(tab);
                if (score > valeur) {
                    score = valeur;
                    crdxy.x = i;
                    crdxy.y = j;
                }
                tab[i][j] = -1;
            }
        }
    }
    return crdxy;
}

int Max(morpion tab)
{
	int p_one = gagnant(tab, 0), p_two = gagnant(tab, 1);
	int score,i,j,valeur;

	if (p_one == 1) 
		return 10;  // score = 10
	else if (p_two == 1)
		return -10; // score = -10
	else if (p_one == -1 || p_two == -1)
		return 0;   // score = 0

	score = -INFINI;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (tab[i][j] == -1) {
				tab[i][j] = 0;  // La case prend X
				valeur = Min(tab);
				if (score < valeur)
					score = valeur;
				tab[i][j] = -1;
			}
		}
	}
	return score;
}

int Min(morpion tab)
{
	int p_one = gagnant(tab, 0), p_two = gagnant(tab, 1);
	int score,i,j,valeur;

	if (p_one == 1) 
		return 10;  // score = 10
	else if (p_two == 1)
		return -10; // score = -10
	else if (p_one == -1 || p_two == -1)
		return 0;   // score = 0

	score = INFINI;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (tab[i][j] == -1) {
				tab[i][j] = 1;  // La case prend O
				valeur = Max(tab);
				if (score > valeur)
					score = valeur;
				tab[i][j] = -1;
			}
		}
	}
	return score;
}

void vsIA(morpion tab)
{
	int x,y,res, p_one = 0, p_IA = 1;
	int out = 1;
	coord crdxy;

	// Nettoyage terminal
  	system("clear");

  	while (out) {  // While nécessaire en cas de 'n' non conforme
  		printf("\nEntrer la taille du morpion supérieur ou égale à 3 :\n");
    	scanf("%d", &n);

    	if (n > 2) {
    		initGame(tab);

    		while (out) {  // Permet de jouer en boucle
    			printBoard(tab);

    			printf("A toi de jouer !\n");
    			printf("\nEntrer les coordonnées X Y :\n");
    			printf("X = ");
		        scanf("%d", &x);
		        printf("Y = ");
		        scanf("%d", &y);

		        // Tour du joueur
		        if (jouer(tab, x, y, p_one) == 0) {
		        	// Tests conditions joueur vainqueur 
		        	res = gagnant(tab, p_one);
					// Si res == 0 , rien ne se passe
					if (res != 0) {
						// Affichage final du morpion 
						printBoard(tab);
						if (res == 1) {  // Si gagné res = 1
							out = 0;
							printf("\n! You win !\n\n");
						}
						else if (res == -1) {  // Si match nul
							out = 0;
							printf("\nMatch nul\n\n");
						}
					}

					// Tour de l'IA
					crdxy = MinMax(tab);
					x = crdxy.x;
					y = crdxy.y;
			        if (jouer(tab, x, y, p_IA) == 0) {
			        	// Tests conditions IA vainqueur 
			        	res = gagnant(tab, p_IA);
						// Si res == 0 , rien ne se passe
						if (res != 0) {
							// Affichage final du morpion 
							printBoard(tab);
							if (res == 1) {  // Si gagné res = 1
								out = 0;
								printf("\n! Game over !\n\n");
							}
							else if (res == -1) {  // Si match nul
								out = 0;
								printf("\nMatch nul\n\n");
							}
						}
					}
				}
				else 
					erreur();
    		}
    	}
    	else 
    		erreur();
  	}
}