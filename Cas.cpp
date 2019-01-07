#include "Cas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



Cas::Cas()
{
	srand(time(NULL));
}

int Cas::generujCas()
{
	
	generovaneCisloZRozsahu = rand() % 1955;
	generovaneCisloZRozsahu = generovaneCisloZRozsahu + 7140;

	return generovaneCisloZRozsahu;
	
}


Cas::~Cas()
{
}
