#include "Engine.h"

Mechanika::Engine::Engine()
	{
	nacitajObjekty();
	nacitajMaticu();
	nacitajArt();
	}

void Mechanika::Engine::spusti()
	{
	nacitajHraca();
	m_hrac->printInfo();

	while(running) {ponuka();}
	}

void Mechanika::Engine::nacitajMaticu()
	{ m_matica = new Matica(20,20); }

void Mechanika::Engine::nacitajHraca()
	{
	moznosti.resize(256);
	for(int i=0;i<256; i++)
		{moznosti[i] = false;}
	running = true;
	int volba = 0;
	string meno;
    char v;

	nakresli(0);
    nakresli(1);
	cout << "Zadajte svoje meno: " ;
	cin >> meno;
    nakresli(0);

    nakresli(3);
	cout << endl << "\n                       Zvolte typ vasej postavy: ";
	while(volba != 97 &&  volba != 115 && volba != 100)
		{ cin >> v; volba = (int) v; }
	switch(volba)
		{
		case 97: m_hrac = new Carry(meno);
			break;
		case 100: m_hrac = new Tanker(meno);
			break;
		case 115: m_hrac = new Semi(meno);
			break;
		}

    m_hrac->setZbroj(m_brn[0]);
    m_hrac->setZbran(m_mec[0]);

	volba = 0;
	nakresli(0);
	nakresli(2);
	cout << "\n\n\n                       Vyber si co si chces vziat: " ;
	while(volba != 97 && volba != 100)
		{ cin >> v; volba = (int) v; }
	switch(volba)
		{
		case 97: m_hrac->setZbroj(m_brn[1]);
			break;
		case 100: m_hrac->setZbran(m_mec[1]);
			break;
		}

    m_matica->vlozMec(m_mec[2],4,10);
	m_matica->vlozBrnenie(m_brn[2],6,10);
	m_matica->vlozMec(m_mec[3],9,10);
	m_matica->vlozBrnenie(m_brn[3],6,15);

	m_matica->vlozPrisera(m_pri[1],2,10); //cesta
	m_matica->vlozPrisera(m_pri[11],3,10);
	m_matica->vlozPrisera(m_pri[2],5,10);

    m_matica->vlozPrisera(m_pri[11],6,11); //prva cesta dole
    m_matica->vlozPrisera(m_pri[12],6,13);
    m_matica->vlozPrisera(m_pri[2],6,15);

    m_matica->vlozPrisera(m_pri[2],7,10); //druha cesta rovno
    m_matica->vlozPrisera(m_pri[3],8,10);
    m_matica->vlozPrisera(m_pri[13],9,10);

    m_matica->vlozPrisera(m_pri[11],6,8); //cesta bossovi
    m_matica->vlozPrisera(m_pri[13],6,7);
    m_matica->vlozPrisera(m_pri[0],6,5);

	}

void Mechanika::Engine::nacitajObjekty()
	{
	m_mec.resize(20);
	m_brn.resize(20);
	m_pri.resize(20);
	for(int i = 0; i < 20; i++)
		{
		m_brn[i]=NULL;
		m_mec[i]=NULL;
		m_pri[i]=NULL;
		}

	m_pri[1] = new Ork(5, "Maly Ork", 30, 50, 10); //  uzdravenie - meno -utok - zivot - obrana
	m_pri[2] = new Ork(10, "Stredny Ork", 35, 100, 15);
	m_pri[3] = new Ork(10, "Velky Ork", 40, 150, 20);

	m_pri[11] = new Invader(5, "Maly Invader", 30, 50, 10);  // hnev - meno - utok - zivot - obrana
	m_pri[12] = new Invader(10, "Stredny Invader", 35, 100, 15);
	m_pri[13] = new Invader(10, "Velky Invader", 40, 150, 20);

	m_pri[0] = new Invader(7, "Boss", 40, 300, 30);

	m_brn[1] = new Brnenie("Cloak     ", 20);
	m_brn[2] = new Brnenie("Chain Mail", 30);
	m_brn[3] = new Brnenie("Plate Mail", 50);

	m_mec[1] = new Mec("Broadsword   ", 20);
	m_mec[2] = new Mec("Claymore    ", 40) ;
	m_mec[3] = new Mec("Divine Rapier", 100);

	m_mec[0] = new Mec("Palica       ", 15);
	m_brn[0] = new Brnenie("Plast          ", 10);

	}


