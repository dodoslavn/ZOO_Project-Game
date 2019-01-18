#include "Brnenie.h"

Mechanika::Brnenie::Brnenie(string nazovb, int brnenieb)
	{ 
	cout<<"Vytvaram brnenie: " << nazovb <<endl; 
	m_nazov = nazovb;
	m_brnenie = brnenieb;
	}

string Mechanika::Brnenie::getNazov() 
	{ return m_nazov; }
	
int Mechanika::Brnenie::getBrnenie() 
	{ return m_brnenie; }