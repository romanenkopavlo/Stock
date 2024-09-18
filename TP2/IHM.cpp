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
	while (choix != 6) {
		cout << "..........Menu.........." << endl;
		cout << "Tapez 1 pour ajouter un article......" << endl;
		cout << "Tapez 2 pour modifier un article......" << endl;
		cout << "Tapez 3 pour supprimer un article......." << endl;
		cout << "Tapez 4 pour lire vos articles........" << endl;
		cout << "Tapez 5 pour faire une commande......." << endl;
		cout << "Tapez 6 pour arreter votre session......." << endl;

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
			faireUneCommande();
			break;
		case 6:
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

void IHM::faireUneCommande()
{
	cout << "Bienvenue a la page de la creation d'une commande." << endl;
	cout << "Voici les articles disponibles a commander: " << endl;
	gestion->lireArticles();
	int choix = 0;
	int quantite = 0;
	int isEnd;

	do
	{
		cout << "Choisissez un article que vous voulez commander en entrant son numero: ";
		cin >> choix;
		cout << "Vous avez choisi l'article numero " << choix << ". Son nom est " << gestion->listeDesArticles->at(choix - 1)->getNom() << endl;
		cout << "Combien d'articles de ce type voulez vous commander: ";
		cin >> quantite;
		cout << "Est-ce que vous voulez commander un autre article? (0 - oui, 1 - non): ";
		cin >> isEnd;

		Commande* commande = new Commande();
		commande->numero = choix;
		commande->quantite = quantite;
		commande->prixTotal = quantite * gestion->listeDesArticles->at(choix - 1)->prixHT;
		gestion->lesCommandes->push_back(commande);

		gestion->listeDesArticles->at(choix - 1)->setStock((gestion->listeDesArticles->at(choix - 1)->stock) - quantite);
		
		if (isEnd == 1)
		{
			cout << "Votre commande: " << endl;
			for (int i = 0; i < gestion->lesCommandes->size(); i++)
			{
				cout << "------------------- Numero " << (i + 1) << " --------------------" << endl;
				cout << "Numero d'article: " << gestion->lesCommandes->at(i)->numero << endl;
				cout << "Nom d'article: " << gestion->listeDesArticles->at(gestion->lesCommandes->at(i)->numero - 1)->getNom() << endl;
				cout << "Quantite: " << gestion->lesCommandes->at(i)->quantite << endl;
				cout << "Prix total HT: " << gestion->lesCommandes->at(i)->prixTotal << endl;
				cout << "Prix TTC: " << gestion->lesCommandes->at(i)->prixTotal * 1.2 << endl;
				cout << "--------------------------------------------------" << endl;
			}
		}
	} while (isEnd != 1);
}

void IHM::arreterSession()
{
	cout << "La fin de session.";
}