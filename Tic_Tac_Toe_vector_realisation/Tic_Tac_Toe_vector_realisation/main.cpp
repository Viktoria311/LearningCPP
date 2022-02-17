#include <iostream>
#include <cctype>
#include <vector>
#include "header.h"

int main()
{
	char player_point;

	char machine_point;

	int points_for_winning;

	int row;

	int column;

	row = enter_rows();

	column = enter_columns();

	points_for_winning = enter_quantity_of_points(row, column);

	choose_a_point(player_point, machine_point);

	std::vector<std::vector<char>> vec(row, std::vector<char>(column));

	init_vec(vec, row, column);

	if (player_point == 'X')
	{
		do
		{
			show_field(vec, row, column);
			player_steps(vec, player_point, row, column);
			if (is_there_a_winner(vec, points_for_winning, row, column)) break;
			machine_steps(vec, machine_point, row, column);
		} while (!is_there_a_winner(vec, points_for_winning, row, column) && !is_arr_full(vec, row, column));
	}
	else
	{
		do
		{
			machine_steps(vec, machine_point, row, column);
			show_field(vec, row, column);
			if (is_there_a_winner(vec, points_for_winning, row, column)) break;
			player_steps(vec, player_point, row, column);
		} while (!is_there_a_winner(vec, points_for_winning, row, column) && !is_arr_full(vec, row, column));
	}


	show_field(vec, row, column);

	if (is_player_a_winner(vec, player_point, points_for_winning, row, column))
	{
		std::cout << " you are a winner!!! Congratulations!" << std::endl;
	}
	else if (is_player_a_winner(vec, machine_point, points_for_winning, row, column))//
	{
		std::cout << "you are a looser." << std::endl;
	}
	else
	{
		std::cout << "drawn game." << std::endl;
	}

	return 0;
}