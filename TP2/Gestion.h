#pragma once
using namespace std;
#include <string>;
#include <vector>;
#include <fstream>;
#include "Article.h";
#include "Commande.h";

class Gestion
{
public:
    Gestion();
    ~Gestion();
    vector <Commande*> * lesCommandes;
    vector <Article*> * listeDesArticles;
    ofstream fichierEcrire;
    void ajouterArticle(string nom);
    void supprimerArticle(int index);
    void modifierArticle(int index, double prixHT, int stock);
    void lireArticles();
    void supprimerLesArticles();
    void supprimerLesCommandes();
};