#include "Hrac.h"

string Mechanika::Hrac::getMeno()
	{ return m_meno; }

void Mechanika::Hrac::setZbroj(Brnenie* zbroj)
	{ m_zbroj = zbroj; }

void Mechanika::Hrac::setZbran(Mec* zbran)
	{ m_zbran = zbran; }

void Mechanika::Hrac::Zabil()
	{ m_utok++; }

string Mechanika::Hrac::getPredmetNazov(string typ)
	{
	if(typ == "mec")
		{
		if(m_zbran == NULL) { return "# Hrac nema ziadny mec"; }
		else { return m_zbran->getNazov(); }
		}
	if(typ == "brnenie")
		{
		if(m_zbroj == NULL) { return "# Hrac nema ziadne brnenie"; }
		else { return m_zbroj->getNazov(); }
		}
	}

int Mechanika::Hrac::getPredmetSila(string typ)
	{
	if(typ == "mec")
		{
		if(m_zbran == NULL) { return 0; }
		else { return m_zbran->getUtok(); }
		}
	if(typ == "brnenie")
		{
		if(m_zbroj == NULL) { return 0; }
		else { return m_zbroj->getBrnenie(); }
		}
	}

Mechanika::Hrac::Hrac(string meno, int utok, int obrana)
	{
	m_zivot = 100;
	m_meno = meno;
	m_utok = utok;
	m_obrana = obrana;
	this->setPozicia(0,10);
	m_zbran = NULL;
	m_zbroj = NULL;
	}

void Mechanika::Hrac::setPozicia(int x, int y)
	{
    m_xl = m_x;
    m_yl = m_y;
	m_x = x;
	m_y = y;
	}

int Mechanika::Hrac::getX()
	{ return m_x; }

int Mechanika::Hrac::getY()
	{ return m_y; }

void Mechanika::Hrac::Utec()
	{
	m_x = m_xl;
	m_y = m_yl;
	}

void Mechanika::Hrac::printInfo()
	{
    string nieco = "\t\t";
    string hh,gg,ff; hh = gg = "--";
    int h,g; h = g = 0;

    if (m_utok == 0) { ff = "Tanker"; }
    else if (m_obrana == 0) { ff = "Carry"; }
    else { ff = "Semi"; }

    if (m_zbran != NULL) {h = m_zbran->getUtok(); hh = m_zbran->getNazov(); }
    if (m_zbroj != NULL) {g = m_zbroj->getBrnenie(); gg = m_zbroj->getNazov(); }
    cout << "\n\n";
    cout << nieco << "Meno: " << m_meno << nieco << "Typ: " << ff << endl;
    cout << nieco << "Utok: " << h + m_utok << " " << nieco << "Zbran: " << hh << endl;
    cout << nieco << "Obrana: " << g + m_obrana << nieco << "Brnenie: " << gg << endl;
	}

int Mechanika::Hrac::getUtok()
	{
	return getPredmetSila("mec") + m_utok;
	}

int Mechanika::Hrac::getObrana()
	{
	return getPredmetSila("brnenie") + m_obrana;
	}
