#ifndef bunka
#define bunka

#include "Brnenie.h"
#include "Mec.h"
#include "Prisera.h"

namespace Mechanika {
	class Bunka {

	private:
		bool m_chodba;
		Mechanika::Brnenie* m_brnenie;
		Mechanika::Mec* m_mec;
		Mechanika::Prisera* m_prisera;

	public:
        /** metoda vracia ukazatel na objekt "Mec" ktori sa nachadza v danej/tejto bunke */
		Mechanika::Mec* getMec();

		/** metoda vracia ukazatel na objekt "Brnenie" ktori sa nachadza v danej/tejto bunke */
		Mechanika::Brnenie* getBrnenie();

		/** metoda vracia ukazatel na objekt "Prisera" ktori sa nachadza v danej/tejto bunke */
		Mechanika::Prisera* getPrisera();

        /** metoda ulozi do tejto bunky dany ukazatel na objekt typu "Mec"*/
		void setMec(Mechanika::Mec* mec);

        /** metoda ulozi do tejto bunky dany ukazatel na objekt typu "Prisera"*/
		void setPrisera(Mechanika::Prisera* prisera);

        /** metoda ulozi do tejto bunky dany ukazatel na objekt typu "Brnenie"*/
		void setBrnenie(Mechanika::Brnenie* brnenie);

        /** metoda vracia hodnotu ci tato bunka predstavuje volnu chodbu alebo nie*/
		bool getChodba();

		/** tato metoda nastavi tento objekt/bunku ci je volna chodba alebo nie */
		void setChodba(bool chodba);

        /** tato metoda automaticky nastavi tento objekt/bunku ze je chodbou*/
		void setChodba();

        /** konstruktor tejto triedy, ulozi podla parametru ci je chodbou alebo nie */
		Bunka(bool chodba);
	};
}


#endif // bunka
