#pragma once
namespace GestionBibliotheque {
	class Date
	{
	private:
		int jour, mois, annee;
	public:
		Date(int j, int m, int a);
		static bool estBissextile(int annee);
		static bool estValide(int j, int m, int a);
		bool operator==(const Date& d) const;
		bool operator<(const Date& d) const;
		void afficher() const;


	};
}

