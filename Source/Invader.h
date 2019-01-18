#ifndef invader
#define invader

#include "Prisera.h"

namespace Mechanika {
	class Invader : public Mechanika::Prisera {

	private:
	    /** hodnota specialnej vlastnosti tohto potomka */
		int m_hnev;
	public:
	    /** konstruktor ktori ulozi do tohto potomka premenuu hodnoty "hnev", a ostatne posunie predkovi */
		Invader(int hnev, string meno, int utok, int zivot, int obrana );

        /** tato metoda pouzije specialnu schopnost tohto potomka - zvysi "utok" o hodnotu "hnev" */
		void pouziSchopnost();

        /** metoda ktora vracia hodnotu specialnej vlastnosti */
		int getSchopnost();
	};
}

#endif // invader
