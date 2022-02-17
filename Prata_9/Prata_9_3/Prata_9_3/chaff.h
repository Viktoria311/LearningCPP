#ifndef CHAFF_H_
#define CHAFF_H_

const int LEN = 20;

const int quantity = 4;

struct chaff
{
	char dross[LEN];
	int slag;
};

void complete_arr_of_struct(chaff* p, int n);
void show_arr_of_struct(const chaff* p, int n);

#endif
