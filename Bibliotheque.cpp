#include "Bibliotheque.h"
#include <iostream>
using namespace std;

namespace GestionBibliotheque {

    int Bibliotheque::nbBibliotheques = 0;

    
    Bibliotheque::Bibliotheque(string n, int cap) : nom(n), capacite(cap) {
        if (capacite <= 0) capacite = 1;
        livres = new Livre * [capacite];
        nbLivres = 0;
        nbBibliotheques++;
    }

   
    Bibliotheque::Bibliotheque(const Bibliotheque& b)
        : nom(b.nom), capacite(b.capacite), nbLivres(b.nbLivres)
    {
        livres = new Livre * [capacite];
        for (int i = 0; i < nbLivres; i++) {
           
            livres[i] = new Livre(*(b.livres[i]));
        }
        nbBibliotheques++;
    }

   
    Bibliotheque& Bibliotheque::operator=(const Bibliotheque& b) {
        if (this != &b) {
            
            for (int i = 0; i < nbLivres; i++) {
                delete livres[i];
            }
            delete[] livres;

            
            nom = b.nom;
            capacite = b.capacite;
            nbLivres = b.nbLivres;
            livres = new Livre * [capacite];
            for (int i = 0; i < nbLivres && i < capacite; i++) {
                livres[i] = new Livre(*(b.livres[i]));
            }
        }
        return *this;
    }

    Bibliotheque::~Bibliotheque() {
       
        for (int i = 0; i < nbLivres; i++) {
            delete livres[i];
        }
        delete[] livres;
        livres = nullptr;
        nbBibliotheques--;
    }

    
    Livre& Bibliotheque::ajouterLivre(const Livre& l) {
        if (nbLivres < capacite) {
            livres[nbLivres] = new Livre(l); 
            return *(livres[nbLivres++]);
        }
        cout << "Erreur : Bibliotheque pleine !" << endl;
        return *(livres[0]); 
    }

    
    Bibliotheque& Bibliotheque::operator+=(const Livre& l) {
        ajouterLivre(l);
        return *this;
    }

    
    void Bibliotheque::afficher() const {
        cout << "--- Bibliotheque : " << nom << " ---" << endl;
        for (int i = 0; i < nbLivres; i++) {
            livres[i]->afficher();
        }
    }
}

