void ReadLine(char EILE[], int &n, ifstream& input)
{
	input.getline(EILE, 1000);
	n = strlen(EILE);
}

/*
Simboliu eilutes skaitymo funkcija
	EILE - simboliu masyvas i kuri skaitome
	n - busimu simboliu kiekis jame
	input - duomenu failas
*/