#include <iostream>
#include <string>
#include <ctime>

using namespace std;

char slot[9];

void showslot();
bool moveIsValid(int m);
int Win(); 
int Move = rand() % 7 + 1;

void main()
{
	srand(time(NULL));

	int Whose_Turn = 1; 
	int Move; 
	int Total_Moves = 0;

	slot[0] = '1';
	slot[1] = '2';
	slot[2] = '3';
	slot[3] = '4';
	slot[4] = '5';
	slot[5] = '6';
	slot[6] = '7';
	slot[7] = '8';
	slot[8] = '9';

	while (Win() == 0 && Total_Moves < 9)
	{
		
		do
		{

			
			showslot();

			
			if (Whose_Turn == 1)
			{
				cout <<"It's player 1's turn." << endl;
			}

			else
			{
				cout << "It's player 2's turn." << endl;
			}

			
			cout << "where do you want to go" << endl;
			cin >> Move;
		} while (moveIsValid(Move) != true);

		
		Total_Moves++;

		
		switch (Whose_Turn)
		{
		case (1):
		{
			slot[Move] = 'x';
			Whose_Turn = 2;
			break;
		}

		case (2):
		{
			slot[Move] = 'o';
			Whose_Turn = 1;
		}
		}
	}

	
	showslot();

	if (Win() == 1)
	{
		cout << " Player 1 has won the game!" << endl;
	}

	else if (Win() == 2)
	{
		cout <<  " Player 2 has won the game!" << endl;
	}

	else
	{
		cout << "It's a tie game!" << endl;
	}

	system("PAUSE");
}

void showslot()
{
	cout << endl;
	cout << slot[0] << " | " << slot[1] << " | " << slot[2] << endl;
	cout << "--+---+--" << endl;
	cout << slot[3] << " | " << slot[4] << " | " << slot[5] << endl;
	cout << "--+---+--" << endl;
	cout << slot[6] << " | " << slot[7] << " | " << slot[8] << endl;
	cout << endl;
}

bool moveIsValid(int m)
{
	if (slot[m] != 'x' && slot[m] != 'o')
	{
		return true;
	}

	else
	{
		return false;
	}
}

int Win()
{
	if (slot[0] == slot[1] && slot[1] == slot[2])
	{
		if (slot[0] == 'x')
		{
			return 1;
		}

		else
		{
			return 2;
		}
	}

	if (slot[3] == slot[4] && slot[4] == slot[5])
	{
		if (slot[3] == 'x')
		{
			return 1;
		}

		else
		{
			return 2;
		}
	}

	if (slot[6] == slot[7] && slot[7] == slot[8])
	{
		if (slot[6] == 'x')
		{
			return 1;
		}

		else
		{
			return 2;
		}
	}

	if (slot[0] == slot[3] && slot[3] == slot[6])
	{
		if (slot[0] == 'x')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}

	if (slot[1] == slot[4] && slot[4] == slot[7])
	{
		if (slot[1] == 'x')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (slot[2] == slot[5] && slot[5] == slot[8])
	{
		if (slot[2] == 'x')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}

	if (slot[0] == slot[4] && slot[4] == slot[8])
	{
		if (slot[0] == 'x')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}

	if (slot[2] == slot[4] && slot[4] == slot[6])
	{
		if (slot[2] == 'x')
		{
			return 1;
		}
		else
		{

			return 2;
		}
	}
	return 0;
}
