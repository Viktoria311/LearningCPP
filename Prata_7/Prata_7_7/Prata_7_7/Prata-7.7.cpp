#include <iostream>

const int MAX = 5;

double* fill_array(double ar[], const int limit);

void show_array(const double ar[], const double* const p);

void revalue(double r, double ar[], const double* const p);

int main()
{
    double properties[MAX];

    const double* p_end_of_ar = fill_array(properties, MAX);

    show_array(properties, p_end_of_ar);

    if (properties != p_end_of_ar)
    {
        std::cout << "Enter revaluation factor: ";

        double factor;

        while (  !(std::cin >> factor) )
        {
            std::cin.clear();

            while( std::cin.get() != '\n' ) continue;

            std::cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, p_end_of_ar);

        show_array(properties, p_end_of_ar);
    }

    std::cin.clear();

    std::cout << "Done.\n";

    return 0;
}

double* fill_array(double ar[], const int limit)
{
    double temp;
    int i = 0;
    for (; i < limit; ++i)
    {
        std::cout << "Enter value #" << (i + 1) << ": ";
        std::cin >> temp;
        if (!std::cin)
        {
            std::cin.clear(); 
            while (std::cin.get() != '\n') continue;
            std::cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0) break;
        ar[i] = temp;
    }
    return ar + i;
}
void show_array(const double ar[], const double* const p)
{
    for (int i = 0;  (ar + i) != p;   ++i)
    {
        std::cout << "Property #" << (i + 1) << ": $";
        std::cout << ar[i] << std::endl;
    }
}
void revalue(double r, double ar[], const double* const p)
{
    for (int i = 0;   (ar + i) != p;   ++i)
        ar[i] *= r;
}