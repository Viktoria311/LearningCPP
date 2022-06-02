#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<int> Lotto(int count_of_all, int count_of_numbers);

int main()
{

	std::vector<int> winners = Lotto(51, 6);

	std::ostream_iterator<int, char> cout_iter(std::cout, " ");

	std::copy(winners.begin(), winners.end(), cout_iter);


	return 0;
}

std::vector<int> Lotto(int count_of_all, int count_of_numbers)
{
	std::vector<int> lotto;

	for (int i = 1; i <= count_of_all; ++i)
	{
		lotto.push_back(i);
	}

	std::random_shuffle(lotto.begin(), lotto.end());

	decltype(lotto.begin()) iter;

	if (count_of_numbers < count_of_all / 2)
	{
		iter = lotto.begin();
		for (int i = 0; i <= count_of_numbers; ++i)
			++iter;
	}
	else
	{
		iter = lotto.end();
		for (int i = count_of_all; i > count_of_numbers; --i)
			--iter;
	}

	lotto.erase(iter, lotto.end());
	std::sort(lotto.begin(), lotto.end());

	return lotto;
}