#pragma once

const int Len = 40;

struct golf
{
	char fullname[Len];
	int handicap;
};

//void setgolf(golf& g, const char* name, int hc);

int setgolf(golf& g);

void change_handicap(golf& g, int hc);

void showgolf(const golf& g);

void new_function(golf* gg, void (*func1)(golf&, int), void (*func2)(const golf&));

void new_function(golf* gg, void (*func1)(golf&, int), void (*func2)(const golf&), int quantity_of_elements);




