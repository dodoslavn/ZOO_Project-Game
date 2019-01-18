#ifndef brnenie
#define brnenie



#include <iostream>
using namespace std;

namespace Mechanika
	{
	class Brnenie
		{
		private:
		    /** premenna obsahuje konstantnu hodnotu daneho objektu - brnenia */
			int m_brnenie;

			/** premenna obsahuje nazov daneho objektu - brnenia */
			string m_nazov;
		public:
		    /** jednoduchy konstruktor ktori ulozi hodnoty do premennych */
			Brnenie(string nazov, int brnenie);

			/** metoda vrati nazov daneho objektu - brnenia */
			string getNazov();

			/** metoda vracia hodnotu brnenia */
			int getBrnenie();
		};
	}


#endif // brnenie
