#include "Date.h"
#include<iostream>
using namespace std;
namespace GestionBibliotheque {



	Date::Date(int j, int m, int a)
	{
		if (estValide(j,m,a)) {
			this->jour = j;
			this->annee = a;
			this->mois = m;
		}
		else {
			this->jour = 1;
			this->annee = 2000;
			this->mois = 1;

		}

	}

	bool Date::estBissextile(int a)
	{
		if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
			return true;
		else
			return false;
	}

	bool Date::estValide(int j, int m, int a) {
		if (m < 1 || m > 12 || j < 1 || j > 31) return false;

		int joursParMois[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (m == 2 && estBissextile(a)) {
			joursParMois[2] = 29;
		}
		return j <= joursParMois[m];
	}


	bool Date::operator==(const Date& d) const
	{
		if (this->jour == d.jour && this->mois == d.mois && this->annee == d.annee)
			return true;
		else
			return false;

	}

	bool Date::operator<(const Date& d) const
	{
		if (this->jour < d.jour && this->mois < d.mois && this->annee < d.annee)
			return true;
		else
			return false;
	}

	void Date::afficher() const {
		cout << jour << "/" << mois << "/" << annee;
	}


}


