#include "Ork.h"

Mechanika::Ork::Ork(int uzdravenie, string meno, int utok, int zivot, int obrana):Prisera(meno, utok, zivot, obrana)
	{
	m_uzdravenie = uzdravenie;
	m_typ = "Ork";
	}

void Mechanika::Ork::pouziSchopnost()
	{ m_zivot = m_zivot + m_uzdravenie; }

int Mechanika::Ork::getSchopnost()
	{ return m_uzdravenie; }
