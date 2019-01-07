#include "Preteky.h"
#include "CitajSubor.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 

Preteky::Preteky()
{}

Bezec Preteky::getBezca(int index)
{
	return poleBezcov[index];
}

void Preteky::nastavBezca(int index, char * priezviskoBezca, char * menoBezca, char pohlavieBezca)
{
	poleBezcov[index].setBezca((char*)priezviskoBezca, (char*)menoBezca, pohlavieBezca);
}

void Preteky::pridajBezca(Bezec *novyBezec)
{
	if (startovneCisloBezca == 0) {
		startovneCisloBezca++;
		poleBezcov = new Bezec[startovneCisloBezca];
		novyBezec->setStartovneCislo(startovneCisloBezca);
		poleBezcov[0] = *novyBezec;

	}
	else
	{
		Bezec *pomPoleBezcov;
		pomPoleBezcov = new Bezec[startovneCisloBezca + 1];
		if (poleBezcov) {
			for (int i = 0; i < startovneCisloBezca; i++)
			{
				pomPoleBezcov[i] = poleBezcov[i];
			}
			startovneCisloBezca++;
			novyBezec->setStartovneCislo(startovneCisloBezca);
			pomPoleBezcov[startovneCisloBezca-1] = *novyBezec;
			delete[] poleBezcov;
		}
		poleBezcov = new Bezec[startovneCisloBezca + 1]; //
		poleBezcov = pomPoleBezcov;

	}
}

void Preteky::citajZoSuboru(const char * menoSuboru)
{
	if (menoSuboru) {
		FILE *f = fopen(menoSuboru, "rb");
		if (f)
		{
			char charPocetBezcovZoSubora[5] = {0};			
			fscanf(f, "%s ", charPocetBezcovZoSubora);
			int intPocetBezcovZoSubora = atoi(charPocetBezcovZoSubora);
			char *pr;
			char *mn;
			char poh[2];
				for (int i = 0; i < intPocetBezcovZoSubora; i++)
				{
					Bezec *bezec;
					pr = new char[10];
					mn = new char[10];

					fscanf(f, "%s %s %s ", pr, mn, poh);
					{

						bezec = nullptr;
						bezec = new Bezec();
						bezec->setBezca(pr, mn, poh[0]);
						pridajBezca(bezec);
					}
				}

			fclose(f);
		}

	}
}

void Preteky::priradBezcomCas()
{
	for (int i = 0; i < startovneCisloBezca; ++i)
	{
		unsigned int cas = c->generujCas();
		poleBezcov[i].setDosiahnutyCas(cas);
	}
}

void Preteky::vypisBezcov()
{
	
	for (int i = 0; i < startovneCisloBezca; ++i)
	{
		vypisBezca(i);
	}
	printf("\n");
}

void Preteky::vypisBezca(int index)
{
	int hodiny = 0;
	int minuty = 0;
	int sekundy = 0;
	int generovaneCisloZRozsahu = 0;

	poleBezcov[index].vypisBezca();

	generovaneCisloZRozsahu = poleBezcov[index].getDosiahnutyCas();
	hodiny = generovaneCisloZRozsahu / 3600;
	generovaneCisloZRozsahu = generovaneCisloZRozsahu - (hodiny * 3600);
	minuty = generovaneCisloZRozsahu / 60;
	generovaneCisloZRozsahu = generovaneCisloZRozsahu - (minuty * 60);
	sekundy = generovaneCisloZRozsahu;
	
	printf(" Cas: %u", hodiny);
	if (minuty < 10) 
	{
		printf(":0%u", minuty); 
	}
	else
	{
		printf(":%u", minuty);
	}
	if (sekundy < 10)
	{
		printf(":0%u", sekundy);
	}
	else
	{
		printf(":%u", sekundy);
	}
	
	printf("\n");

}

void Preteky::vytvorBezca()
{
	char *pr;
	char *mn;
	char poh[1];

	Bezec *bezec;
	pr = new char[10];
	mn = new char[10];

	scanf("%s %s %s", pr, mn, poh);
	{

		bezec = nullptr;
		bezec = new Bezec();
		bezec->setBezca(pr, mn, poh[0]);
		pridajBezca(bezec);

	}
		printf("Vyberte si moznost\n");
		printf("1 = Nacitanie bezcov z textoveho suboru\n");
		printf("2 = Pridaj bezca z konzoly\n");
		printf("3 = Start pretekov(prirad bezcom casy)\n");
		printf("4 = Vypis bezcov podla startovneho cisla\n");
		printf("5 = Vypis bezcov podla dosiahnutych casov\n");
		printf("6 = Vypis bezcov podla dosiahnutych casov/muzi\n");
		printf("7 = Vypis bezcov podla dosiahnutych casov/zeny\n");
		printf("0 = Koniec\n");
	
}



void Preteky::zoradPodlaStCisB()
{
	vypisBezcov();
}


