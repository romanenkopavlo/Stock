#include "Gestion.h";
#include "Article.h";
#include <iostream>;
#include <sstream>;
#include <string>;
using namespace std;


Gestion::Gestion()
{
	listeDesArticles = new vector <Article*>;
	fichierEcrire.open("sauvegarde.txt", ios::app);
	ifstream fichierLire("sauvegarde.txt");


	if (fichierLire.is_open()) {
		string ligne;
		
		while (getline(fichierLire, ligne))
		{
			stringstream ss(ligne);
			string tempNom;
			double tempPrixHT;
			int tempStock;

			if (getline(ss, tempNom, ',') && ss >> tempPrixHT && ss.ignore(1) && ss >> tempStock)
			{
				Article* article = new Article(tempNom);
				article->prixHT = tempPrixHT;
				article->stock = tempStock;
				listeDesArticles->push_back(article);
			}
		}
		fichierLire.close();
	}
}

Gestion::~Gestion()
{
	supprimerLesArticles();
	delete listeDesArticles;
	fichierEcrire.close();
}

void Gestion::ajouterArticle(string nom)
{
	Article* article = new Article(nom);
	article->prixHT = 0.0;
	article->stock = 0;
	listeDesArticles->push_back(article);
}


void Gestion::supprimerArticle(int index)
{
	for (int i = 0; i < listeDesArticles->size(); i++)
	{
		if (i == index - 1)
		{
			Article* article = listeDesArticles->at(index - 1);
			delete article;
			listeDesArticles->erase(listeDesArticles->begin() + index - 1);
			break;
		}
	}
}


void Gestion::modifierArticle(int index, double prixHT, int stock)
{
	for (int i = 0; i < listeDesArticles->size(); i++)
	{
		if (i == index - 1)
		{
			listeDesArticles->at(i)->prixHT = prixHT;
			listeDesArticles->at(i)->stock = stock;
			if (fichierEcrire.is_open())
			{
				fichierEcrire << listeDesArticles->at(i)->getNom() << "," << listeDesArticles->at(i)->prixHT << "," << listeDesArticles->at(i)->stock << endl;
			}
			break;
		}
	}

}


void Gestion::lireArticles()
{
	for (int i = 0; i < listeDesArticles->size(); i++) {
		cout << "Article numero " << i + 1 << ". Nom: " << listeDesArticles->at(i)->getNom() << ". Prix HT: " << listeDesArticles->at(i)->prixHT << ". Stock: " << listeDesArticles->at(i)->stock << endl;
	}
}

void Gestion::supprimerLesArticles()
{
	if (listeDesArticles->size() > 0)
	{
		for (Article* article : *listeDesArticles)
		{
			delete article;
		}
		listeDesArticles->clear();
	}
}