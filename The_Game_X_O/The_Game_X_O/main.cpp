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
		
		//логика. если пользователь Х. пользователь первый играет. если машина - то машина.
		//проверка на выигрыш
		
		if (player_point == 'X')
		{
			do
			{
				show_field(arr, row, column);
				player_steps(arr, player_point, row, column);
				if (is_there_a_winner(arr, points_for_winning, row, column)) break;
				machine_steps(arr, machine_point, row, column);
			} while (!is_there_a_winner(arr, points_for_winning, row, column) && !is_arr_full(arr, row, column));
		}
		else
		{
			do
			{
				machine_steps(arr, machine_point, row, column);
				show_field(arr, row, column);
				if (is_there_a_winner(arr, points_for_winning, row, column)) break;
				player_steps(arr, player_point, row, column);
			} while (!is_there_a_winner(arr, points_for_winning, row, column) && !is_arr_full(arr, row, column));
		}

		
		show_field(arr, row, column);

		if (is_player_a_winner(arr, player_point, points_for_winning, row, column))
		{
			std::cout << " you are a winner!!! Congratulations!" << std::endl;
		}
		else if(is_player_a_winner(arr, machine_point, points_for_winning, row, column))//если машина победила
		{
			std::cout << "you are a looser." << std::endl;
		}
		else 
		{
			std::cout << "drawn game." << std::endl;
		}
	
		delete_arr(arr, row);
		
	return 0;
}