void Mechanika::Engine::vezmiPredmet(string typ)
	{
	int x = m_hrac->getX();
	int y = m_hrac->getY();

	if(typ == "mec")
		{
		m_hrac->setZbran(m_matica->getMec(x,y));
		m_matica->vlozMec(NULL,x,y);
		}
	if(typ == "brnenie")
		{
		m_hrac->setZbroj(m_matica->getBrnenie(x,y));
		m_matica->vlozBrnenie(NULL,x,y);
		}
	}


void Mechanika::Engine::ponuka()
	{
	for(int i=0;i<256; i++)
		{ moznosti[i] = false; }
	char volba;

	nakresli(0);
	m_hrac->printInfo();
	int x = m_hrac->getX();
	int y = m_hrac->getY();

	stavChodby();

	cin >> volba;int v = (int) volba;
	if(moznosti[v])
		{
		switch(v)
			{
			case 100: m_hrac->setPozicia(x+1,y); nakresli(91);
				break;
			case 97: m_hrac->setPozicia(x-1,y); nakresli(91);
				break;
			case 119: m_hrac->setPozicia(x,y-1); nakresli(91);
				break;
			case 115: m_hrac->setPozicia(x,y+1); nakresli(91);
				break;
			case 120: vezmiPredmet("mec");
				break;
			case 118: m_hrac->Utec();
				break;
			case 99: vezmiPredmet("brnenie");
				break;
			case 122: suboj();
				break;
            case 102: nakresli(6);
				break;
			case 113: koniec("zrusilto");
				break;
			}
		}
	if(!m_matica->stavBunky(x,y)) { cout << "# " << m_hrac->getMeno()  << " je mimo mapu" << endl; throw; }
	}

void Mechanika::Engine::vypisNazovPredmetu(string typ, int x, int y)
	{
	if(typ == "mec")
		{
		Mec* mecik;
		mecik = m_matica->getMec(x,y);
		if (mecik != NULL) { cout << mecik->getNazov()<<endl;}
		else { cout << "# Na pozicii "<<x<<":"<<y<<" sa nenachadza ziadny mec" << endl; throw;}
		}
	if(typ == "brnenie")
		{
		Brnenie* brn;
		brn = m_matica->getBrnenie(x,y);
		if (brn != NULL) { cout << brn->getNazov()<<endl;}
		else { cout << "# Na pozicii "<<x<<":"<<y<<" sa nenachadza ziadne brnenie" << endl; throw;}
		}
	}

string Mechanika::Engine::getNazovMec(Mec* mecc)
	{
    if (mecc != NULL)
        { return mecc->getNazov();}
    else
        { return NULL; }
    }

string Mechanika::Engine::getNazovBrnenie(Brnenie* brn)
	{
    if (brn != NULL)
        { return brn->getNazov();}
    else
        { return NULL; }
    }

void Mechanika::Engine::stavChodby()
	{
	Mec* mecik;
	Brnenie* brn;

	int x = m_hrac->getX();
	int y = m_hrac->getY();

    cout << "\n\n\n\n";

	if(m_matica->getPrisera(x,y) == NULL)
		{
		if ( m_matica->stavBunky(x+1,y) ) {cout << "\t[D] Dopredu" << endl; moznosti[100] = true;}
		if ( m_matica->stavBunky(x-1,y) ) {cout << "\t[A] Doazdu" << endl; moznosti[97] = true;}
		if ( m_matica->stavBunky(x,y-1) ) {cout << "\t[W] Hore" << endl; moznosti[119] = true;}
		if ( m_matica->stavBunky(x,y+1) ) {cout << "\t[S] Dole" << endl; moznosti[115] = true;}

		mecik = m_matica->getMec(x,y);
		if(mecik != NULL)
			{
			cout << "\t[X] Vezmi mec - " << getNazovMec(mecik) << endl;
			moznosti[120] = true;
			}
		brn = m_matica->getBrnenie(x,y);
		if(brn != NULL)
			{
			cout << "\t[C] Vezmi brnenie - " << getNazovBrnenie(brn) << endl;
			moznosti[99] = true;
			}
		}
	else
        {
        cout << "\t[V] Utiect" << endl; moznosti[118] = true;
        cout << "\t[Z] Suboj - " << m_matica->getPrisera(x,y)->getMeno() << endl; moznosti[122] = true;
        }
    cout << "\t[Q] Vypnut" << endl; moznosti[113] = true;
    if(x == 6 && y == 5)
        { koniec("vyhral"); }
    }


