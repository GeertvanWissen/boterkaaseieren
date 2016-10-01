#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void renderField(int x, int y);
bool gameEnded();
char winnerIs();

char field[3][3] =
{
	{ ' ', ' ', ' ' },
	{ ' ', ' ', ' ' },
	{ ' ', ' ', ' ' }
};

int main()
{
	renderField(10, 5);

	bool result = gameEnded();
	cout << result;
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
	if (winnerIs() != ' ')
	{
		return true;
	}
	else {
		return false;
	}
}

char winnerIs()
{
	char winner = ' ';

	// horizontal lines
	if (string(field[0]).substr(0, 3) == "XXX" || string(field[1]).substr(0, 3) == "XXX" || string(field[2]).substr(0, 3) == "XXX") winner = 'X';
	if (string(field[0]).substr(0, 3) == "OOO" || string(field[1]).substr(0, 3) == "OOO" || string(field[2]).substr(0, 3) == "OOO") winner = 'O';

	//vertical lines
	if ((field[0][0] == 'X' && field[1][0] == 'X' && field[2][0] == 'X') || (field[0][1] == 'X' && field[1][1] == 'X' && field[2][1] == 'X') || (field[0][2] == 'X' && field[1][2] == 'X' && field[2][2] == 'X')) winner = 'X';
	if ((field[0][0] == 'O' && field[1][0] == 'O' && field[2][0] == 'O') || (field[0][1] == 'O' && field[1][1] == 'O' && field[2][1] == 'O') || (field[0][2] == 'O' && field[1][2] == 'O' && field[2][2] == 'O')) winner = 'O';

	//diagonal lines
	if ((field[0][0] == 'X' && field[1][1] == 'X' && field[2][2] == 'X') || (field[2][0] == 'X' && field[1][1] == 'X' && field[0][2] == 'X')) winner = 'X';
	if ((field[0][0] == 'O' && field[1][1] == 'O' && field[2][2] == 'O') || (field[2][0] == 'O' && field[1][1] == 'O' && field[0][2] == 'O')) winner = 'O';

	return winner;
}