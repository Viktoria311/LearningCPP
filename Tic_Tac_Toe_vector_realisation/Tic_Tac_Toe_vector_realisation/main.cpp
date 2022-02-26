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

	std::vector<std::vector<char>> field(row, std::vector<char>(column));

	init_field(field, row, column);

	do
	{
		show_field(field, row, column);
		step(field, player_point, 1, row, column, player_steps, machine_steps);
		if (is_there_a_winner(field, points_for_winning, row, column)) break;
		step(field, player_point, 2, row, column, player_steps, machine_steps);
	} while (!is_it_the_end(field, points_for_winning, row, column, is_there_a_winner, is_field_full));

	show_field(field, row, column);

	show_the_results(field, player_point, machine_point, points_for_winning, row, column, is_player_a_winner);

	return 0;
}