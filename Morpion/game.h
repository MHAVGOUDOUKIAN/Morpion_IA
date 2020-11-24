#ifndef GAME_H
#define GAME_H

#include "board.h"

// Déclaration des fonctions
void initGame(morpion tab);							// Initialise le morpion à -1
int jouer(morpion tab, int i, int j, int player);	// Met X ou O selon les corddonées choisies
int gagnant(morpion tab, int player);				// Vérifie s'il y a un gagnant

#endif