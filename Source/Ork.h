#ifndef ork
#define ork


#include "Prisera.h"


namespace Mechanika {
	class Ork : public Mechanika::Prisera {
    private:
        /** premenna urcujuca silu specialnej vlastnosti */
		int m_uzdravenie;
	public:
        /** konstruktor ktori ulozi hodnotu specialnej vlastnosti tohto potomka, ostatne preposle na konstruktor predka */
		Ork(int uzdravenie, string meno, int utok, int zivot, int obrana);

        /** metoda ktora aplikuje specialnu schopnost tohto potomka - zvysi "zivot" o hodnotu "uzdravenie"  */
		void pouziSchopnost();

        /** tato metoda vracia hodnotu specialnej vlastnosti */
		int getSchopnost();
	};
}

#endif
