#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>

#define INFINI 2894

// Déclaration des types
typedef char morpion[INFINI][INFINI];		// Limité à 2894 pour éviter les dépassement de tableau

// Déclaration des variables globales
int n;										// Dimension du morpion

// Déclaration des fonctions
void printBoard(morpion tab);				// Affiche le tableau
void erreur();								// Affiche un message d'erreur	

#endif