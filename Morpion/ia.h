#ifndef IA_H
#define IA_H

#include "board.h"
#include "game.h"

// Déclaration des types
typedef struct nCoord {
  int x, y;
}coord;

// Déclaration des fonctions
void vsIA(morpion tab);								// Mode de jeu vs IA
coord MinMax(morpion tab);		// IA calcule les meilleures couts possibles 
int Min(morpion tab);
int Max(morpion tab);

#endif