#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;


void printInstructions()
{
	printf("Please enter the number where you would like to place your O.\n");
	printf("1 2 3\n4 5 6\n7 8 9\n");
	printf("Please input F if you would like to go first and S if you would like to go second.\n");
}

void printTable(vector<char> &table)
{
	int count = 0;
	for(int i = 0; i < 3; i++)
	{	
		for(int j = 0; j < 3; j++)
		{
			printf("%c ",table.at(count));
			count++;
		}
		printf("\n");
	}
}

void defence(vector<char> &table, bool &changed)
{
	int k = 0;
	if((table[0] == 'O' && (table[1] == 'O' || table[2] == 'O')) || (table[2] == 'O' && (table[0] == 'O' || table[1] == 'O')))
	{
		for(int i = 0; i < 3; i++)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[3] == 'O' && (table[4] == 'O' || table[5] == 'O')) || (table[5] == 'O' && (table[4] == 'O' || table[3] == 'O')))
	{
		for(int i = 4; i < 6; i++)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}

	if((table[6] == 'O' && (table[7] == 'O' || table[8] == 'O')) || (table[8] == 'O' && (table[6] == 'O' || table[7] == 'O')))
	{
		for(int i = 6; i < 9; i++)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[0] == 'O' && (table[3] == 'O' || table[6] == 'O')) || (table[6] == 'O' && (table[0] == 'O' || table[3] == 'O')))
	{
		for(int i = 0; i < 7; i += 3)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[1] == 'O' && (table[4] == 'O' || table[7] == 'O')) || (table[7] == 'O' && (table[1] == 'O' || table[4] == 'O')))
	{
		for(int i = 1; i < 8; i += 3)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[2] == 'O' && (table[5] == 'O' || table[8] == 'O')) || (table[8] == 'O' && (table[5] == 'O' || table[2] == 'O')))
	{
		for(int i = 2; i < 9; i += 3)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[0] == 'O' && (table[4] == 'O' || table[8] == 'O')) || (table[8] == 'O' && (table[4] == 'O' || table[0] == 'O')))
	{
		for(int i = 0; i < 9; i += 4)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
		if(table[0] == 'O' && table[8] == 'O' && table[4] == 'X' && changed == false)
		{
			for(int i = 1; i < 8; i += 2)
			{
				if(k == 0 && table[i] == '-')
				{
					changed = true;
					table[i] = 'X';
					k = 1;
				}
			}
		}
	}
	if((table[2] == 'O' && (table[4] == 'O' || table[6] == 'O')) || (table[6] == 'O' && (table[2] == 'O' || table[4] == 'O')))
	{
		for(int i = 2; i < 7; i += 2)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
		if(table[2] == 'O' && table[6] == 'O' && table[4] == 'X' && changed == false)
		{
			for(int i = 1; i < 8; i += 2)
			{
				if(k == 0 && table[i] == '-')
				{
					table[i] = 'X';
					changed = true;
					k = 1;
				}
			}
		}
	}
}

void offence(vector<char> &table, bool &changed)
{

	if((table[0] == 'X' && (table[1] == 'X' || table[2] == 'X')) || (table[2] == 'X' && (table[0] == 'X' || table[1] == 'X')))
	{
		for(int i = 0; i < 3; i++)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[3] == 'X' && (table[4] == 'X' || table[5] == 'X')) || (table[5] == 'X' && (table[4] == 'X' || table[3] == 'X')))
	{
		for(int i = 4; i < 6; i++)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}

	if((table[6] == 'X' && (table[7] == 'X' || table[8] == 'X')) || (table[8] == 'X' && (table[6] == 'X' || table[7] == 'X')))
	{
		for(int i = 6; i < 9; i++)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[0] == 'X' && (table[3] == 'X' || table[6] == 'X')) || (table[6] == 'X' && (table[0] == 'X' || table[3] == 'X')))
	{
		for(int i = 0; i < 7; i += 3)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}

	if((table[1] == 'X' && (table[4] == 'X' || table[7] == 'X')) || (table[7] == 'X' && (table[1] == 'X' || table[4] == 'X')))
	{
		for(int i = 1; i < 8; i += 3)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[2] == 'X' && (table[5] == 'X' || table[8] == 'X')) || (table[8] == 'X' && (table[5] == 'X' || table[2] == 'X')))
	{
		for(int i = 2; i < 9; i += 3)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[0] == 'X' && (table[4] == 'X' || table[8] == 'X')) || (table[8] == 'X' && (table[4] == 'X' || table[0] == 'X')))
	{
		for(int i = 0; i < 9; i += 4)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[2] == 'X' && (table[4] == 'X' || table[6] == 'X')) || (table[6] == 'X' && (table[2] == 'X' || table[4] == 'X')))
	{
		for(int i = 2; i < 7; i += 2)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}


}

void YourTurn(int &input, vector<char> &table)
{
	printf("Your Turn\n");
	cin >> input;
	table.at(input - 1) = 'O';
	printTable(table);
}

bool Result(vector<char> &table)
{
	for(int i = 0; i < 9; i++)
	{
		if(table[i] == '-')
		{
			return false;
		}
	}
	return true;
}
string Result2(vector<char> &table)
{
	return "Tie";
}
int main()
{
	char ForS;
	int input;
	bool changed = false;
	bool result = false;
	vector<char> table;
	for(int i = 0; i < 11; i++)
	{
		printInstructions();
		cin >> ForS;
		if(ForS == 'F')
		{
			printf("Please enter the number where you would like to place your O.\n");
		}
		table.resize(0);
		table.resize(9,'-');
		printTable(table);
		YourTurn(input, table);
		if(input != 5)
		{
			printf("Computer input\n");
			table.at(4) = 'X';
			printTable(table);
		}
		while(result == false)
		{
			YourTurn(input, table);
			changed = false;
			defence(table, changed);
			if(changed == false)
			{
				offence(table, changed);
			}
			printf("Computer input\n");
			printTable(table);
			result = Result(table);
		}
		if(result == true)
		{
			printf("Game Over! Result: %s\n", Result2(table).c_str());
		}
	}
	return 0;
}

