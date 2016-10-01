#include <iostream>
#include <iomanip>

using namespace std;

void renderField(int x, int y);
bool gameEnded();

char field[3][3] =
{
	{ 'X', 'X', 'X' },
	{ 'X', 'X', 'X' },
	{ 'X', 'X', 'X' }
};

int main()
{
	field[0][0] = 'X';

	renderField(10, 5);
	
	bool result = gameEnded();
	cout << result ? "true" : "false";
	cin.get();
}


void renderField(int x, int y)
{
	for (int i = 0; i < y; i++) cout << endl;
	cout << setw(x) << " " << "#############" << endl;
	cout << setw(x) << " " << "# " << field[0][0] << " # " << field[0][1] << " # " << field[0][2] << " #" << endl;
	cout << setw(x) << " " << "#############" << endl;
	cout << setw(x) << " " << "# " << field[1][0] << " # " << field[1][1] << " # " << field[1][2] << " #" << endl;
	cout << setw(x) << " " << "#############" << endl;
	cout << setw(x) << " " << "# " << field[2][0] << " # " << field[2][1] << " # " << field[2][2] << " #" << endl;
	cout << setw(x) << " " << "#############" << endl;
}

bool gameEnded()
{
	bool gameEnd = false;
	if (*field[0] == 'XXX' || *field[0] == 'OOO') gameEnd = true; 
	if (*field[1] == 'XXX' || *field[1] == 'OOO') gameEnd = true;
	if (*field[2] == 'XXX' || *field[2] == 'OOO') gameEnd = true;

	return gameEnd;
}