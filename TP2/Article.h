#pragma once
using namespace std;
#include <string>;

class Article
{
	string nom;
public:
	Article(string n);
	string getNom();
	double prixHT;
	int stock;
};