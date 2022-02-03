#include <iostream>

int Fill_array(double* arr, const int size);

void Show_array(const double* arr, const int size);

void Reverse_array(double* arr, const int size);

int main()
{
    std::cout << "Welcome to this program!" << std::endl;

    std::cout << "Enter a number, which will be a size of an array: ";

    unsigned int size_of_arr;

    while (!(std::cin >> size_of_arr))
    {
        std::cin.clear();

        std::cout << "Please, enter a number, which will be a size of an array again: ";
    }
   
    double *p_my_arr = new double [size_of_arr];

    int true_size_of_arr = Fill_array(p_my_arr, size_of_arr);

    Show_array(p_my_arr, true_size_of_arr);

    bool reverse;

    std::cout << "Do you want to reverse your array? 1 - yes, 0 - no" << std::endl;

    std::cin.clear();

    std::cin >> reverse;

    if (reverse)
    {
        Reverse_array(p_my_arr, true_size_of_arr);

        Show_array(p_my_arr, true_size_of_arr);
    }
      
    std::cout << "Bye!" << std::endl;

    delete[] p_my_arr;

    return 0;
}

int Fill_array(double* arr, const int size)
{
    std::cout << "Enter not more than " << size << " doubles in your array:" << std::endl;

    int i = 0;

    while (  i < size   &&   std::cin >> *(arr + i)  )   ++i;

    return i;
}
void Show_array(const double* arr, const int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << i+1<< " element: " << *(arr + i) << std::endl;
}
void Reverse_array(double* arr, const int size)
{
    int i; int j;
    for ( i = 0, j = size - 1; i < size/2; ++i, --j)
    {
            double q = *(arr + i);
            *(arr + i) = *(arr + j);
            *(arr + j) = q;
    }
}