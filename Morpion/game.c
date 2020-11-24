#include "game.h"

void initGame(morpion tab)
{
	int i,j;

	// Initialisation du morpion à -1
	for (i = 0; i < n; ++i) {
	    for (j = 0; j < n; ++j)
	    	tab[i][j] = -1;
  	}
}

int jouer(morpion tab, int i, int j, int player)
{
	// Si les coordonnées conviennent au tabeau
	if (i >= 0 && i < n && j >= 0 && j < n) {
		// Si la case est vide
	    if (tab[i][j] == -1)
	    {
	    	tab[i][j] = player;
	      	return 0;
	    }
	}
	// Retourne 1 si la case n'est pas vide 
	// ou s'il y a dépassement du tabeau
	// REJOUER
	return 1;
}

int gagnant(morpion tab, int player)
{
	int i,j,m,tmp = 0;

	// Analyse chaque lignes
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (tab[i][j] == player)
				tmp++;
			// Si gagnant
			if (tmp == n)
				return 1;
		} 
		tmp = 0;
	}

	// Analyse chaque colonnes
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (tab[j][i] == player)
				tmp++;
			// Si gagnant
			if (tmp == n)
				return 1;
		} 
		tmp = 0;
	}

	// Analyse la diagonale directe
	for (i = 0; i < n; ++i) {
		if (tab[i][i] == player)
			tmp++;
		// Si gagnant
		if (tmp == n)
			return 1;
	}
	tmp = 0;

	// Analise la diagonale indirecte
	m = n-1;
	for (i = 0; i < n; ++i) {
		if (tab[i][m-i] == player)
			tmp++;
		// Si gagnant
		if (tmp == n)
			return 1;
	}

	// Si aucun gagnant avant n² tours
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (tab[i][j] == -1)
				return 0;
		}
	}

	// Par défaut : si aucun gagnant au bout de n² tours
  	return -1;
}