void Preteky::zoradPodlaDosiahnutychCasov()
{
	
	    unsigned int *casy = new unsigned int[startovneCisloBezca];
		unsigned int *index = new unsigned int[startovneCisloBezca];

		for (int i = 0; i < startovneCisloBezca; ++i)
		{
			casy[i] = poleBezcov[i].getDosiahnutyCas();
			index[i] = i;
		}
		int temp;
		int ind;
		int i,j;

		bool swapped = false;

		for (i = 0; i < startovneCisloBezca - 1; i++) {
			swapped = false;			
			for (j = 0; j < startovneCisloBezca - 1 - i; j++) {			
				if (casy[j] > casy[j + 1]) {
					temp = casy[j];
					ind = index[j];
					casy[j] = casy[j + 1];
					index[j] = index[j + 1];
					casy[j + 1] = temp;
					index[j + 1] = ind;

					swapped = true;					
				}
				else {					
				}
			}		
			if (!swapped) {
				break;
			}		
		}
		for (int i = 0; i < startovneCisloBezca; ++i)
		{
			vypisBezca(index[i]);
		}
		delete[] casy;
		delete[] index;
		printf("\n");
}

void Preteky::zoradPodlaDosiahnutychCasovMuzi()
{
	int pocetMuzov = 0;
	int pomocnePocitadlo = 0;
	for (int i = 0; i < startovneCisloBezca; ++i)
	{
		if (poleBezcov[i].getPohlavie() == 'm')
		{
			++pocetMuzov;
		}
	}
	unsigned int *casy = new unsigned int[pocetMuzov];
	unsigned int *index = new unsigned int[pocetMuzov];

	for (int i = 0; i < startovneCisloBezca; ++i)
	{
		if (poleBezcov[i].getPohlavie() == 'm')
		{
			
			casy[pomocnePocitadlo] = poleBezcov[i].getDosiahnutyCas();
			index[pomocnePocitadlo] = i;
			pomocnePocitadlo++;
		}
		
	}
	int temp;
	int ind;
	int i, j;

	bool swapped = false;

	for (i = 0; i < pocetMuzov - 1; i++) {
		swapped = false;
		for (j = 0; j < pocetMuzov - 1 - i; j++) {
			if (casy[j] > casy[j + 1]) {
				temp = casy[j];
				ind = index[j];
				casy[j] = casy[j + 1];
				index[j] = index[j + 1];
				casy[j + 1] = temp;
				index[j + 1] = ind;

				swapped = true;
			}
			else {
			}
		}
		if (!swapped) {
			break;
		}
	}
	for (int i = 0; i < pocetMuzov; ++i)
	{
		vypisBezca(index[i]);
	}
	delete[] casy;
	delete[] index;
	printf("\n");
}

void Preteky::zoradPodlaDosiahnutychCasovZeny()
{
	int pocetZien = 0;
	int pomocnePocitadlo = 0;
	for (int i = 0; i < startovneCisloBezca; ++i)
	{
		if (poleBezcov[i].getPohlavie() == 'z')
		{
			++pocetZien;
		}
	}
	unsigned int *casy = new unsigned int[startovneCisloBezca];
	unsigned int *index = new unsigned int[startovneCisloBezca];

	for (int i = 0; i < startovneCisloBezca; ++i)
	{
		if (poleBezcov[i].getPohlavie() == 'z')
		{
			casy[pomocnePocitadlo] = poleBezcov[i].getDosiahnutyCas();
			index[pomocnePocitadlo] = i;
			pomocnePocitadlo++;
		}

	}
	int temp;
	int ind;
	int i, j;

	bool swapped = false;

	for (i = 0; i < pocetZien - 1; i++) {
		swapped = false;
		for (j = 0; j < pocetZien - 1 - i; j++) {
			if (casy[j] > casy[j + 1]) {
				temp = casy[j];
				ind = index[j];
				casy[j] = casy[j + 1];
				index[j] = index[j + 1];
				casy[j + 1] = temp;
				index[j + 1] = ind;

				swapped = true;
			}
			else {
			}
		}
		if (!swapped) {
			break;
		}
	}
	for (int i = 0; i < pocetZien; ++i)
	{
		vypisBezca(index[i]);
	}
	delete[] casy;
	delete[] index;
	printf("\n");
}


void Preteky::zapisVysledkyDoSuboru(const char * menoSuboru)
{
	if (menoSuboru) {
		FILE *f = fopen(menoSuboru, "w");
		if (f)
		{
		for (int i = 0; i < startovneCisloBezca; ++i)
			{
				string fd = poleBezcov[i].getUdaje();
				fprintf(f, "%s%s", fd);
			}
		}
		fclose(f);
	}
}



Preteky::~Preteky()
{
	for (int i = 0; i < startovneCisloBezca; ++i) 
	{
		poleBezcov[i].vymazUdaje();
	}
	delete[] poleBezcov;
}
