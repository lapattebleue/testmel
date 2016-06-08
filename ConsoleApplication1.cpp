// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"



int main(int argc, char *argv[])
{

#define TAILLE_MAX_GENRE 2
#define TAILLE_MAX_PRENOM 26
#define TAILLE_MAX_PRENOMVERIF 26
#define TAILLE_MAX_ANNEE 5
#define TAILLE_MAX_NAISSANCE 18
#define TAILLE_MAX_LIGNE 48

	FILE* finput = NULL;
	FILE* foutput = NULL;
	char prenom[TAILLE_MAX_PRENOM] = ""; // Chaîne vide de taille TAILLE_MAX
	char ligne[TAILLE_MAX_LIGNE] = "";
	char genre[TAILLE_MAX_GENRE] = "";
	char annee[TAILLE_MAX_ANNEE] = "";
	char naissance[TAILLE_MAX_NAISSANCE] = "";
	char prenomverif[TAILLE_MAX_PRENOMVERIF] = "";
	int genretest;
	int compteur = 0;
	char affichageCompteur[18];

	fopen_s(&finput, "nat2013.txt","r");
	fopen_s(&foutput, "output.txt", "w");
	if (foutput != NULL && foutput != NULL) {
		//do {
		while (!feof(finput)) {
			fgets(genre, TAILLE_MAX_GENRE, finput); // On lit maximum TAILLE_MAX caractères du fichier finput, on stocke le tout dans "chaine"
			fgets(prenom, TAILLE_MAX_PRENOM, finput);
			fgets(annee, TAILLE_MAX_ANNEE, finput);
			fgets(naissance, TAILLE_MAX_NAISSANCE, finput);
			genretest = atoi(genre); // atoi pour convertir une chaine de caractères en int

			if (genretest == 1) {		// on teste le genre si 1 = M sinon F
				fputs("M\n", foutput);
			}
			else {
				fputs("F\n", foutput);
			}

			fputs(prenom, foutput);
			fputs("\n", foutput);
			strcpy_s(prenomverif, prenom); // On copie la valeur de prenom à prenom verif

			while (strcmp(prenomverif, prenom) == 0 && (!feof(finput))) { // tant que prenomverif[TAILLE_MAX_PRENOMVERIF] = prenom[TAILLE_MAX_PRENOM]; ET fin de fichier pour la dernière entrée
				compteur = atoi(naissance) + compteur; // atoi pour convertir une chaine de caractères en int
				fgets(genre, TAILLE_MAX_GENRE, finput);
				fgets(prenom, TAILLE_MAX_PRENOM, finput);
				fgets(annee, TAILLE_MAX_ANNEE, finput);
				fgets(naissance, TAILLE_MAX_NAISSANCE, finput);
			}
			sprintf_s(affichageCompteur, "%d", compteur); // reconvertir le int en chaine
			fputs(affichageCompteur, foutput);
			fputs("\n\n", foutput);
			compteur = 0; // on remet le compteur à 0 pour le prochain prénom
		}
	}
	else {
		printf("Il y a eu une erreur à l'ouverture du fichier");
	}

	fclose(finput);
	fclose(foutput);

}
