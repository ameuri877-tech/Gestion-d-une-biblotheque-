#pragma once
#include<iostream>
#include "Livre.h"
using namespace std;
namespace  GestionBibliotheque{
	class Bibliotheque
	{ 
	private:
		string nom;
		Livre** livres;
		int capacite;
	    int nbLivres;
		static int nbBibliotheques;
	public:
		Bibliotheque(string n, int cap);
		Bibliotheque(const Bibliotheque& b);
		Bibliotheque& operator=(const Bibliotheque& b);
		~Bibliotheque();
		Livre& ajouterLivre(const Livre& l);
		Bibliotheque& operator+=(const Livre& l);

		void afficher() const;

	};

}


