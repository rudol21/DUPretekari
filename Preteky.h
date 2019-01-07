#pragma once
#include "Bezec.h"
#include "Cas.h"
class Preteky
{
	Cas *c = new Cas();
	Bezec *poleBezcov = nullptr;
	unsigned int startovneCisloBezca = 0;
public:
	Preteky();
	Bezec getBezca(int index);
    void nastavBezca(int index,char* priezviskoBezca, char* menoBezca, char pohlavieBezca);
	void pridajBezca(Bezec *novyBezec);
	void citajZoSuboru(const char * menoSuboru);
	void priradBezcomCas();
	void vypisBezcov();
	void vypisBezca(int index);
	void vytvorBezca();	
	void zoradPodlaStCisB();
	void zoradPodlaDosiahnutychCasov();
	void zoradPodlaDosiahnutychCasovMuzi();
	void zoradPodlaDosiahnutychCasovZeny();
	void zapisVysledkyDoSuboru(const char * menoSuboru);
	
	~Preteky();
};

