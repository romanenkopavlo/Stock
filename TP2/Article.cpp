#include "Article.h"

Article::Article(string n)
{
    nom = n;
}

string Article::getNom()
{
    return nom;
}

void Article::setStock(int s)
{
    stock = s;
}