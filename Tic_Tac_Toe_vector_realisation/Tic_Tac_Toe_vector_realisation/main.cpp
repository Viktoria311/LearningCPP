#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include "header.h"

int main()
{
	char player_point;

	char machine_point;

	int points_for_winning;

	int row;

	int column;

	std::string player_1;

	std::string player_2;

	init_settings(row, column, enter_rows, enter_columns, points_for_winning, enter_quantity_of_points,
				  player_point, machine_point, choose_a_point, player_1, player_2, init_players);

	std::vector<std::vector<char>> field(row, std::vector<char>(column));

	init_field(field, row, column);

	game(field, points_for_winning, row, column, show_field, player_1, player_2, player_steps, machine_steps,
		 step, is_there_a_winner, is_it_the_end, is_field_full);

	show_field(field, row, column);

	show_the_results(field, player_point, machine_point, points_for_winning, row, column, is_player_a_winner);

	return 0;
}