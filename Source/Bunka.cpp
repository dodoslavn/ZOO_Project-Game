#include "Bunka.h"

Mechanika::Prisera* Mechanika::Bunka::getPrisera()
	{ return m_prisera; }

void Mechanika::Bunka::setPrisera(Mechanika::Prisera* priB)
	{ m_prisera = priB; }

Mechanika::Mec* Mechanika::Bunka::getMec()
	{ return m_mec; }

void Mechanika::Bunka::setMec(Mechanika::Mec* mecB)
	{ m_mec = mecB; }

Mechanika::Brnenie* Mechanika::Bunka::getBrnenie()
	{ return m_brnenie; }

void Mechanika::Bunka::setBrnenie(Mechanika::Brnenie* brnenieB)
	{ m_brnenie = brnenieB; }

bool Mechanika::Bunka::getChodba()
	{ return m_chodba; }

void Mechanika::Bunka::setChodba(bool chodba)
	{ m_chodba = chodba; }

void Mechanika::Bunka::setChodba()
	{ m_chodba = true; }

Mechanika::Bunka::Bunka(bool chodba)
	{
    m_chodba = chodba;
	m_prisera = NULL;
	m_brnenie = NULL;
	m_mec = NULL;
	}
