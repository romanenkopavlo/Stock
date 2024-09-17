#include "Gestion.h";
#include "Article.h";
#include <iostream>;
using namespace std;


Gestion::Gestion()
{
	listeDesArticles = new vector <Article*>;
}

Gestion::~Gestion()
{
	supprimerLesArticles();
	delete listeDesArticles;
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