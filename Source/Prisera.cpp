#include "Prisera.h"

Mechanika::Prisera::Prisera(string meno, int utok, int zivot, int obrana) 
	{
	cout << "Vytvaram priseru: "<<meno <<endl;
	m_meno = meno;
	m_utok = utok; bu_utok = utok;
	m_zivot = zivot; bu_zivot = zivot;
	m_obrana = obrana;
	}

int Mechanika::Prisera::getObrana() 
	{ return m_obrana; }

int Mechanika::Prisera::getUtok() 
	{ return m_utok; }

int Mechanika::Prisera::getZivot() 
	{ return m_zivot; }

void Mechanika::Prisera::setZivot(int zivot) 
	{ m_zivot = zivot; }

string Mechanika::Prisera::getMeno() 
	{ return m_meno; }
	
void Mechanika::Prisera::reset()
	{ 
	m_zivot = bu_zivot;
	m_utok = bu_utok;
	}
	
string Mechanika::Prisera::getTyp() 
	{ return m_typ; }
	
