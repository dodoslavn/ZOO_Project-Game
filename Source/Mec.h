#ifndef mec
#define mec

#include <iostream>

using namespace std;

namespace Mechanika {
	class Mec {

	private:
	    /** tato hodnota urcujue silu daneho meca */
		int m_utok;

		/** tato hodnota vlastni nazov meca */
		string m_nazov;

	public:
	    /** konstruktor ktori vlastni nazov a silu vytvoreneho meca */
		Mec(string nazov, int utok);

		/** metoda ktora vrati nazov daneho meca */
		string getNazov();

		/** metoda ktora vrati silu daneho meca */
		int getUtok();
	};
}

#endif // mec
