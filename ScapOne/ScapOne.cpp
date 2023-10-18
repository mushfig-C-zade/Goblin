#include <iostream>
#include <conio.h>
#include<Windows.h>
using namespace std;

int main()
{
	char menu[3]{ '>' ,' ',' ' };
	int menuStep = 0;
	int ch = 0;
	char mainCharacter = '&';
	char enemyView = '^';
	char wallView = '#';
	char quit;
	int score = 0;

	do
	{
		system("cls");

		if (ch == 224)
		{
			ch = _getch();
			if (ch == 72)
			{
				if (menuStep - 1 >= 0)
				{
					swap(menu[menuStep], menu[menuStep - 1]);
					menuStep--;
				}
			}

			else if (ch == 80)
			{
				if (menuStep + 1 <= 2)
				{
					swap(menu[menuStep], menu[menuStep + 1]);
					menuStep++;
				}
			}
		}

		if (ch == 13 && menu[0] == '>')
		{
			system("cls");
			char oyun[21][21]{};
			int x = 1;
			int y = 1;
			int k = 3;
			int m = 4;
			int symbol = 0;
			oyun[x][y] = mainCharacter;
			oyun[k][m] = enemyView;
			int schore = 0;
			do
			{
				system("cls");
				if (symbol == 224)
				{
					symbol = _getch();
					if (symbol == 80)
					{
						if (x + 1 < 20)
						{
							if (oyun[x + 1][y] != ' ')oyun[x + 1][y] = ' ';


							swap(oyun[x][y], oyun[x + 1][y]);
							x++;
						}

					}
					if (symbol == 72)
					{
						if (x - 1 > 0)
						{
							if (oyun[x - 1][y] != ' ')oyun[x - 1][y] = ' ';

							swap(oyun[x][y], oyun[x - 1][y]);
							x--;
						}
					}
					if (symbol == 75)
					{
						if (y - 1 > 0)
						{

							if (oyun[x][y - 1] != ' ')oyun[x][y - 1] = ' ';

							swap(oyun[x][y], oyun[x][y - 1]);
							y--;
						}
					}
					if (symbol == 77)
					{
						if (y + 1 < 20)
						{
							if (oyun[x][y + 1] != ' ')oyun[x][y + 1] = ' ';

							swap(oyun[x][y], oyun[x][y + 1]);
							y++;
						}
					}
					
				}
				if (symbol == 'q' || symbol == 'Q')
				{
					break;
				}

				if (x == k && y == m)
				{
					schore += 20;
					k = rand() % 19 + 1;
					m = rand() % 19 + 1;

					oyun[k][m] = enemyView;
				}
				for (size_t i = 0; i < 21; i++)
				{
					for (size_t j = 0; j < 21; j++)
					{
						if (i == 0 || j == 0 || i == 20 || j == 20)
						{
							cout << wallView;
						}
						else if (oyun[i][j] == mainCharacter)
						{
							cout << mainCharacter;
						}
						else if (oyun[i][j] == enemyView)
						{
							cout << enemyView;
						}
						else
						{
							cout << " ";
						}
					}
					cout << "\n";
				}
				cout << "Quit-q\n";
				cout << "Schore: " << schore;
			} while (symbol = _getch());			
		}
		else if (ch == 13 && menu[1] == '>')
		{
			system("cls");
			char menu2[4]{ '>',' ',' ',' ' };
			int menuStep1 = 0;
			int ch1 = 0;

			do
			{


				if (ch1 == 224)
				{
					ch1 = _getch();

					if (ch1 == 72)
					{
						if (menuStep1 - 1 >= 0)
						{
							swap(menu2[menuStep1], menu2[menuStep1 - 1]);
							menuStep1--;
						}
					}

					else if (ch1 == 80)
					{
						if (menuStep1 + 1 <= 3)
						{
							swap(menu2[menuStep1], menu2[menuStep1 + 1]);
							menuStep1++;
						}
					}
				}
				else if (ch1 == 13 && menu2[0] == '>')
				{
					cout << "Enter Main Character View: ";
					cin >> mainCharacter;

				}
				else if (ch1 == 13 && menu2[1] == '>')
				{
					cout << "Enter Enemy View: ";
					cin >> enemyView;
				}
				else if (ch1 == 13 && menu2[2] == '>')
				{
					cout << "Enter Wall View: ";
					cin >> wallView;
				}
				else if (ch1 == 13 && menu2[3] == '>')
				{
					system("cls");
					break;
				}

				system("cls");

				cout << menu2[0] << "Main Character View: " << mainCharacter << "\n";
				cout << menu2[1] << "Enemy View: " << enemyView << "\n";
				cout << menu2[2] << "Wall View: " << wallView << "\n";
				cout << menu2[3] << "Back" << "\n";

			} while (ch1 = _getch());

		}
		else if (ch == 13 && menu[2] == '>')
		{
			system("cls");
			cout << "Siz oyundan cixis verdiz \n";
			break;
		}

		cout << menu[0] << "Play" << "\n";
		cout << menu[1] << "Setting" << "\n";
		cout << menu[2] << "Quit" << "\n";

	} while (ch = _getch());


	cout << "\n";
	system("pause");



}