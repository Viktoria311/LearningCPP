#pragma once

const int Len = 40;

struct golf
{
	char fullname[Len];
	int handicap;
};

int setgolf(golf& g);

void change_handicap(golf& g, int hc);

void showgolf(const golf& g);

void new_function(golf* gg);

void new_function(golf* gg, int quantity_of_elements);




