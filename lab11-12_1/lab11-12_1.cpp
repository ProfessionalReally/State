#include "Header.h"

int main()
{
	StateContex* sc = new StateContex(new OffState());

	sc->Off();

	cout << "--------------------------\n";

	sc->On();

	cout << "--------------------------\n";

	sc->On();

	delete sc;
}


