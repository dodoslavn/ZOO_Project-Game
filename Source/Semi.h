#ifndef semi
#define semi

#include "Hrac.h"

namespace Mechanika {
	class Semi : public Mechanika::Hrac {
	public:
	    /** konstruktor tkori urcuje parametre pre konstruktor predka */
		Semi(string meno);
	};
}

#endif // semi
