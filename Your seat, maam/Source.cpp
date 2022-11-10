#include <iostream>
using namespace std;

const int ROWS = 4;

int findrowindex(int thisrow);
int findseatindex(char thisseat);
void displaycolumn(char seats[][ROWS], int column);



int main() {
	int column = 1;
	char seats[14][ROWS];
	int row = 0;
	int thisrow;
	char thisseat;
	int valid = 0;
	for (column >= 1; column < 14; column++) {
		seats[column][0] = 'D';
		seats[column][1] = 'C';
		seats[column][2] = 'B';
		seats[column][3] = 'A';
	}
	while (true) {
		valid = 0;
		displaycolumn(seats, column);
		while (valid == 0) {
			cout << "Please enter your seat: ";
			cin >> thisrow >> thisseat;
			if (cin.fail()) {
				return 1;
			}
			if (thisrow == 13 && thisseat == 'C') {
				cout << "Invalid seat\n";
			}
			if (thisrow == 13 && thisseat == 'D') {
				cout << "Invalid seat\n";
			}

			if (findrowindex(thisrow) == -1) {
				cout << "Invalid seat\n";
			}
			else if (findseatindex(thisseat) == -1) {
				cout << "Invalid seat\n";
			}
			else valid = 1;
		}
		if (seats[findrowindex(thisrow)][findseatindex(thisseat)] != 'X') {
			seats[findrowindex(thisrow)][findseatindex(thisseat)] = 'X';
			cout << endl;
		}
		else cout << "Seat Taken\n";
	}
}

void displaycolumn(char seats[][ROWS], int column) {
	
	int row = 0;
	for (row = 0; row < 4; row++) {
		for (column = 1; column < 14; column++) {
			if (row == 0 || row == 1) {
				if (column == 13) {
					cout << " ";
				}
				else cout << seats[column][row] << " ";
			}
			else cout << seats[column][row] << " ";
		}
		if (row == 1) {
			cout << endl << endl << "  " << "  " << "  " << "  " << "  " << "  " << "  " << "  " << "  " << "1 " << "1 " << "1 " << "1 ";
			cout << endl << "1 " << "2 " << "3 " << "4 " << "5 " << "6 " << "7 " << "8 " << "9 " << "0 " << "1 " << "2 " << "3 ";
			cout << endl << endl;
		}
		else cout << endl;
	}
}
int findrowindex(int thisrow) {
	if (thisrow < 14 && thisrow > 0) {
		return thisrow;
	}
	else return -1;
}
int findseatindex(char thisseat) {
	switch (thisseat) {
	case 'A':
		return 3;
		break;
	case 'B':
		return 2;
		break;
	case 'C':
		return 1;
		break;
	case 'D':
		return 0;
		break;
	case 'Q':
		return 2;
		break;
	case 'q':
		return 2;
		break;
	default:
		return -1;
		break;
	}
	
}