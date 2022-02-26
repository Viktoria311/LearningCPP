#include <iostream>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
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

void init_players(char customer_point, std::string& player1, std::string& player2)
{
	switch (customer_point)
	{
	case 'X': player1 = "customer"; player2 = "bot"; break;

	case 'O': player1 = "bot"; player2 = "customer"; break;
	}
}

void init_settings(int& rows, int& columns, enter_quantity_of_field_parameter_t f_enter_rows, enter_quantity_of_field_parameter_t f_enter_columns,
					int& quantity, enter_quantity_of_points_t f_enter_quantity_of_points,
					char& customer_point, char& machine_point, choose_a_point_t f_choose_a_point,
					std::string& player1, std::string& player2, init_players_t f_init_players)
{
	rows = f_enter_rows();

	columns = f_enter_columns();

	quantity = f_enter_quantity_of_points(rows, columns);

	f_choose_a_point(customer_point, machine_point);

	f_init_players(customer_point, player1, player2);

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

void step(std::vector<std::vector<char>>& vec, char point, int field_rows, int field_columns,
	      std::string player, step_t step_player, step_t step_machine)
{
	if (player.compare("customer") == 0)
		step_player(vec, point, field_rows, field_columns);
	else
		step_machine(vec, point, field_rows, field_columns);

}

void game(std::vector<std::vector<char>>& my_field, int win_quantity, int  field_rows, int field_columns,
	show_field_t f_show_field, std::string player1, std::string player2, step_t player_step, step_t machine_step,
	common_step_t f_common_step, is_there_a_winner_t f_is_there_a_winner, is_it_the_end_t f_is_it_the_end,
	is_field_full_t f_is_field_full)
{
	do
	{
		if (player1.compare("customer") == 0) f_show_field(my_field, field_rows, field_columns);

		f_common_step(my_field, 'X', field_rows, field_columns, player1, player_step, machine_step);

		if (player1.compare("bot") == 0) f_show_field(my_field, field_rows, field_columns);

		if (f_is_there_a_winner(my_field, win_quantity, field_rows, field_columns)) break;

		f_common_step(my_field, 'O', field_rows, field_columns, player2, player_step, machine_step);

	} while (!f_is_it_the_end(my_field, win_quantity, field_rows, field_columns, f_is_there_a_winner, f_is_field_full));

	f_show_field(my_field, field_rows, field_columns);
}

bool is_there_a_winner(std::vector<std::vector<char>>& my_vec, int quantity, int  rows, int columns)
{
	int count = 0;
	//horizontal check
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			for (int m = 1; m < quantity && j + m < rows; ++m)//a loop of checking identical elements standing sequentially
				if (my_vec[i][j] != '*' && my_vec[i][j] == my_vec[i][j + m]) ++count;

			if (count == quantity - 1) return true;
			count = 0;
		}
	}
	//vertical check
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			for (int m = 1; m < quantity && i + m < rows; ++m)//a loop of checking identical elements standing sequentially
				if (my_vec[i][j] != '*' && my_vec[i][j] == my_vec[i + m][j]) ++count;

			if (count == quantity - 1) return true;
			count = 0;
		}
	}
	//checking diagonally FROM LEFT TO RIGHT AND FROM TOP TO BOTTOM
	for (int j = 0; j < columns; ++j)
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int m = 1; m < quantity && i + m < rows && j + m < columns; ++m)//a loop of checking identical elements standing sequentially
				if (my_vec[i][j] != '*' && my_vec[i][j] == my_vec[i + m][j + m]) ++count;

			if (count == quantity - 1) return true;
			count = 0;
		}
	}

	//checking diagonally FROM LEFT TO RIGHT AND FROM BOTTOM TO TOP
	for (int j = 0; j < columns; ++j)
	{
		for (int i = rows - 1; i >= 0; --i)
		{
			for (int m = 1; m < quantity && i - m >= 0 && j + m < columns; ++m)//a loop of checking identical elements standing sequentially
				if (my_vec[i][j] != '*' && my_vec[i][j] == my_vec[i - m][j + m]) ++count;

			if (count == quantity - 1) return true;
			count = 0;
		}
	}

	return false;// if there were no complete sequences of identical icons in previous checks
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
	//horizontal check
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			for (int m = 1; m < quantity && j + m < rows; ++m)//a loop of checking identical elements standing sequentially
				if (my_vec[i][j] == customer_point && my_vec[i][j] == my_vec[i][j + m]) ++count;

			if (count == quantity - 1) return true;
			count = 0;
		}
	}
	//vertical check
	for (int i = 0; i < rows; ++i)
	{

		for (int j = 0; j < columns; ++j)
		{
			for (int m = 1; m < quantity && i + m < rows; ++m)//a loop of checking identical elements standing sequentially
				if (my_vec[i][j] == customer_point && my_vec[i][j] == my_vec[i + m][j]) ++count;

			if (count == quantity - 1) return true;
			count = 0;
		}
	}
	//checking diagonally FROM LEFT TO RIGHT AND FROM TOP TO BOTTOM
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

	//checking diagonally FROM LEFT TO RIGHT AND FROM BOTTOM TO TOP
	for (int j = 0; j < columns; ++j)
	{
		for (int i = rows - 1; i >= 0; --i)
		{
			for (int m = 1; m < quantity && i - m >= 0 && j + m < columns; ++m)//a loop of checking identical elements standing sequentially
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
