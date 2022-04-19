#include <iostream>
#include "my_classes.h"


int main() 
{
    Tv my_tv;
    Remote my_remote;
    int num;
    bool want;

    my_remote.onoff_tv(my_tv);
    my_tv.settings();

    std::cout << "Enter a number of channel: ";
    while (!(std::cin >> num))
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Try again to enter a number of channel: ";
    }
    my_remote.set_chan(my_tv, num);

    std::cout << "Do you want to change input of tv? 1 - yes, 0 - no  : ";
    std::cin >> want;
    std::cin.ignore(100, '\n');
    if (want)
        my_remote.set_input(my_tv);
    my_tv.settings();
    std::cout << "Do you want to Vol up? 1 - yes, 0 - no  : ";
    std::cin >> want;
    std::cin.ignore(100, '\n');
    if (want)
        my_remote.volup(my_tv);
    else my_remote.voldown(my_tv);

    my_tv.settings();
    my_remote.onoff_tv(my_tv);

    return 0;
}

