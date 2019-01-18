#include <iostream>


#include "Engine.h"

using namespace std;

int main()
{
    cout << "Spustam.." << endl;
	Mechanika::Engine* enjin = new Mechanika::Engine;
	enjin->spusti();
	delete(enjin);
    cout << "Koncim.." << endl;
    return 0;
}