void Mechanika::Engine::koniec(string ako)
	{
	running = false;
	nakresli(0);
	nakresli(1);
	if( ako == "umrel v boji" )
        { cout << "PREHRAL SI V BOJI !" << endl; }
	if( ako == "zrusilto" )
        { cout << "HRA UKONCENA !" << endl; }
	if( ako == "vyhral" )
        { cout << "VYHRAL SI !" << endl; }

    cout << "\n\t\t\t    KONIEC\n\n\n\n\n\n\n";
	/*for(int i = 0; i < 20; i++)
		{
		if( m_brn[i] != NULL ) { delete(m_brn[i]); }
		if( m_mec[i] != NULL ) { delete(m_mec[i]); }
		if( m_pri[i] != NULL ) { delete(m_pri[i]); }
		}*/
	}

void Mechanika::Engine::suboj()
	{
	int x = m_hrac->getX();
	int y = m_hrac->getY();

	Prisera* pri = m_matica->getPrisera(x,y);

	string hrMeno = m_hrac->getMeno();
	string prMeno = pri->getMeno();

	int hrZivot = 100;


	bool udri,neumrel = true;
	int volba, c = 0;
	char v;
	while(neumrel)
		{
        c++;
        nakresli(0);
        udri = false;
        volba = 0;

		cout << "\n\t  Hrac: "<< hrMeno << "\t\t\t\t" << "Prisera: "<< prMeno  << endl;
		cout << "\t  ==================" << "\t\t\t" << "==================" << endl;
		cout << "\t  Zdravie: " << hrZivot << "\t\t\t\tZdravie " << pri->getZivot() << endl;
		cout << "\t  Utok: " << m_hrac->getUtok() << " - " <<  m_hrac->getPredmetNazov("mec") << "\t\tUtok: " << pri->getUtok() << endl;
		cout << "\t  Obrana: " << m_hrac->getObrana() << " - " <<  m_hrac->getPredmetNazov("brnenie") << "\t\tObrana: " << pri->getObrana() <<  endl << endl;

        cout << "\n\n\n";
        cout << "\t[V] Utec\n\t[Z] Zautoc\n\t[Q] Vypnut" << endl;
        moznosti[113] = true;

        while(volba != 118 && volba != 122 && volba != 113)
            { cin >> v; volba = (int) v; }
        switch(volba)
            {
            case 118: m_hrac->Utec(); neumrel = false;
                break;
            case 122: udri = true;
                break;
			case 113: koniec("zrusilto"); neumrel = false;
				break;
            }

        if(udri)
            {
            nakresli(0);
            cout << "Zautocil si na priseru " << endl;
            cout << "Prisere " << prMeno << " odobrane: " << double( m_hrac->getUtok() ) / 100 * (100 - pri->getObrana() ) << endl;
            pri->setZivot( pri->getZivot() - double(m_hrac->getUtok()) / 100 * (100 - pri->getObrana() ) );

            cout << "Zautocila na teba prisera " << endl;
            cout << "Prisera " << prMeno << " ti zobrala: " << double( pri->getUtok() ) / 100 * (100 - m_hrac->getObrana() ) << endl;
            hrZivot = hrZivot - double(pri->getUtok() ) / 100 * (100 - m_hrac->getObrana());

            for(int i = 0; i <= 4; i++)
                {
                nakresli(0);
                cout << endl << endl << endl << endl << endl << endl;
                nakresli(8);
                cout << "\n\t Utok o sile: " << m_hrac->getUtok() << "        \tZranil o: " << double(m_hrac->getUtok() ) / 100 * (100 - pri->getObrana() )  ;
                Sleep(400);

                nakresli(0);
                cout << endl << endl << endl;
                nakresli(6);
                cout << "\n\t Utok o sile: " << m_hrac->getUtok() << "        \tZranil o: " << double(m_hrac->getUtok() ) / 100 * (100 - pri->getObrana() )  ;
                Sleep(400);
                }
            Sleep(1000);
            for(int i = 0; i <= 4; i++)
                {
                nakresli(0);
                cout << endl << endl << endl;
                nakresli(7);
                cout << "\n\t Zranil o: " << double(pri->getUtok() ) / 100 * (100 - m_hrac->getObrana()) << "    \t\tUtok o sile: " << pri->getUtok() ;
                Sleep(400);

                nakresli(0);
                cout << endl << endl << endl;
                nakresli(6);
                cout << "\n\t Zranil o: " << double(pri->getUtok() ) / 100 * (100 - m_hrac->getObrana()) << "    \t\tUtok o sile: " << pri->getUtok() ;
                Sleep(400);
                }
            Sleep(1000);

            if( hrZivot <= 0 || pri->getZivot() <= 0 )
                {neumrel = false;}
            else ( pri->pouziSchopnost() );
            }
        }
	if( hrZivot <= 0 )
		{ koniec("umrel v boji");}
    else if ( pri->getZivot() <= 0 )
        {
        m_hrac->Zabil();
        m_matica->vlozPrisera(NULL,x,y);
        nakresli(0);
        nakresli(1);
        cout << "VYHRAL SI SUBOJ !" << endl; Sleep(2000);
        }
    pri->reset();
	}


