#pragma once
#include <stdio.h>
#include <string>


using namespace std;
class Bezec
{
	
	char *meno = nullptr;
	char *priezvisko = nullptr;
	char pohlavie;
	unsigned int startovneCislo = 0;
	unsigned int dosiahnutyCas = 0;

public:
	Bezec();
	~Bezec();
	char getMeno() { return *meno; }
	char getPriezvisko() { return *priezvisko; }
	char getPohlavie() { return pohlavie; }
	unsigned int getStartovneCislo() { return startovneCislo; }
	double getDosiahnutyCas() { return dosiahnutyCas; }
	string getUdaje();
	void vymazUdaje();
	void setBezca(char* priezviskoBezca, char* menoBezca, char pohlavieBezca);
	void setMeno(char *menoBez);		
	void setPriezvisko(char *priezviskoBez);	
	void setPohlavie(char pohlavieBez);	
	void setStartovneCislo(unsigned int stCislo);
	void setDosiahnutyCas(unsigned int dosiahnutyCasBezca);
	void vypisBezca();

};

