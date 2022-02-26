#include <iostream>
#include <cctype>
#include <cstdlib>
#include "header.h"

void choose_a_point(char& customer_point, char& computer_point)
{
	while (std::cin.get() != '\n') continue;
	std::cout << "Welcome to the tic-tac-toe!" << std::endl;
	std::cout << "Choose X or 0: ";
	int count = 0;
	do
	{
		if (count != 0) std::cout << "Error enter. Try again to choose X or 0:  ";
		std::cin.get(customer_point);
		while (std::cin.get() != '\n') continue;
		++count;
	} while (customer_point != 'x' && customer_point != 'X' && customer_point != '0' && customer_point != 'o' && customer_point != 'O');

	if (isalpha(customer_point)) customer_point = toupper(customer_point);

	if (customer_point == 'X') computer_point = 'O';
	else computer_point = 'X';
}

int enter_rows()
{
	int my_row;
	std::cout << "How many rows do you want? Enter a number: ";
	while (!(std::cin >> my_row) || my_row < 3)
	{
		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else if (my_row <= 0) std::cout << "The number of rows can`t be 0 or less than 0";
		else  std::cout << "The number of rows can`t be less than 3/ It`a a tic-tac-toe!!!" << std::endl;

		std::cout << "Try again to enter a quantity of rows: ";
	}
	return my_row;
}

int enter_columns()
{
	int my_columns;
	std::cout << "And how many columns do you want? Enter a number: ";
	while (!(std::cin >> my_columns) || my_columns < 3)
	{
		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else if (my_columns <= 0) std::cout << "The number of columns can`t be 0 or less than 0";
		else std::cout << "The number of columns can`t be less than 3/ It`a a tic-tac-toe!!!" << std::endl;

		std::cout << "Try again to enter a quantity of columns: ";
	}
	return my_columns;
}

int enter_quantity_of_points(int rows, int columns)
{
	int points_for_wining;
	std::cout << "And how many points will it enough for wining? Enter a number: ";
	while (!(std::cin >> points_for_wining) || points_for_wining < 3 || (points_for_wining > rows && points_for_wining > columns))
	{
		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else if (points_for_wining < 3) std::cout << "The quantity of points can`t be less than 3. It`a a tic-tac-toe!!!";
		else std::cout << "The quantity of points can`t be more than quantity of rows and quantity of columns" << std::endl;

		std::cout << "Try again to enter a quantity of points for wining: ";
	}
	return points_for_wining;
}

void init_field(std::vector<std::vector<char>>& my_vec, int x, int y)
{
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < y; ++j)
			my_vec[i][j] = '*';

}

void show_field(std::vector<std::vector<char>>& my_vec, int x, int y)
{
	//head of the field
	std::cout << '\t';
	for (int i = 1; i <= y; ++i)
		std::cout << i << '\t';

	std::cout << std::endl << std::endl;

	//main body of the field
	for (int i = 1; i <= x; ++i)
	{
		std::cout << i << " ";
		for (int j = 1; j <= y; ++j)
		{
			std::cout << '\t' << my_vec[i - 1][j - 1];
		}
		std::cout << std::endl << std::endl;
	}
}

void player_steps(std::vector<std::vector<char>>& my_vec, char player_point, int rows, int columns)
{
	int row_of_player_step;

	int column_of_player_step;

	int count = 0;

	std::cout << "Make our move. ";
	do
	{
		if (count != 0)  std::cout << "Impossible step. Try to make your move again.";

		std::cout << "Enter a number of the row: ";

		while (!(std::cin >> row_of_player_step) || row_of_player_step > rows || row_of_player_step <= 0)
		{
			if (!std::cin)
			{
				std::cin.clear();
				std::cin.ignore(100, '\n');
			}
			else if (row_of_player_step <= 0) std::cout << "The number of rows can`t be 0 or less than 0";
			else  std::cout << "The number of rows can`t be less than 3/ It`a a tic-tac-toe!!!" << std::endl;

			std::cout << "Try again to enter a quantity of rows: ";
			while (std::cin.get() != '\n') continue;
		}
		std::cout << "Enter a number of column: ";
		while (!(std::cin >> column_of_player_step) || column_of_player_step > columns || column_of_player_step <= 0)
		{
			if (!std::cin)
			{
				std::cin.clear();
				std::cin.ignore(100, '\n');
			}
			else if (column_of_player_step <= 0) std::cout << "The number of rows can`t be 0 or less than 0";
			else  std::cout << "The number of rows can`t be less than 3/ It`a a tic-tac-toe!!!" << std::endl;

			std::cout << "Try again to enter a quantity of columns: ";
			while (std::cin.get() != '\n') continue;
		}
		--row_of_player_step;
		--column_of_player_step;
		++count;
	} while (my_vec[row_of_player_step][column_of_player_step] != '*');

	my_vec[row_of_player_step][column_of_player_step] = player_point;
}

void machine_steps(std::vector<std::vector<char>>& my_vec, char machine_point, int rows, int columns)
{
	int row_of_machine_step;

	int column_of_machine_step;

	do
	{
		row_of_machine_step = rand() % rows;
		column_of_machine_step = rand() % columns;
	} while (my_vec[row_of_machine_step][column_of_machine_step] != '*');

	my_vec[row_of_machine_step][column_of_machine_step] = machine_point;
}