void Mechanika::Engine::nakresli(int co)
    {
    string x;
    switch(co)
        {
        case 0: system("CLS"); break;                                           // linux= "clear" win="CLS"
        case 1: cout << "\n\n\n\n\n\n\n\n\n\n                        "; break;  //zacni na strede
        case 2: cout << m_art[1]; break;                                        // mec + stit
        case 3: cout << m_art[2]; break;                                        // vyber typ hraca
        case 4: cout << m_art[3]; break;                                        //panacik
        case 5: cout << "\n\n\n\n\n\n\n\n\n\n                        "; break;
        case 6: cout << m_art[5]; break;
        case 7: cout << m_art[6]; break;
        case 8: cout << m_art[16]; break;
        case 91: nakresli(0);
                 cout << "\n\n\n\n\n\n"; for(int i = 0; i<40; i++){cout << " -";} cout << endl << m_art[15] << endl; for(int i = 0; i<40; i++){cout << " -";} Sleep(500); nakresli(0);
                 cout << "\n\n\n\n\n\n"; for(int i = 0; i<40; i++){cout << " -";} cout << endl << m_art[16] << endl; for(int i = 0; i<40; i++){cout << " -";} Sleep(500); nakresli(0);
                 cout << "\n\n\n\n\n\n"; for(int i = 0; i<40; i++){cout << " -";} cout << endl << m_art[17] << endl; for(int i = 0; i<40; i++){cout << " -";} Sleep(500); nakresli(0);
                 cout << "\n\n\n\n\n\n"; for(int i = 0; i<40; i++){cout << " -";} cout << endl << m_art[18] << endl; for(int i = 0; i<40; i++){cout << " -";} Sleep(500); nakresli(0);
                 cout << "\n\n\n\n\n\n"; for(int i = 0; i<40; i++){cout << " -";} cout << endl << m_art[19] << endl; for(int i = 0; i<40; i++){cout << " -";} Sleep(500); nakresli(0);
                 break;
        }
    }

