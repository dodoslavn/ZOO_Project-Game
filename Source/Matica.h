#ifndef matica
#define matica

#include <vector>
#include "Bunka.h"
#include "Prisera.h"
#include "Mec.h"

using namespace std;

namespace Mechanika {
	class Matica {

	private:
	    /** vektor vektorov - matica ktora obsahuje zakazdym ukazatel na iny objekt triedy Bunka */
		vector<vector<Bunka*> > m_vmatica;

		/** velkost matice ktora sa ma vytvoritna ose X */
		int m_constx;

		/** velkost matice ktora sa ma vytvorit na ose Y */
		int m_consty;

	public:
	    /** konstruktor ktora nastavi aka velka matica(m_vmatica) sa ma vytvorit a vytvori ju */
		Matica(int m_constx, int m_consty);

        /** tato metoda vracia velkost matice po ose Y */
		int getConsty();

        /** tato metoda vracia velkost matice po ose X */
		int getConstx();

        /** tato metoda vracia stav volnej chodby Bunky na danej suradnici X:Y na matici */
		bool stavBunky(int x, int y);

        /** tato emtoda vlozi zadany ukazatel objektu "Mec" do Bunky na danej suradnice */
		void vlozMec(Mec* mecM, int x, int y);

        /** tato emtoda vlozi zadany ukazatel objektu "Brnenie" do Bunky na danej suradnice */
		void vlozBrnenie(Brnenie* brnM, int x, int y);

        /** tato emtoda vlozi zadany ukazatel objektu "Prisera" do Bunky na danej suradnice */
		void vlozPrisera(Prisera* priM, int x, int y);

        /** tato emtoda vrati ukazatel objektu "Mec" z Bunky na danej suradnici v matici */
		Mec* getMec(int x, int y);

        /** tato emtoda vrati ukazatel objektu "Brnenie" z Bunky na danej suradnici v matici */
		Brnenie* getBrnenie(int x, int y);

        /** tato emtoda vrati ukazatel objektu "Prisera" z Bunky na danej suradnici v matici */
		Prisera* getPrisera(int x, int y);

	};
}

#endif // matica
