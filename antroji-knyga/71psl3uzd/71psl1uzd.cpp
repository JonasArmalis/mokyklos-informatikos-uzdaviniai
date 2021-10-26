#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

void skaitymas(ifstream& in, int mas[], int& n);
void skaiciavimas(int& n, int& m, int VAR[], int VER[]);
void salinimas(int mas[], int v, int& n);
void isvedimas(ofstream& out, int VAR[], int VER[], int n, int m);

int main()
{
	ifstream in("Pradiniai.txt");
	ofstream out("Rezultatai.txt");

	int n, m;
	int VAR[100];
	int VER[100];

	skaitymas(in, VAR, n);
	skaitymas(in, VER, m);
	skaiciavimas(n, m, VAR, VER);
	isvedimas(out, VAR, VER, n, m);

	in.close();
	out.close();
	return 0;
}

void skaitymas(ifstream& in, int mas[], int& n)
{
	in >> n;
	for (int i = 0; i < n; i++)
	{
		in >> mas[i];
	}
}

void skaiciavimas(int& n, int& m, int VAR[], int VER[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (VAR[i] == VER[j])
			{
				salinimas(VAR, i, n);
				salinimas(VER, j, m);
				i--;
				j--;
			}
		}
	}
}

void salinimas (int mas[], int v, int& n)
{
	for (int i = v; i <= n; i++)
	{
		mas[i] = mas[i + 1];
	}
	n--;
}

void isvedimas(ofstream& out, int VAR[], int VER[], int n, int m)
{
    if (m != 0)
	{
		out << "Reikalingos verzles: " << endl;

		for(int j = 0; j < m; j++)
        {
            int sk = VER[0];
            int kiekis = 1;
            for (int i = 1; i < m; i ++)
            {
                if(sk == VER[i])
                {
                    kiekis++;
                    salinimas(VER, i, m);
                    i--;
                }
            }
          out << kiekis << " " << sk << endl;
          salinimas(VER, 0, m);
          j--;
        }
	}

	if (n != 0)
	{
		out << "Reikalingi varztai: " << endl;

		for(int j = 0; j < n; j++)
        	{
            		int sk = VAR[0];
            		int kiekis = 1;
		    	for (int i = 1; i < n; i ++)
            		{
                		if(sk == VAR[i])
                		{
                    			kiekis++;
                    			salinimas(VAR, i, n);
                    			i--;
                		}
            		}
          		out << kiekis << " " << sk << endl;
          		salinimas(VAR, 0, n);
          		j--;
        	}
		out << endl;
	}
}
