// Gestionbiblio.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Date.h"
#include "Livre.h"
#include "Bibliotheque.h"
using namespace std;
using namespace GestionBibliotheque;
    int main()
    {
        cout << "=== 1. TEST DE LA CLASSE DATE ===" << endl;
        cout << "2024 est bissextile ? " << Date::estBissextile(2024)  << endl;
        cout << "2023 est bissextile ? " << Date::estBissextile(2023) << endl;

        cout << "Date 15/05/2020 valide ? " << Date::estValide(15, 5, 2020 ) << endl;
        cout << "Date 32/12/2021 valide ? " << Date::estValide(32, 12, 2021 )<< endl;
            
        Date d1(15, 5, 2020);
        Date d2(30, 2, 2024); 
        cout << "Date d1 : "; d1.afficher(); cout << endl;
        cout << "Date d2 (invalide) : "; d2.afficher(); cout << endl;

        cout << "\n=== 2. TEST DE LA CLASSE LIVRE ===" << endl;
        Livre l1("AA", "MM", d1, 3);
        cout << "Livre l1 : "; l1.afficher(); cout << endl;

        cout << "-> Test Constructeur de recopie (l2 = l1)" << endl;
        Livre l2 = l1;
        cout << "Livre l2 : "; l2.afficher(); cout << endl;

        
        cout << "-> Test Operateur = (l3 = l1)" << endl;
        Livre l3("NN", "ZZ", Date(1, 1, 2000), 1);
        l3 = l1;
        cout << "Livre l3 : "; l3.afficher(); cout << endl;

        cout << "\n=== 3. TEST DE LA CLASSE BIBLIOTHEQUE ===" << endl;
        Bibliotheque biblio("Centrale", 2); 

        
        cout << "-> Ajout de l1 et l2" << endl;
        biblio.ajouterLivre(l1);
        biblio.ajouterLivre(l2);

        
        cout << "-> Ajout de l3 avec operator+=" << endl;
        biblio += l3; 

        cout << "\n-> Affichage du catalogue :" << endl;
        biblio.afficher();

        
        cout << "\n-> Test Constructeur de recopie (biblio2 = biblio)" << endl;
        Bibliotheque biblio2 = biblio;
        biblio2.afficher();

        
        cout << "\n-> Test Operateur = (biblio3 = biblio)" << endl;
        Bibliotheque biblio3("Annexe", 5);
        biblio3 = biblio;
        biblio3.afficher();

        cout << "\n=== 4. FIN DU PROGRAMME ===" << endl;
        cout << "Destruction de tous les objets..." << endl;

        return 0;

    }


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
