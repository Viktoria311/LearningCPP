#include <iostream>

unsigned long long func_fuctorial(int number);

int main()
{
    bool again;
    do
    {
        int number;
        std::cout << "Enter a number for computing it`s fuctorial: ";
        while (!(std::cin >> number))
        {
            std::cin.clear();
        }

        std::cout << "Fuctorial of " << number << " is " << func_fuctorial(number) << std::endl;

        std::cout << "Do you want to compute nummber`s fuctorial again? 1 - yes, 0 - no" << std::endl;
        std::cin >> again;
        std::cin.clear();
        std::cin.ignore(100500, '\n');
    } while (again);

    std::cout << "Bye!" << std::endl;
    return 0;
}

unsigned long long func_fuctorial(int number)
{
    if (number == 0 || number == 1) return 1;
    else {
        unsigned long long result = 1;
        result *= number * func_fuctorial(number - 1);
        return result;
    }

}