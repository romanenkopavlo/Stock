#include "IHM.h";
#include "Gestion.h";
#include "Article.h";
#include <iostream>;
#include <string>;

IHM::IHM() {
	gestion = new Gestion();
}

IHM::~IHM() {
	delete gestion;
}

void IHM::afficherMenu()
{
	while (choix != 5) {
		cout << "..........Menu.........." << endl;
		cout << "Tapez 1 pour ajouter un article......" << endl;
		cout << "Tapez 2 pour modifier un article......" << endl;
		cout << "Tapez 3 pour supprimer un article......." << endl;
		cout << "Tapez 4 pour lire vos articles........" << endl;
		cout << "Tapez 5 pour arreter votre session......." << endl;

		cout << "Votre choix: ";
		cin >> choix;

		switch (choix)
		{
		case 1:
			ajouterArticle();
			break;
		case 2:
			modifierArticle();
			break;
		case 3:
			supprimerArticle();
			break;
		case 4:
			lireArticles();
			break;
		case 5:
			arreterSession();
			break;
		}
	}
}


void IHM::ajouterArticle()
{
	cout << "Entrez le nom de votre article: ";
	cin >> nomArticle;
	gestion->ajouterArticle(nomArticle);
	cout << "Article " << nomArticle << " a ete cree" << endl;
}

void IHM::modifierArticle()
{
	numeroArticle = 0;
	cout << "Entrez le numero d'article que vous voulez modifier: ";
	cin >> numeroArticle;
	cout << "Entrez le prix HT de votre article: ";
	cin >> prixHT;
	cout << "Entrez la quantite de stock de votre article: ";
	cin >> stock;
	gestion->modifierArticle(numeroArticle, prixHT, stock);
	cout << gestion->listeDesArticles->at(numeroArticle - 1)->getNom() << " a ete modifie" << endl;
}

void IHM::supprimerArticle()
{
	numeroArticle = 0;
	cout << "Entrez le numero d'article que vous voulez supprimer: ";
	cin >> numeroArticle;
	nomArticle = gestion->listeDesArticles->at(numeroArticle - 1)->getNom();
	gestion->supprimerArticle(numeroArticle);
	cout << nomArticle << " a ete supprime" << endl;
}

void IHM::lireArticles()
{
	if (gestion->listeDesArticles->size() > 0)
	{
		gestion->lireArticles();
	}
	else {
		cout << "Vous n'avez aucun article." << endl;
	}
}

void IHM::arreterSession()
{
	gestion->supprimerLesArticles();
	cout << "La fin de session.";
}