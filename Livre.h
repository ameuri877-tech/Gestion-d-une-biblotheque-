#pragma once
using namespace std;
#include "Date.h"
#include <string>
#include<iostream>

namespace GestionBibliotheque {
	class Livre
	{
	private:
		const int id;
		string auteur, titre;
		Date parution;
		int* notes;
		int nbNotes;
		int capacite;
		static int compteurId, nbrInstances;

	public:
		Livre(string t, string a, Date p, int cap);
		Livre(const Livre& l);
		Livre& operator=(const Livre& l);
		~Livre();
		void afficher()const;



	};
}

