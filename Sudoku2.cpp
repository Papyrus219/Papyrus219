#include<iostream>
using namespace std;
  
int pole_gry[9][9] = {9,3,0,1,0,0,0,0,0,  1,2,0,0,0,0,7,3,0,  0,6,0,0,0,5,0,0,2,
					  0,0,0,3,0,2,7,6,0,  8,0,0,0,0,0,0,0,9,  0,7,6,5,0,9,0,0,0,
					  6,0,0,2,0,0,0,9,0,  0,7,1,0,0,0,0,4,8,  0,0,0,0,0,4,0,2,1};
int *wsk_pole_gry[4][4] = {};

void Wypisywanie_planszy();
bool Czy_legalne(int n,int x,int y);
bool Czy_wygrana();
void Wypelnienie_tabwsk();

int main()
{
	Wypelnienie_tabwsk();
	
	cout << "====================\n";
	cout << "       SUDOKU       \n";
	cout << "By:Papyrus219       \n";
	cout << "====================\n\n";
	cout<<"1.Zagraj \n2.Info \n3.Wyjdz\n";
	
	while(true)
	{
		int wybor{};
		cout <<"\nWybor: ";
		cin >> wybor;
	
		switch(wybor)
		{
			case 1:
				Wypisywanie_planszy();

				while(!Czy_wygrana())
				{
					cout << endl;

					int x{},y{};
					cout << "Podaj wspolrzedne pola: ";
					cin >> y >> x;
					if(*wsk_pole_gry[y-1][x-1] == 0)
					{
						int n{};
						cout << "Podaj wartosc do wpisania: ";
						cin >> n;
						if( Czy_legalne(n,x-1,y-1 ) )
						{
							*wsk_pole_gry[y-1][x-1] = n;
							Wypisywanie_planszy();
						}

					}
					else
						cout << "NIEPOPRAWNY RUCH: POLE ZAJETE\n";
				}
				cout << endl;
				Wypisywanie_planszy();
			cout << endl;
			cout << "===============================";
			cout << "		  GRATULACJE!           ";
			cout << "===============================";
			return 0;
		
		case 2:
			cout << "Hej! Witaj w moiej pierwszej aplikacji, ktora nie jest tylko zadaniem konkursowym! \nOgolnie zasady sa proste: \n1.Program nie mysli za ciebie, on tylko sprawdza czy dany ruch jest AKTUALNIE legalny. Nie wstawiaj nic jesli nie jestes pewien. \n2.W wspolrzednych podawaj najpierw rzad potem kolumne \n3.Baw sie dobrze!\n";
			break;
		case 3:
			return 0;
	}
	}
	
	

	

	return 0;
}

/*-------------------------------------------------
  FUNKCJE ZWYK£E
  -------------------------------------------------*/

void Wypisywanie_planszy()
{
	cout << endl << "-------------------------" << endl;
	for(int meta=0;meta<9;meta+=3) //Za pierwszym razem potrzebujemy wartoœci od 0-2 , za drugim od 3-5 a za trzecim od 6-8
	{
		cout << "| ";
		for(int i=meta;i<=meta+2;i++) //Wdra¿anie tych przedzia³ów
		{
			for(int j=0;j<3;j++)
			{
				cout << pole_gry[i][j] << " ";
			}
			cout << "| ";
		}
		
		cout << endl << "| ";
		
		for(int i=meta;i<=meta+2;i++) //Wdra¿anie tych przedzia³ów
		{
			for(int k=3;k<6;k++)
			{
				cout << pole_gry[i][k] << " ";
			}
			cout << "| ";
		}
		
		cout << endl << "| ";
		
		for(int i=meta;i<=meta+2;i++) //Wdra¿anie tych przedzia³ów
		{
			for(int l=6;l<9;l++)
			{
				cout << pole_gry[i][l] << " ";
			}
			cout << "| ";
		}
		cout << endl << "-------------------------" << endl;
	}
}

