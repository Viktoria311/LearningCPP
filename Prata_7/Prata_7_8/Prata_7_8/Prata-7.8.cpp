#include <iostream>

const int Seasons = 4;
const char* ar[Seasons] = { "spring", "summer", "fall", "winter" };

void fill(double* p, const int size);
void show(const double* p, const int size);

int main()
{
    double my_ar[Seasons];

    fill(my_ar, Seasons);

    show(my_ar, Seasons);
   
    return 0;
}

void fill(double* p, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Enter " << *(ar + i) << " expenses: ";

        while ( !(std::cin >> *(p + i) )  )
        {
            std::cin.clear();

            std::cin.ignore(100, '\n');

            std::cout << " error input. enter " << *(ar + i) << " expenses again: ";
        }
    }
}
void show(const double* p, const int size)
{
    double total = 0.0;

    for (int i = 0; i < size; ++i)
    {
        std::cout << ar[i] << ": $" << *(p + i) << std::endl;

        total += *(p + i);
    }
    std::cout << "Total Expenses: $" << total << std::endl;
}
