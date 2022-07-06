#include <iostream>
#include <string>
#include "cpmv.h"

int main()
{
    Cpmv first("vnn", "hdhh");
    first.Display();

    Cpmv second = first;
    second.Display();

    Cpmv third;
    third.Display();

    Cpmv fouth = std::move(second);
    second.Display();
    fouth.Display();

    Cpmv fifth = first + third;
    fifth.Display();



    return 0;
}
