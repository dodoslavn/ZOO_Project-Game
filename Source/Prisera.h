#ifndef prisera
#define prisera

#include <iostream>

using namespace std;

namespace Mechanika {
	class Prisera {

	protected:
	    /** premenna ktora obsahuje meno prisery */
		string m_meno;

		/** premenne obsahujuce hodnotu zivota */
		int m_zivot, bu_zivot;

		/** premenna ktora obsahuje silu utoku */
		int m_utok, bu_utok;

		/** premenna obsahuje hodnoty obrany */
		int m_obrana;

		/** premmena ktora pre ulahcenie obsahuje o aky typ prisery ide */
		string m_typ;

	public:

	    /** konstruktor predka */
		Prisera(string meno, int utok, int zivot, int obrana);

        /** metoda ktora vracia hodnotu obrany */
		int getObrana();

        /** metoda ktora vraciua hodnotu utoku */
		int getUtok();

        /** metoda ktora vracia hodnotu velkosti zivota*/
		int getZivot();

        /** metoda ktora nastavi velkost zivota */
		void setZivot(int m_zivot);

        /** tato emtoda vracia meno prisery */
		string getMeno();

		virtual void pouziSchopnost() = 0;

		virtual int getSchopnost()=0;

        /** metoda ktora vyresetuje danu priseru, zavola sa vzdy po okoncieni suboja prisery a hraca */
		void reset();

        /** vrati o aky typ prisery ide */
		string getTyp();
	};
}

#endif // prisera
