#include <Windows.h>
#include <iostream>
using namespace std;

int queen = -1;
int board[8][8];

void set_queen(int i, int j) // Ставим ферзя на позицию (i,j) и помечаем какие клетки перекрываются
{
	int d;
	for (int x = 0; x < 8; ++x) {
		board[x][j]++; // помечаем вертикаль
		board[i][x]++; // затем горизонталь
		d = j - i + x; // 1я диагональ
		if (d >= 0 && d < 8) {
			board[x][d]++;
		}
		d = j + i - x; // 2я диагональ
		if (d >= 0 && d < 8) {
			board[x][d]++;
		}
	}
	board[i][j] = queen;
}

void remove_queen(int i, int j) // Убираем ферзя с доски по координатам (i, j)
{
	int d;
	for (int x = 0; x < 8; ++x) {
		board[x][j]--; // очистка вертикали
		board[i][x]--; // затем горизонтали
		d = j - i + x; // 1я диагональ
		if (d >= 0 && d < 8) {
			board[x][d]--;
		}
		d = j + i - x; // 2я диагональ
		if (d >= 0 && d < 8) {
			board[x][d]--;
		}
	}
	board[i][j] = 0; // убираем саму фигуру
}

bool check_queen(int i)
{
	bool result = false;
	for (int j = 0; j < 8; j++) {
		if (board[i][j] == 0) {
			set_queen(i, j);
			if (i == 7)
				result = true;
			else {
				result = check_queen(i + 1);
				if (!result)
					remove_queen(i, j);
			}
		}
	}
	return result;
}

int main()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			board[i][j] = 0;
	}
	check_queen(0);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			if (board[i][j] == -1)
				cout << "[Q] ";
			else
				cout << "[ ] ";
		cout << endl;
	}
    cout << endl;
}