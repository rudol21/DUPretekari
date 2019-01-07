#pragma once
class Cas
{
	const int hornaHranica = 9095;
	const int dolnaHranica = 7140;
	int generovaneCisloZRozsahu = 0;
	
public:
	Cas();
	int generujCas();
	~Cas();
};