bool Czy_legalne(int n,int x,int y)
{
	if(n>9 || n<1)
	{
		cout << "NIEPOPRAWNY RUCH: NIEPRAWIDLOWA WARTOSC!\n";
		return false;
	}
	
	for(int i=0;i<9;i++)
	{
		if(*wsk_pole_gry[y][i] == n  ||  *wsk_pole_gry[i][x] == n) //Sprawdzenie czy takiej wartoœci ju¿ nie ma w rzêdzie lub kolumnie
		{
			cout << "NIEPOPRAWNY RUCH: WARTOSC SIE POWTARZA!\n";
			return false;	
		}
	}
	
	if(x<3)
	{
		if(y<3)
		{
			for(int i=0;i<9;i++)
				if(pole_gry[0][i] == n)
				{
					cout << "NIEPOPRAWNY RUCH: WARTOSC SIE POWTARZA!\n";
					return false;
				}
		}	
		else if(y<6)
		{
			for(int i=0;i<9;i++)
				if(pole_gry[1][i] == n)
				{
					cout << "NIEPOPRAWNY RUCH: WARTOSC SIE POWTARZA!\n";
					return false;
				}
		}
		else
		{
			for(int i=0;i<9;i++)
				if(pole_gry[2][i] == n)
				{
					cout << "NIEPOPRAWNY RUCH: WARTOSC SIE POWTARZA!\n";
					return false;
				}
		}
	}
	else if(x<6)
	{
		if(y<3)
		{
			for(int i=0;i<9;i++)
				if(pole_gry[3][i] == n)
				{
					cout << "NIEPOPRAWNY RUCH: WARTOSC SIE POWTARZA!\n";
					return false;
				}
		}	
		else if(y<6)
		{
			for(int i=0;i<9;i++)
				if(pole_gry[4][i] == n)
				{
					cout << "NIEPOPRAWNY RUCH: WARTOSC SIE POWTARZA!\n";
					return false;
				}
		}
		else
		{
			for(int i=0;i<9;i++)
				if(pole_gry[5][i] == n)
				{
					cout << "NIEPOPRAWNY RUCH: WARTOSC SIE POWTARZA!\n";
					return false;
				}
		}
	}
	else
	{
		if(y<3)
		{
			for(int i=0;i<9;i++)
				if(pole_gry[6][i] == n)
				{
					cout << "NIEPOPRAWNY RUCH: WARTOSC SIE POWTARZA!\n";
					return false;
				}
		}	
		else if(y<6)
		{
			for(int i=0;i<9;i++)
				if(pole_gry[7][i] == n)
				{
					cout << "NIEPOPRAWNY RUCH: WARTOSC SIE POWTARZA!\n";
					return false;
				}
		}
		else
		{
			for(int i=0;i<9;i++)
				if(pole_gry[8][i] == n)
				{
					cout << "NIEPOPRAWNY RUCH: WARTOSC SIE POWTARZA!\n";
					return false;
				}
		}
	}
		
	return true;
}

bool Czy_wygrana()
{
	for(int i=0;i<9;i++)
		for(int j=0;i<9;j++)
			if(*wsk_pole_gry[i][j]==0)
				return false;
				
	return true;
}

/*-------------------------------------------------
  FUNKCJE DO WSKANIKÓW
  -------------------------------------------------*/
  
void Wypelnienie_tabwsk() //Potrzebne by pommimo wypisywania inn¹ kolejnoœci¹ urzytkownik móg³ podawaæ wspó³rzêdne tak jak widzi
{
	int I{},J{}; //Zmienne s³u¿¹ce do iterowania po tablicy wskaŸników
	for(int meta=0;meta<9;meta+=3)
	{
		for(int i=meta;i<meta+3;i++)
		{
			for(int j=0;j<3;j++)
			{
				wsk_pole_gry[I][J] = &pole_gry[i][j]; //Wk³adanie do tablicy wskaŸników, adresów tablicy gry w kolejnoœci jakiej s¹ wypisywane na ekranie
				
				J++; //Przeskakujemy do kolejnej kolumny tablicy
				if(J>=9) //Przeskakujeny do kolejnego rzêdu tablicy
				{J=0; I++;}
			}
		}
		
		for(int i=meta;i<meta+3;i++)
		{
			for(int k=3;k<6;k++)
			{
				wsk_pole_gry[I][J] = &pole_gry[i][k]; //Wk³adanie do tablicy wskaŸników, adresów tablicy gry w kolejnoœci jakiej s¹ wypisywane na ekranie
				
				J++; //Przeskakujemy do kolejnej kolumny tablicy
				if(J>=9) //Przeskakujeny do kolejnego rzêdu tablicy
				{J=0; I++;}
			}
		}
		
		for(int i=meta;i<meta+3;i++)
		{
			for(int l=6;l<9;l++)
			{
				wsk_pole_gry[I][J] = &pole_gry[i][l]; //Wk³adanie do tablicy wskaŸników, adresów tablicy gry w kolejnoœci jakiej s¹ wypisywane na ekranie
				
				J++; //Przeskakujemy do kolejnej kolumny tablicy
				if(J>=9) //Przeskakujeny do kolejnego rzêdu tablicy
				{J=0; I++;}
			}
		}
	}
}
