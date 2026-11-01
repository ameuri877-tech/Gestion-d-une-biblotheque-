#include "Livre.h"
#include<iostream>
using namespace std;
namespace GestionBibliotheque {
	int Livre::compteurId = 1;
	int Livre::nbrInstances = 0;


	Livre::Livre(string t, string a, Date p, int cap)
		: id(compteurId++), titre(t), auteur(a), parution(p), capacite(cap)
	{
		if (capacite <= 0) capacite = 1;
		notes = new int[capacite];
		nbNotes = 0;
		nbrInstances++;
	}

	Livre::Livre(const Livre& l):
		id(compteurId++),
		titre(l.titre),
		auteur(l.auteur),
		parution(l.parution)
	{
		notes = new int[capacite];
		nbNotes = l.nbNotes;
		for (int i = 0; i < nbNotes && i < capacite; i++) {
			notes[i] = l.notes[i];
		}
		nbrInstances++;
	}

	Livre& Livre::operator=(const Livre& l)
	{
		if (this != &l) {
			titre = l.titre;
			auteur = l.auteur;
			parution = l.parution;
			nbNotes = l.nbNotes;


			if (capacite != l.capacite) {
				delete[] notes;
				capacite = l.capacite;
				notes = new int[capacite];
			}
			for (int i = 0; i < nbNotes; i++) {
				notes[i] = l.notes[i];
			}

		}
		return *this;
	}


		Livre::~Livre() {
			delete[] notes;
			notes = nullptr;
			nbrInstances--;
		}
		void Livre::afficher() const {
			cout << "Livre #" << id << " : " << titre << " par " << auteur << " (";
			parution.afficher();
		
		}

}