#ifndef HEADER_H_
#define HEADER_H_

#include <vector>
#include <string>

void choose_a_point(char& customer_point, char& computer_point);

int enter_rows();

int enter_columns();

int enter_quantity_of_points(int rows, int columns);

void init_field(std::vector<std::vector<char>>& my_vec, int x, int y);

void init_players(char customer_point, std::string& player_1, std::string& player_2);

void init_settings(int& rows, int& columns, int& quantity, char& customer_point, char& machine_point, std::string& player1, std::string& player2);

void show_field(std::vector<std::vector<char>>& my_vec, int x, int y);

void player_steps(std::vector<std::vector<char>>& my_vec, char player_point, int rows, int columns);

void machine_steps(std::vector<std::vector<char>>& my_vec, char machine_point, int rows, int columns);

void step(std::vector<std::vector<char>>& vec, char point, int field_rows, int field_columns, std::string player);

bool is_there_a_winner(std::vector<std::vector<char>>& my_vec, int quantity, int  rows, int columns);

bool is_player_a_winner(std::vector<std::vector<char>>& my_vec, char customer_point, int quantity, int rows, int columns);

bool is_field_full(std::vector<std::vector<char>>& my_vec, int rows, int columns);

bool is_it_the_end(std::vector<std::vector<char>>& my_vec, int quantity, int  rows, int columns);

void game(std::vector<std::vector<char>>& my_field, int win_quantity, int field_rows, int field_columns, std::string player1, std::string player2);

void show_the_results(std::vector<std::vector<char>>& my_vec, char player_p, char machine_p, int quantity, int  rows, int columns);

#endif 