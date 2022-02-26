#ifndef HEADER_H_
#define HEADER_H_

#include <vector>

typedef void (*step_t)(std::vector<std::vector<char>>&, char, int, int);
typedef bool (*is_there_a_winner_t)(std::vector<std::vector<char>>&, int, int, int);
typedef bool (*is_field_full_t)(std::vector<std::vector<char>>&, int r, int);
typedef bool (*is_player_a_winner_t)(std::vector<std::vector<char>>&, char, int, int, int);

void choose_a_point(char& customer_point, char& computer_point);

int enter_rows();

int enter_columns();

int enter_quantity_of_points(int rows, int columns);

void init_field(std::vector<std::vector<char>>& my_vec, int x, int y);

void show_field(std::vector<std::vector<char>>& my_vec, int x, int y);

void player_steps(std::vector<std::vector<char>>& my_vec, char player_point, int rows, int columns);

void machine_steps(std::vector<std::vector<char>>& my_vec, char machine_point, int rows, int columns);

void step(std::vector<std::vector<char>>& my_vec, char player_point, int number_in_the_queue, int rows, int columns, step_t step_player, step_t step_machine);

bool is_there_a_winner(std::vector<std::vector<char>>& my_vec, int quantity, int  rows, int columns);

bool is_player_a_winner(std::vector<std::vector<char>>& my_vec, char customer_point, int quantity, int rows, int columns);

bool is_field_full(std::vector<std::vector<char>>& my_vec, int rows, int columns);

bool is_it_the_end(std::vector<std::vector<char>>& my_vec, int quantity, int  rows, int columns, is_there_a_winner_t f_is_there_a_winner, is_field_full_t f_is_field_full);

void show_the_results(std::vector<std::vector<char>>& my_vec, char player_p, char machine_p, int quantity, int  rows, int columns, is_player_a_winner_t f_is_player_a_winner);

#endif 