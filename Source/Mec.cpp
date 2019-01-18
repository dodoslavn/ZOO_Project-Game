#include "Mec.h"

Mechanika::Mec::Mec(string nazov, int utok) 
	{
	{ cout<<"Vytvaram mec: " << nazov <<endl; }
	m_nazov = nazov;
	m_utok = utok;
	}

string Mechanika::Mec::getNazov() 
	{ return m_nazov; }
	
int Mechanika::Mec::getUtok() 
	{ return m_utok; }