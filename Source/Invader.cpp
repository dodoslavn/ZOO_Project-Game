#include "Invader.h"

Mechanika::Invader::Invader(int hnev, string meno, int utok ,int zivot, int obrana ):Prisera(meno,utok,zivot,obrana)
	{
	m_hnev = hnev;
	m_typ = "Invader";
	}

void Mechanika::Invader::pouziSchopnost()
	{ m_utok = m_utok + m_hnev; }

int Mechanika::Invader::getSchopnost()
	{ return m_hnev; }
