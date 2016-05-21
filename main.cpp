#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
	int n;
	
	n=atoi(argv[1]);


	//----------------sprawdzam czy liczba jest z przedziału od zera do miliona
	if (n < 0 || n > 1000000)
	{
		printf("Wprowadzona liczba jest nieprawidłowa.\n\n");
		return 0;
	}
	else
		{
			printf("Wprowadzona liczba: %d\n", n);
		}
	
	//-------------------------deklaracja ciagów znaków
	string units[] = {"","jeden ","dwa ","trzy ","cztery ","pięć ","sześć ","siedem ","osiem ","dziewięć "};
	string dozens[] = {"","dziesięć ","jedenaście ","dwanaście ","trzynaście ","czternaście ","pietnaście ","szesnaście ","siedemnaście ","osiemnaście ","dziewietnaście "};
	string dozens_2[] = {"","dziesięć ","dwadzieścia ","trzydzieści ","czterdzieści ","pięcdziesiąt ","sześćdziesiąt ","siedemdziesiąt ","osiemdziesiąt ","dziewięćdziesiąt "};
	string hundreds[] = {"","sto ","dwieście ","trzysta ","czterysta ","pięcset ","sześćset ","siedemset ","osiemset ","dziewięćset "};
	string thousands[] = {"","tysiąc ","tysiące ","tysiące ","tysiące ","tysięcy ","tysięcy ","tysięcy ","tysięcy ","tysięcy "};
	string milions[] = {"","milion ","miliony ","miliony ","miliony ","milionów ","milionów ","milionów ","milionów ","milionów "};

	//-----------------zamiana liczby na słowną liczby od milionów do tysiecy
	int numbMilions, g;//liczba milionów
	g=n % 10000000;
	numbMilions= g / 1000000;
	//printf("%d", numbMilions);
	printf("Wprowadzona liczba słownie: %s%s",units[numbMilions].c_str(), milions[numbMilions].c_str());

	int numbThousands_3, i;
	i=n % 1000000;
	numbThousands_3= i / 100000;
	//printf("%d\n\n", numbThousands_3);
	printf("%s", hundreds[numbThousands_3].c_str());

	int numbThousands, numbThousands_2, e, f;//liczba tysięcy
	e=n % 10000;
	numbThousands_2= e / 1000; //rowne 3
	f=n % 100000;
	numbThousands=f / 10000; //rowne 20

	if ( numbThousands_2 == 0)
	{
		printf("%s%s", dozens_2[numbThousands].c_str(), thousands[numbThousands].c_str());

	}
	else
		if ( numbThousands != 0)
		{
			printf("%s%s%s", dozens_2[numbThousands].c_str(), units[numbThousands_2].c_str(), thousands[numbThousands_2].c_str());
		}
		else
			if( numbThousands == 0)
			{
				printf("%s%s", units[numbThousands_2].c_str(), thousands[numbThousands_2].c_str());
			}

	

	//---------------------zamiana liczby na słowną od jedności do setek
	int numbHundreds, d;//liczba setek
	d=n % 1000;
	numbHundreds=d/100;
	//printf("liczba setek- %d\n", numbHundreds);

	int numbDozens_2, numbUnits, numbDozens, c, b;//liczba dziesiątek
	b= n % 100;
	numbDozens_2= b / 10;
	//printf("liczba dziesiątek- %d\n", numbDozens_2);

	if (numbDozens_2 == 1)
	{
		c= n %100;
		numbDozens= ((c % 10) +1);
		//printf("%d", numbDozens);

	
		printf("%s%s\n\n",hundreds[numbHundreds].c_str(), dozens[numbDozens].c_str());
	}
	else
	{

		numbUnits= n % 10;
		//printf("liczba jedności- %d\n", numbUnits);

		printf("%s%s%s\n",hundreds[numbHundreds].c_str(), dozens_2[numbDozens_2].c_str(), units[numbUnits].c_str());
	}


	getchar();	
	system ("clear");

}


