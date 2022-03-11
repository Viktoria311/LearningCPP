#include <iostream>
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

	init_settings(row, column, points_for_winning, player_point, machine_point, player_1, player_2);

	std::vector<std::vector<char>> field(row, std::vector<char>(column));

	init_field(field, row, column);

	game(field, points_for_winning, row, column, player_1, player_2);

	show_the_results(field, player_point, machine_point, points_for_winning, row, column);

	return 0;
}