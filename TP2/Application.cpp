#include "Application.h"
#include "IHM.h";

void main()
{
	IHM * programme = new IHM();
	programme->afficherMenu();
	delete programme;
}