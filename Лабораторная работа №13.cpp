#include <iostream>
using namespace std;
int amountOfSquaresInLine;
bool isLastRowReached = false;
int** ChessBoard;
void create_dynamic_array() {
	ChessBoard = new int* [amountOfSquaresInLine];
	for (int i = 0; i < amountOfSquaresInLine; i++)
		ChessBoard[i] = new int[amountOfSquaresInLine];
}
void put_queen(int row_index, int column_index) {
	int fill_diagonal;
	for (int x = 0; x < amountOfSquaresInLine; ++x)
	{
		++ChessBoard[x][column_index]; 
		++ChessBoard[row_index][x]; 
		fill_diagonal = column_index - row_index + x;
		if (fill_diagonal >= 0 && fill_diagonal < amountOfSquaresInLine)
			++ChessBoard[x][fill_diagonal];
		fill_diagonal = column_index + row_index - x;
		if (fill_diagonal >= 0 && fill_diagonal < amountOfSquaresInLine)
			++ChessBoard[x][fill_diagonal];
		ChessBoard[row_index][column_index] = -1; 
	}
}
void delete_queen(int row_index, int column_index) {
	int fill_diagonal;
	for (int x = 0; x < amountOfSquaresInLine; ++x)
	{
		--ChessBoard[x][column_index];  
		--ChessBoard[row_index][x]; 
		fill_diagonal = column_index - row_index + x;
		if (fill_diagonal >= 0 && fill_diagonal < amountOfSquaresInLine)
			--ChessBoard[x][fill_diagonal];
		fill_diagonal = column_index + row_index - x;
		if (fill_diagonal >= 0 && fill_diagonal < amountOfSquaresInLine)
			--ChessBoard[x][fill_diagonal];
		ChessBoard[row_index][column_index] = 0; 
	}
}
bool try_put_queen(int row_index) { 
	for (int column_index = 0; column_index < amountOfSquaresInLine; ++column_index) 
	{
		if (ChessBoard[row_index][column_index] == 0) 
		{
			put_queen(row_index, column_index); 
			if (row_index == amountOfSquaresInLine - 1) 
				isLastRowReached = true;
			else if (!(isLastRowReached = try_put_queen(row_index + 1))) delete_queen(row_index, column_index); 
		}
		if (isLastRowReached) column_index = amountOfSquaresInLine; 
	}
	return isLastRowReached; 
}
void clear_chess_board() {
	for (int i = 0; i < amountOfSquaresInLine; i++)
		for (int j = 0; j < amountOfSquaresInLine; j++)
			ChessBoard[i][j] = 0;
}
void show_chess_board() {
	for (int i = 0; i < amountOfSquaresInLine; ++i)
	{
		for (int j = 0; j < amountOfSquaresInLine; ++j)
		{
			if (ChessBoard[i][j] == -1) cout << "[Ф]";
			else cout << " . ";
		}
		cout << "\n";
	}
}
void shield_from_the_durak(int &sizeOfChessBoard) {
	do {
		cin >> sizeOfChessBoard;
		if (cin.fail()) {
			cout << "Нужно ввести положительное число: ";
			cin.clear();
			cin.ignore(3076, '\n');
			_flushall();
		}
		else
		if (sizeOfChessBoard < 1) 
			cout << "Нужно ввести положительное число: ";		
	} while (sizeOfChessBoard < 1);
}
bool has_queen() {
	for (int i = 0; i < amountOfSquaresInLine; i++)
		for (int j = 0; j < amountOfSquaresInLine; j++)
			if (ChessBoard[i][j] == -1)
				return true;
	return false;
}
void delete_dynamic_array() {
	for (int i = 0; i < amountOfSquaresInLine; i++)
		delete ChessBoard[i];
	delete[] ChessBoard;
}
int main()
{
	setlocale(LC_ALL, "");
	cout << "Введите размер шахматной доски: ";
	shield_from_the_durak(amountOfSquaresInLine);
	create_dynamic_array();
	clear_chess_board();
	try_put_queen(0);
	if (has_queen())
		cout << "Ферзи расставлены на шахматной доске (ни один не находится под боем другого)\n";
	else
		cout << "Не удалось расставить ферзей на шахматной доске\n";
	show_chess_board();
	delete_dynamic_array();
	system("pause");
	return 0;
}