#include <iostream>
#include <cctype>

void choose_a_point(char& customer_point, char& computer_point);
int enter_rows();
int enter_columns();
int enter_quantity_of_points(int rows, int columns);
void init_arr(char** my_arr, int x, int y);
void show_field(char** my_arr, int x, int y);////
char** create_arr(int rows, int columns);
void delete_arr(char** my_arr, int n);
void player_steps(char** my_arr, char player_point, int rows, int columns);
void machine_steps(char** my_arr, char machine_point, int rows, int columns);
bool is_there_a_winner(char** my_arr, int quantity, int  rows, int columns);////
bool is_player_a_winner(char** my_arr, char customer_point, int quantity, int rows, int columns);////
bool is_arr_full(char** my_arr, int rows, int columns);////

int main()
{
	char player_point;

	char machine_point;

	int points_for_winning;

	int row = enter_rows();

	int column = enter_columns();

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
		else if (is_arr_full(arr, row, column))
		{
			std::cout << "drawn game." << std::endl;
		}
	
		delete_arr(arr, row);
		
	return 0;
}