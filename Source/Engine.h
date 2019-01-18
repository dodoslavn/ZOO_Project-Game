/*!
 *  \brief     Riadiaca metoda.
 *  \details   Tato trieda sluzi na riadenie celej hry.
 *  \author    Dominik Fortuna
 *  \date      2013-2014
 *  \bug       Pohyb na matici nieje uplne vyladeny.
 */

#ifndef engine
#define engine

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "windows.h"

#include <string>

#include "Matica.h"
#include "Bunka.h"

#include "Hrac.h"
#include "Semi.h"
#include "Carry.h"
#include "Tanker.h"

#include "Mec.h"
#include "Brnenie.h"

#include "Prisera.h"
#include "Ork.h"
#include "Invader.h"


namespace Mechanika {
	class Engine {

	private:
	    /** premenna ktora obsahuje ukazatel na jedinu maticu */
		Matica* m_matica;

		/** premenna ktora obsahuje ukazatel na jedineho hraca */
		Mechanika::Hrac* m_hrac;

		/** premenna ktora urcuje kedy hra skonci */
		bool running;

		/** premenna vektor ktora obsahuje vsetky ascii arty, pristupuje sa na nu cez metodu "nakresli" */
		vector <string> m_art;
	public:
	    /** premenna ktora obsahuje ukazatele na vsetky objekty triedy "Mec" */
		vector <Mec*> m_mec;

		/** premenna ktora obsahuje ukazatele na vsetky objekty triedy "Brnenie" */
		vector <Brnenie*> m_brn;

		/** premenna ktora obsahuje ukazatele na vsetky objekty triedy "Prisera" */
		vector <Prisera*> m_pri;

		/** premenna ktora obsahuje hodnotu ktora ponuka sa sa ma uzivatelovi zobrazit v GUI */
		vector<bool> moznosti;

        /** konstruktor ktori vytvori vsetky potrebne objekty a spusti celi beh metodou "spusti" */
		Engine();

        /** metoda ktora spusti celi chod hry */
		void spusti();

        /** metoda ktora vytvori a pripravy maticu(herne pole) pre pracu s nou */
		void nacitajMaticu();

        /** metoda ktora vytvori hraca s GUI */
		void nacitajHraca();

        /** metoda ktora vytvori vsetky potrebne objekty roznych tried */
		void nacitajObjekty();

        /** metoda ktora ulozi do premennej vsetky ascii arty a pripavy ich k pouzivaniu */
		void nacitajArt();

        /** metoda ktora podla parametru vlozi ukazatel predmetu na ktoreho sa nachadza hracovi */
		void vezmiPredmet(string typ);

        /** metoda ktora sa stara o celu interakciu s uzivatelom vypisovanim ponuky a spracovavanim vsetupov */
		void ponuka();

        /** metoda ktora riadi ukoncenie celej hry a sposob ukoncenia */
		void koniec(string ako);

        /** metoda ktora ulahcuje vypisanie predmetu ktory sa nachadza na danej suradnici, podla zadaneho typu */
		void vypisNazovPredmetu(string typ, int x, int y);

        /** metoda ulahcuje ziskanie nazvu, a vrati nazov daneho objektu triedy "Mec" */
		string getNazovMec(Mec* mecc);

        /** metoda ktora ulahcuje ziskanie nazvu, a vrati nazov daneho objektu "Brnenie" */
		string getNazovBrnenie(Brnenie* brn);

        /** metoda zisti stav chodby, a uzivatelovi podla toho vytvori ponuku moznosti */
		void stavChodby();

        /** tato metoda riadi celi suboj hraca s priserou */
		void suboj();

        /** metoda pracuej s vektorom v ktorom su ulozene vsetky ascii arty, pomaha a zjednodusuje vykreslovanie animacii */
		void nakresli(int co);
	};
}

#endif // engine
