#include <iostream>
#include <cctype>
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

	char** arr = create_arr(row, column);
	
	init_arr(arr, row, column);
		
	game(arr, row, column, points_for_winning, player_point, machine_point);
		
	show_field(arr, row, column);

	show_results(arr, row, column, points_for_winning, player_point, machine_point);

	delete_arr(arr, row);
		
	return 0;
}