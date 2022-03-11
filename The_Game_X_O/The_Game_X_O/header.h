#ifndef HEADER_H_
#define HEADER_H_

void choose_a_point(char& customer_point, char& computer_point);
int enter_rows();
int enter_columns();
int enter_quantity_of_points(int rows, int columns);
void init_arr(char** my_arr, int x, int y);
void show_field(char** my_arr, int x, int y);////
char** create_arr(int rows, int columns);
void delete_arr(char** my_arr, int n);
void player_steps(char** my_arr, char player_point_, int rows, int columns);
void machine_steps(char** my_arr, char machine_point_, int rows, int columns);
bool is_there_a_winner(char** my_arr, int quantity, int  rows, int columns);////
bool is_player_a_winner(char** my_arr, char customer_point, int quantity, int rows, int columns);
bool is_arr_full(char** my_arr, int rows, int columns);
void game(char** my_arr_, int rows_, int columns_, int quantity_, char player_point_, char machine_point_);
void show_results(char** my_arr, int rows, int columns, int quantity, char player_point_, char machine_point_);

#endif 

