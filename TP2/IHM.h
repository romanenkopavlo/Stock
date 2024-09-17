#pragma once
#include "Gestion.h";

class IHM
{
private:
	Gestion * gestion;
	string nomArticle;
	int choix = 0;
	int numeroArticle, stock;
	double prixHT;
	void ajouterArticle();
	void supprimerArticle();
	void lireArticles();
	void modifierArticle();
	void arreterSession();
public:
	IHM();
	~IHM();
	void afficherMenu();
};

