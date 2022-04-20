#include <iostream>
#include "my_exept.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        try
        {               
            z = hmean(x, y);
            std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
            std::cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << std::endl;
            std::cout << "Enter next set of numbers <q to quit>: ";
        }
        catch (bad_mean& hg)
        {
            hg.mess();
            std::cout << "Sorry, you don't get to play any more.\n";
            break;
        } 
    }

    std::cout << "Bye!\n";
   
    return 0;
}

