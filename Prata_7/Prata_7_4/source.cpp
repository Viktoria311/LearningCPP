#include <iostream>

long double probability(int numbers, int picks)
{
long double result = 1.0;
int n; int p;
for(n = numbers, p = picks; p > 0; --n, --p)
     result = result * n / p;
return result;
}

int main() {
  int total1;
  int choices1;
  int total2;
  int choices2;
  bool again;

do
{
  std::cout << "Computing the probability of winning in the lottery" << std::endl;
std::cout << "Enter the total number of choices on the first part of the lottery: ";
  while(!(std::cin >> total1)) std::cin.clear();
  std::cin.clear();
  std::cout << "Enter the number of picks allowed on the first part of the lottery: ";
  while(!(std::cin >> choices1)) std::cin.clear();
  std::cin.clear();

   std::cout << "Enter the total number of choices on the second part of the lottery: ";
  while(!(std::cin >> total2)) std::cin.clear();
  std::cin.clear();
  std::cout << "Enter the number of picks allowed on the first part of the lottery: ";
  while(!(std::cin >> choices2)) std::cin.clear();
  std::cin.clear();

  std::cout << "You have one chance in " << probability(total1, choices1) * probability(total2, choices2) << std::endl;

  std::cout << "Do you want to compute probability again? 1 - yes, 0 - no" << std::endl;
  std::cin >> again;
} while(again);

std::cout << "Bye";

  return 0;
}
