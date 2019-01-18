#ifndef hrac
#define hrac

#include <iostream>
#include "Mec.h"
#include "Brnenie.h"

using namespace std;

namespace Mechanika
	{
	class Hrac
	{
	protected:
	    /** meno hraca */
		string m_meno;

		/** ukazatel na "Mec" ktori vlastni */
		Mec* m_zbran;

		/** ukazatel na brnenie ktore vlastni */
		Brnenie* m_zbroj;

		/** premenne ktore obsahuju jeho hlavne vlastnosti */
		int m_zivot, m_utok, m_obrana;

		/** premenne ktore obsahuju informacie o jeho pozicii na matici */
		int m_x,m_y;

		/** premenne ktore obsahuju jeho poslednu poziciu, teda nie aktualnu */
		int m_xl,m_yl;;

	public:
	    /** konstruktor ktory prebera meno od uzivatela, a Utok a Obranu podla toho aky potom sa zvolil */
		Hrac(string meno, int utok, int obrana);

        /** metoda ktora nastavi hracovi brnenie */
		void setZbroj(Brnenie* m_zbroj);

        /** metoda ktora nastavi hracovi mec */
		void setZbran(Mec* m_zbran);

        /** metoda ktora vrati hracove meno */
		string getMeno();

        /** metoda ktora nastavi hracovi novu poziciu na matici */
		void setPozicia(int x, int y);

        /** metoda ktora vrati jeho hodnotu na ose X */
		int getX();

        /** hodnota ktora zvysi jeho utok o cislo 1, zakazdym ked zabije priseru */
		void Zabil();

        /** metoda ktora vrati jeho hodnotu na ose Y  */
		int getY();

        /** metoda ktora nastavi jeho suradnicu na poslednu na ktorej sa nachadzal, pokial chce ukoncit/vyjst z boja s priserou */
		void Utec();

        /** metoda ktora vypisuje jeho aktualny stav + pomaha pri debug */
		void printInfo();

        /** metoda na ulahcenie ziskania nazvu predmetu ktory hrac vlastni, a vrati ho */
		string getPredmetNazov(string typ);

        /** metoda ktora ulahcuje ziskanie silu predmetu ktory vlastni hrac */
		int getPredmetSila(string typ);

        /** tato metoda vracia hodnotu utoku hraca */
		int getUtok();

        /** tato metoda vracia hodnotu obrany hraca */
		int getObrana();
		};
	}

#endif // hrac
