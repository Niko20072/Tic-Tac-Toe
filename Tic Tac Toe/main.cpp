#include <iostream>
using namespace std;

char t[3][3];
int n = 2,x,y,gata=0;

void initialization()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
			t[i][j] =' ';
	}
}

void display()
{
	system("cls");
	int cont = 2;
	cout << "\033[97m  1 2 3 " << endl <<"1\033[0m";
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << "|";
			if (t[i][j] == 'X')
				cout << "\033[91m" << t[i][j] << "\033[0m";
			else if (t[i][j] == '0')
				cout << "\033[36m" << t[i][j] << "\033[0m";
			else
				cout << t[i][j];

		}
		cout << "|" << endl;
		if (i <= n - 1)
		{
			cout << " -------" <<endl << "\033[97m" << cont << "\033[0m";
			cont++;
		}
	}
	cout << endl;
}

int win_rows()
{
	int contx = 0, cont0 = 0;
	for (int i = 0; i <= n; i++)
	{
			if (t[0][i] == 'X')
				contx++;
			if (t[0][i] == '0')
				cont0++;
	}
	if (contx == 3 || cont0 == 3)
		return 1;
	contx = 0;
	cont0 = 0;
	for (int i = 0; i <= n; i++)
	{
		if (t[1][i] == 'X')
			contx++;
		if (t[1][i] == '0')
			cont0++;
	}
	if (contx == 3 || cont0 == 3)
		return 1;
	contx = 0;
	cont0 = 0;
	for (int i = 0; i <= n; i++)
	{
		if (t[2][i] == 'X')
			contx++;
		if (t[2][i] == '0')
			cont0++;
	}
	if (contx == 3 || cont0 == 3)
		return 1;
	return 0;
}

int win_columns()
{
	int contx = 0, cont0 = 0;
	for (int i = 0; i <= n; i++)
	{
		if (t[i][0] == 'X')
			contx++;
		if (t[i][0] == '0')
			cont0++;
	}
	if (contx == 3 || cont0 == 3)
		return 1;
	contx = 0;
	cont0 = 0;
	for (int i = 0; i <= n; i++)
	{
		if (t[i][1] == 'X')
			contx++;
		if (t[i][1] == '0')
			cont0++;
	}
	if (contx == 3 || cont0 == 3)
		return 1;
	contx = 0;
	cont0 = 0;
	for (int i = 0; i <= n; i++)
	{
		if (t[i][2] == 'X')
			contx++;
		if (t[i][2] == '0')
			cont0++;
	}
	if (contx == 3 || cont0 == 3)
		return 1;
	return 0;
}

int win_main_diagonal()
{
	int contx = 0, cont0 = 0;
	for (int i = 0; i <= n; i++)
	{
		if (t[i][i] == 'X')
			contx++;
		if (t[i][i] == '0')
			cont0++;
	}
	if (contx == 3 || cont0 == 3)
		return 1;
	return 0;
}

int win_secondary_diagonal()
{
	if ((t[0][2] == 'X') && (t[1][1] == 'X') && (t[2][0] == 'X'))
		return 1;
	if ((t[0][2] == '0') && (t[1][1] == '0') && (t[2][0] == '0'))
		return 1;
	return 0;
}

int win()
{
	if (win_rows() == 1)
		return 1;
	if (win_columns() == 1)
		return 1;
	if (win_main_diagonal() == 1)
		return 1;
	if (win_secondary_diagonal() == 1)
		return 1;
	return 0;
}

void validate()
{
	cin >> x >> y;
	if (x > 3 || y > 3)
	{
		cout << "You are not allowed numbers greater than 3. Try again: ";
		validate();
	}
	if (x < 1 || y < 1)
	{
		cout << "You are not allowed numbers less than 1. Try again: ";
		validate();
	}
	if(t[x-1][y-1]=='X' || t[x-1][y-1]=='0')
	{
		cout << "You are not allowed to fill an already filled cell. Try again: ";
		validate();
	}
}

void player1()
{
	cout << "\033[91mPLAYER 1 (X)\033[0m"<<endl;
	cout << "Line, Column: ";
	validate();
	t[x-1][y-1] = 'X';
	display();
	if (win() == 1)
	{
		cout << "\033[91mPLAYER 1 WON\033[0m";
		gata = 1;
	}
		
}

void player2()
{
	cout << "\033[36mPLAYER 2 (0)\033[0m" << endl;
	cout << "Line, Column: ";
	validate();
	t[x-1][y-1] = '0';
	display();
	if (win() == 1)
	{
		cout << "\033[36mPLAYER 2 WON\033[0m";
		gata = 1;
	}
}

void play()
{
	int cont = 0;
	while (cont < 9 && gata==0)
	{
		player1();
		cont++;
		if (cont < 9 && gata==0)
		{
			player2();
			cont++;
		}
	}
	if (gata == 0)
		cout << "\033[33mDRAW\033[0m";
}

int main()
{
	int ok1;
	do
	{
		initialization();
		display();
		play();
		cout << endl << "\033[93mPLAY AGAIN y/n: \033[0m";
		char choice;
		cin >> choice;
		if (choice == 'n')
			break;
		do
		{
			ok1 = 1;
			if (choice != 'n' && choice != 'y')
			{
				cout << "You must type y or n ";
				cin >> choice;
				ok1 = 0;
			}
		} while (ok1 == 0);
		gata = 0;
	} while (true);
	return 0;
}