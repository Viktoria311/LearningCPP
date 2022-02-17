#ifndef HEADER_H_
#define HEADER_H_

#include <vector>

void choose_a_point(char& customer_point, char& computer_point);

int enter_rows();

int enter_columns();

int enter_quantity_of_points(int rows, int columns);

void init_vec(std::vector<std::vector<char>>& my_vec, int x, int y);

void show_field(std::vector<std::vector<char>>& my_vec, int x, int y);

void player_steps(std::vector<std::vector<char>>& my_vec, char player_point, int rows, int columns);

void machine_steps(std::vector<std::vector<char>>& my_vec, char machine_point, int rows, int columns);

bool is_there_a_winner(std::vector<std::vector<char>>& my_vec, int quantity, int  rows, int columns);

bool is_player_a_winner(std::vector<std::vector<char>>& my_vec, char customer_point, int quantity, int rows, int columns);

bool is_arr_full(std::vector<std::vector<char>>& my_vec, int rows, int columns);


#endif 