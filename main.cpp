#include "Bezec.h"
#include "Preteky.h"
#include "CitajSubor.h"
#include <stdlib.h>
 
int main(int argc, char * argv[]) {
	Preteky *preteky = new Preteky();
	
	int x=10;
	while (x != 0)
	{	
		printf("Vyberte si moznost\n");
		printf("1 = Nacitanie bezcov z textoveho suboru\n");
		printf("2 = Pridaj bezca z konzoly(priezvisko meno pohlavie)\n");
		printf("3 = Start pretekov(prirad bezcom casy)\n");
		printf("4 = Vypis bezcov podla startovneho cisla\n");
		printf("5 = Vypis bezcov podla dosiahnutych casov\n");
		printf("6 = Vypis bezcov podla dosiahnutych casov/muzi\n");
		printf("7 = Vypis bezcov podla dosiahnutych casov/zeny\n");
		printf("8 = Zapis vysledky do suboru\n");
		printf("0 = Koniec\n");
		
		scanf("%d", &x);
		system("cls");
		switch (x)
		{
		case 1:
			preteky->citajZoSuboru("subor.txt");
			break;
		case 2:
			char *pr;
			char *mn;
			char poh[2];

			Bezec *bezec;
			pr = new char[10];
			mn = new char[10];

			scanf("%s %s %s", pr, mn, poh);
			{

				bezec = nullptr;
				bezec = new Bezec();
				bezec->setBezca(pr, mn, poh[0]);
				preteky->pridajBezca(bezec);

			}
			break;
		case 3:
			preteky->priradBezcomCas();
			break;
		case 4:
			preteky->zoradPodlaStCisB();
			break;
		case 5:
			preteky->zoradPodlaDosiahnutychCasov();
			break;
		case 6:
			preteky->zoradPodlaDosiahnutychCasovMuzi();
			break;
		case 7:
			preteky->zoradPodlaDosiahnutychCasovZeny();
			break;
		case 8:
			preteky->zapisVysledkyDoSuboru("vysledky.txt");
			break;
		case 0:
			break;

		}
	}
	
	delete preteky;

}