void Mechanika::Engine::nacitajArt()
    {
    m_art.resize(20);
    for (int i = 0; i<20; i++)
        { m_art[i] = ""; }
    vector <string> medz(20,"");
    medz[1] = "        ";
    medz[2] = "                           ";
    medz[3] = "                                          ";
    medz[4] = "                                                         ";

    m_art[1] = "\n\n\n\n\n               |`-B._/\\_.-`|\n               |    ||    |\n               |___o()o___|             /| ________________\n               |__((<>))__|       O|===|* >________________>\n               \\   o\\/o   /             \\|\n                \\   ||   /\n                 \\  ||  /\n                  '.||.'\n                    ``\n                  [A] Stit                 [D] Mec          \n";
    m_art[2] = "\n\n\n\n\n                     [A]              [S]              [D]\n\n                |==========|     |==========|     |==========| \n                |   Carry  |     |   Semi   |     |  Tanker  | \n                |==========|     |==========|     |==========| \n                | utok +20 |     | utok +10 |     | utok   0 | \n                | obrana 0 |     |obrana +10|     |obrana +20| \n                |==========|     |==========|     |==========| \n";
    m_art[3] = "          ,^.\n          |||\n          |||       _T_\n          |||   .-.[:|:].-.\n          ===_ /\\|  ```  |/\n           E]_|\\/ \\--|-|````|                  ,    ,    /\\   /\\\n           O  ``  `=[:]|    |                 |\\_||_/| < \\_   _/ >  \n                  /````|    |                 \\______/  \\|0   0|/\n                 /``````.__.`                    _\\/_   _(_  ^  _)_\n                []`/```\\`[]                    ( () ) /`\\|V```V|/`\\\n                | \\     / |                      {}   \\  \\_____/  /\n                | |     | |                      ()   /\\   )=(   /\\   \n              <\\\\\\)     (///>                    {}  /  \\_/\\=/\\_/  \\   \n   ";

    m_art[5] = "\t\t                            ,-----.\n\t\t                           ( <> <> )\n\t\t                            )_ W _(  \n\t(,);    /\\                           |||||    A A A\n\t(( ^_   ||                            |||     | | | \n\t  /  \\  ||                         __/)'(\\__  `-+-' \n\t  L {=) ||                        /\\\\     //\\   |   \n\t   ) -  ||                       | |\\\\___//\\ \\  |   \n\t (_   \\====                      | |/\\\\_//\\ \\ \\ |   \n\t | (___/{ }                      | ||\\\\_//|  \\ \\|   \n\t  \\____\\/)                       | ||/\\_/\\|   \\ |   \n\t  |    |                         | |/ /|\\ \\    \\_)  \n\t   |  |                          (_/  \\_/  \\    |   \n\t    ) )\\                           |  | |  |    |   \n\t  _/| |/                           |()| |()|    |   \n\t ( ,\\ |_                           |  | |  |    |   \n\t  \\_(___)                          \\__/ \\__/    V   \n";
    m_art[6] = "\t\t                            ,-----.\n\t\t                           ( <> <> )\n\t\t                            )_ W _(  \n\t\t                             |||||    A A A  \n\t\t                              |||     | | | \n\t\t                           __/)'(\\__  `-+-' \n\t\t                          /\\\\     //\\   |   \n\t\t                         | |\\\\___//\\ \\  |   \n\t\t                         | |/\\\\_//\\ \\ \\ |   \n\t\t                         | ||\\\\_//|  \\ \\|   \n\t\t                         | ||/\\_/\\|   \\ |   \n\t\t                         | |/ /|\\ \\    \\_)  \n\t\t                         (_/  \\_/  \\    |   \n\t\t                           |  | |  |    |   \n\t\t                           |()| |()|    |   \n\t\t                           |  | |  |    |   \n\t\t                           \\__/ \\__/    V   \n";
    m_art[7] = "";

    m_art[15] = "(,);    /\\ \n(( ^_   || \n  /  \\  || \n  L {=) ||  \n   ) -  ||  \n (_   \\==== \n | (___/{ }  \n  \\____\\/) \n  |    |   \n   |  |    \n    ) )\\  \n  _/| |/   \n ( ,\\ |_  \n  \\_(___) \n  ";
    m_art[16] =   medz[1]+"(,);    /\\ \n"+medz[1]+"(( ^_   || \n"+medz[1]+"  /  \\  || \n"+medz[1]+"  L {=) ||  \n"+medz[1]+"   ) -  ||  \n"+medz[1]+" (_   \\==== \n"+medz[1]+" | (___/{ }  \n"+medz[1]+"  \\____\\/) \n"+medz[1]+"  |    |   \n"+medz[1]+"   |  |    \n"+medz[1]+"    ) )\\  \n"+medz[1]+"  _/| |/   \n"+medz[1]+" ( ,\\ |_  \n"+medz[1]+"  \\_(___) \n  ";
    m_art[17] =   medz[2]+"(,);    /\\ \n"+medz[2]+"(( ^_   || \n"+medz[2]+"  /  \\  || \n"+medz[2]+"  L {=) ||  \n"+medz[2]+"   ) -  ||  \n"+medz[2]+" (_   \\==== \n"+medz[2]+" | (___/{ }  \n"+medz[2]+"  \\____\\/) \n"+medz[2]+"  |    |   \n"+medz[2]+"   |  |    \n"+medz[2]+"    ) )\\  \n"+medz[2]+"  _/| |/   \n"+medz[2]+" ( ,\\ |_  \n"+medz[2]+"  \\_(___) \n  ";
    m_art[18] =   medz[3]+"(,);    /\\ \n"+medz[3]+"(( ^_   || \n"+medz[3]+"  /  \\  || \n"+medz[3]+"  L {=) ||  \n"+medz[3]+"   ) -  ||  \n"+medz[3]+" (_   \\==== \n"+medz[3]+" | (___/{ }  \n"+medz[3]+"  \\____\\/) \n"+medz[3]+"  |    |   \n"+medz[3]+"   |  |    \n"+medz[3]+"    ) )\\  \n"+medz[3]+"  _/| |/   \n"+medz[3]+" ( ,\\ |_  \n"+medz[3]+"  \\_(___) \n  ";
    m_art[19] =   medz[4]+"(,);    /\\ \n"+medz[4]+"(( ^_   || \n"+medz[4]+"  /  \\  || \n"+medz[4]+"  L {=) ||  \n"+medz[4]+"   ) -  ||  \n"+medz[4]+" (_   \\==== \n"+medz[4]+" | (___/{ }  \n"+medz[4]+"  \\____\\/) \n"+medz[4]+"  |    |   \n"+medz[4]+"   |  |    \n"+medz[4]+"    ) )\\  \n"+medz[4]+"  _/| |/   \n"+medz[4]+" ( ,\\ |_  \n"+medz[4]+"  \\_(___) \n  ";
    }





