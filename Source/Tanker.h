#ifndef tanker
#define tanker

#include "Hrac.h"

namespace Mechanika {
	class Tanker : public Mechanika::Hrac {
	public:
	    /** konstruktor urcujuci hodnoty pre konstruktor predka */
		Tanker(string meno);
	};
}

#endif