void step(std::vector<std::vector<char>>& my_vec, char player_point, int number_in_the_queue, int rows, int columns, step_t step_player, step_t step_machine)
{
	if (number_in_the_queue == 1 && player_point == 'X')
	{
		//PLAYER STEP
		step_player(my_vec, player_point, rows, columns);
	}
	else if (number_in_the_queue == 1 && player_point == 'O')
	{
		// MACHINE STEP
		step_machine(my_vec, 'X', rows, columns);
	}
	else if (number_in_the_queue == 2 && player_point == 'X')
	{
		//MACHINE STEP
		step_machine(my_vec, 'O', rows, columns);
	}
	else if (number_in_the_queue == 2 && player_point == 'O')
	{
		// PLAYER STEP
		step_player(my_vec, player_point, rows, columns);
	}
}

bool is_there_a_winner(std::vector<std::vector<char>>& my_vec, int quantity, int  rows, int columns)
{
	int count = 0;
	//проверка по горизонтали
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			for (int m = 1; m < quantity && j + m < rows; ++m)//loop of the check  the same elements together successively 
				if (my_vec[i][j] != '*' && my_vec[i][j] == my_vec[i][j + m]) ++count;

			if (count == quantity - 1) return true;
			count = 0;
		}
	}
	//проверка по вертикали
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			for (int m = 1; m < quantity && i + m < rows; ++m)//цикл проверки одинаковых элементов подряд
				if (my_vec[i][j] != '*' && my_vec[i][j] == my_vec[i + m][j]) ++count;

			if (count == quantity - 1) return true;
			count = 0;
		}
	}
	//проверка по диагонали СЛЕВА НАПРАВО И СВЕРХУ ВНИЗ
	for (int j = 0; j < columns; ++j)
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int m = 1; m < quantity && i + m < rows && j + m < columns; ++m)//цикл проверки одинаковых элементов подряд
				if (my_vec[i][j] != '*' && my_vec[i][j] == my_vec[i + m][j + m]) ++count;

			if (count == quantity - 1) return true;
			count = 0;
		}
	}

	//проверка по диагонали СЛЕВА НАПРАВО И СНИЗУ ВВЕРХ
	for (int j = 0; j < columns; ++j)
	{
		for (int i = rows - 1; i >= 0; --i)
		{
			for (int m = 1; m < quantity && i - m >= 0 && j + m < columns; ++m)//цикл проверки одинаковых элементов подряд
				if (my_vec[i][j] != '*' && my_vec[i][j] == my_vec[i - m][j + m]) ++count;

			if (count == quantity - 1) return true;
			count = 0;
		}
	}

	return false;//  если в предыдущих проверках не было полных последовательностей одинаковых значков
}

bool is_field_full(std::vector<std::vector<char>>& my_vec, int rows, int columns)
{
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
			if (my_vec[i][j] == '*') return false;
	return true;
}

bool is_it_the_end(std::vector<std::vector<char>>& my_vec, int quantity, int  rows, int columns, is_there_a_winner_t f_is_there_a_winner, is_field_full_t f_is_field_full)
{
	return (f_is_there_a_winner(my_vec, quantity, rows, columns) || f_is_field_full(my_vec, rows, columns));
}

bool is_player_a_winner(std::vector<std::vector<char>>& my_vec, char customer_point, int quantity, int rows, int columns)
{
	int count = 0;
	//проверка по горизонтали
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			for (int m = 1; m < quantity && j + m < rows; ++m)//цикл проверки одинаковых элементов подряд
				if (my_vec[i][j] == customer_point && my_vec[i][j] == my_vec[i][j + m]) ++count;

			if (count == quantity - 1) return true;
			count = 0;
		}
	}
	//проверка по вертикали
	for (int i = 0; i < rows; ++i)
	{

		for (int j = 0; j < columns; ++j)
		{
			for (int m = 1; m < quantity && i + m < rows; ++m)//цикл проверки одинаковых элементов подряд
				if (my_vec[i][j] == customer_point && my_vec[i][j] == my_vec[i + m][j]) ++count;

			if (count == quantity - 1) return true;
			count = 0;
		}
	}
	//проверка по диагонали СЛЕВА НАПРАВО и СВЕРХУ ВНИЗ
	for (int j = 0; j < columns; ++j)
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int m = 1; m < quantity && i + m < rows && j + m < columns; ++m)//цикл проверки одинаковых элементов подряд
				if (my_vec[i][j] == customer_point && my_vec[i][j] == my_vec[i + m][j + m]) ++count;

			if (count == quantity - 1) return true;
			count = 0;
		}
	}

	//проверка по диагонали СЛЕВА НАПРАВО и СНИЗУ ВВЕРХ
	for (int j = 0; j < columns; ++j)
	{
		for (int i = rows - 1; i >= 0; --i)
		{
			for (int m = 1; m < quantity && i - m >= 0 && j + m < columns; ++m)//цикл проверки одинаковых элементов подряд
				if (my_vec[i][j] == customer_point && my_vec[i][j] == my_vec[i - m][j + m]) ++count;

			if (count == quantity - 1) return true;
			count = 0;
		}
	}
	return false;
}


void show_the_results(std::vector<std::vector<char>>& my_vec, char player_p, char machine_p, int quantity, int  rows, int columns, is_player_a_winner_t f_is_player_a_winner)
{
	if (f_is_player_a_winner(my_vec, player_p, quantity, rows, columns))
	{
		std::cout << " you are a winner!!! Congratulations!" << std::endl;
	}
	else if (f_is_player_a_winner(my_vec, machine_p, quantity, rows, columns))
	{
		std::cout << "you are a looser." << std::endl;
	}
	else
	{
		std::cout << "drawn game." << std::endl;
	}
}
