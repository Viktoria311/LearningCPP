#ifndef HEADER_H_
#define HEADER_H_

#include <vector>
#include <string>

typedef int (*enter_quantity_of_field_parameter_t)();
typedef int (*enter_quantity_of_points_t)(int, int);
typedef void (*choose_a_point_t)(char&, char&);
typedef void (*init_players_t)(char, std::string&, std::string&);
typedef void (*show_field_t)(std::vector<std::vector<char>>&, int x, int y);
typedef void (*step_t)(std::vector<std::vector<char>>&, char, int, int);
typedef void (*common_step_t)(std::vector<std::vector<char>>&, char, int, int, std::string, step_t, step_t);
typedef bool (*is_there_a_winner_t)(std::vector<std::vector<char>>&, int, int, int);
typedef bool (*is_field_full_t)(std::vector<std::vector<char>>&, int r, int);
typedef bool (*is_field_full_t)(std::vector<std::vector<char>>&, int, int);
typedef bool (*is_it_the_end_t)(std::vector<std::vector<char>>&, int, int, int, is_there_a_winner_t, is_field_full_t);
typedef bool (*is_player_a_winner_t)(std::vector<std::vector<char>>&, char, int, int, int);

void choose_a_point(char& customer_point, char& computer_point);

int enter_rows();

int enter_columns();

int enter_quantity_of_points(int rows, int columns);

void init_field(std::vector<std::vector<char>>& my_vec, int x, int y);

void init_players(char customer_point, std::string& player_1, std::string& player_2);

void init_settings(int& rows, int& columns, enter_quantity_of_field_parameter_t f_enter_rows, enter_quantity_of_field_parameter_t f_enter_columns,
					int& quantity, enter_quantity_of_points_t f_enter_quantity_of_points,
					char& customer_point, char& machine_point, choose_a_point_t f_choose_a_point,
					std::string& player1, std::string& player2, init_players_t f_init_players);

void show_field(std::vector<std::vector<char>>& my_vec, int x, int y);

void player_steps(std::vector<std::vector<char>>& my_vec, char player_point, int rows, int columns);

void machine_steps(std::vector<std::vector<char>>& my_vec, char machine_point, int rows, int columns);

void step(std::vector<std::vector<char>>& vec, char point, int field_rows, int field_columns, std::string player, step_t step_player, step_t step_machine);

bool is_there_a_winner(std::vector<std::vector<char>>& my_vec, int quantity, int  rows, int columns);

bool is_player_a_winner(std::vector<std::vector<char>>& my_vec, char customer_point, int quantity, int rows, int columns);

bool is_field_full(std::vector<std::vector<char>>& my_vec, int rows, int columns);

bool is_it_the_end(std::vector<std::vector<char>>& my_vec, int quantity, int  rows, int columns, is_there_a_winner_t f_is_there_a_winner, is_field_full_t f_is_field_full);

void game(std::vector<std::vector<char>>& my_field, int win_quantity, int  field_rows, int field_columns,
			show_field_t f_show_field, std::string player1, std::string player2, step_t player_step, step_t machine_step,
			common_step_t f_common_step, is_there_a_winner_t f_is_there_a_winner, is_it_the_end_t f_is_it_the_end,
			is_field_full_t f_is_field_full);

void show_the_results(std::vector<std::vector<char>>& my_vec, char player_p, char machine_p, int quantity, int  rows, int columns, is_player_a_winner_t f_is_player_a_winner);

#endif 