#include "Matica.h"

Mechanika::Matica::Matica(int constx, int consty)
	{
	m_constx = constx;
	m_consty = consty;

	vector<Bunka*> pom;
	pom.resize(m_consty);
	m_vmatica.resize(m_constx);

	for( int i = 0; i < m_constx; i++ )
		{ m_vmatica[i] = pom; }

	for(int x = 0; x < m_constx; x++)
		{
		for(int y = 0; y < m_consty; y++ )
			{ m_vmatica[x][y] = new Bunka(false); }
		}

	m_vmatica[0][10]->setChodba();
	m_vmatica[1][10]->setChodba();
	m_vmatica[2][10]->setChodba();
	m_vmatica[3][10]->setChodba();
	m_vmatica[3][10]->setChodba();
	m_vmatica[4][10]->setChodba();
	m_vmatica[5][10]->setChodba();
	m_vmatica[6][10]->setChodba(); //kriz

	m_vmatica[7][10]->setChodba();
	m_vmatica[8][10]->setChodba();
	m_vmatica[9][10]->setChodba(); //druha cesta rovno

	m_vmatica[6][10]->setChodba();
	m_vmatica[6][11]->setChodba();
	m_vmatica[6][12]->setChodba();
	m_vmatica[6][13]->setChodba();
	m_vmatica[6][14]->setChodba();
	m_vmatica[6][15]->setChodba(); //prva cesta dole

	m_vmatica[6][9]->setChodba();
	m_vmatica[6][8]->setChodba();
	m_vmatica[6][7]->setChodba();
	m_vmatica[6][6]->setChodba();
	m_vmatica[6][5]->setChodba(); //boss
	}

int Mechanika::Matica::getConsty()
	{ return m_consty; }

int Mechanika::Matica::getConstx()
	{ return m_constx; }

bool Mechanika::Matica::stavBunky(int x, int y)
	{
	if( x<=m_constx && x >= 0 && y <= m_consty && y >= 0 )
		{ return m_vmatica[x][y]->getChodba(); }
	else { return false; }
	}

void Mechanika::Matica::vlozMec(Mec* mecM, int x, int y)
	{ m_vmatica[x][y]->setMec(mecM); }

Mechanika::Mec* Mechanika::Matica::getMec(int x, int y)
	{ return m_vmatica[x][y]->getMec(); }

void Mechanika::Matica::vlozBrnenie(Brnenie* brnM, int x, int y)
	{ m_vmatica[x][y]->setBrnenie(brnM); }

Mechanika::Brnenie* Mechanika::Matica::getBrnenie(int x, int y)
	{ return m_vmatica[x][y]->getBrnenie(); }

void Mechanika::Matica::vlozPrisera(Prisera* priM, int x, int y)
	{ m_vmatica[x][y]->setPrisera(priM); }

Mechanika::Prisera* Mechanika::Matica::getPrisera(int x, int y)
	{ return m_vmatica[x][y]->getPrisera(); }
