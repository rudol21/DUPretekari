#include "Bezec.h"
#include <string>


Bezec::Bezec()
{
	
}


Bezec::~Bezec()
{
}

string Bezec::getUdaje()
{
	char result[5];
	itoa(startovneCislo, result, 10);

	int hodiny = 0;
	int minuty = 0;
	int sekundy = 0;
	int generovaneCisloZRozsahu = 0;
	generovaneCisloZRozsahu = dosiahnutyCas;
	hodiny = generovaneCisloZRozsahu / 3600;
	generovaneCisloZRozsahu = generovaneCisloZRozsahu - (hodiny * 3600);
	minuty = generovaneCisloZRozsahu / 60;
	generovaneCisloZRozsahu = generovaneCisloZRozsahu - (minuty * 60);
	sekundy = generovaneCisloZRozsahu;
	char h[5];
	char m[5];
	char s[5];
	
	itoa(hodiny, h, 10);
	itoa(minuty, m, 10);
	itoa(sekundy, s, 10);
	
	string udaje = "Priezvisko: " + (string)priezvisko + " Meno: " + (string)meno + " Pohlavie: " + pohlavie + " Startovne cislo: " + result + " Cas: " + h + ":" + m +":" + s + "\n";
	return udaje;
	}

void Bezec::vymazUdaje()
{
	delete[] meno;
	delete[] priezvisko;
}

void Bezec::setBezca(char * priezviskoBezca, char * menoBezca, char pohlavieBezca)
{
	priezvisko = priezviskoBezca;
	meno = menoBezca;
	pohlavie = pohlavieBezca;
}

void Bezec::setMeno(char * menoBez)
{
	meno = menoBez;
}

void Bezec::setPriezvisko(char * priezviskoBez)
{
	priezvisko = priezviskoBez;
}

void Bezec::setPohlavie(char pohlavieBez)
{
	pohlavie = pohlavieBez;
}

void Bezec::setStartovneCislo(unsigned int stCislo)
{
	startovneCislo = stCislo;
}

void Bezec::setDosiahnutyCas(unsigned int dosiahnutyCasBezca)
{
	dosiahnutyCas = dosiahnutyCasBezca;
}

void Bezec::vypisBezca()
{	
	printf("Priezvisko: %-12s Meno: %-12s Pohlavie:%c Startovne cislo: %-3u",priezvisko,meno,pohlavie, getStartovneCislo());	
}
