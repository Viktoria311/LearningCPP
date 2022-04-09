#ifndef MY_TEMPLATES_
#define MY_TEMPLATES_

#include <valarray>

template <typename T1, typename T2>
class Pair
{
private:
	T1 years_;
	T2 bottles_;
public:
	Pair(const T1& years, const T2& bottles) : years_(years), bottles_(bottles) { }
	Pair();
	T1& years();
	T2& bottles();
	T1 years() const { return years_; }
	T2 bottles() const { return bottles_; }
};

template <typename T1, typename T2>
T1& Pair<T1, T2>::years()
{
	return years_;
}

template <typename T1, typename T2>
T2& Pair<T1, T2>::bottles()
{
	return bottles_;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<> class Pair<std::valarray<int>, std::valarray<int>>
{
private:
	std::valarray<int> years_;
	std::valarray<int> bottles_;
public:
	Pair(int q, const int* years, const int* bottles) : years_(years, q), bottles_(bottles, q) { }
	Pair(int q = 0) : years_(q), bottles_(q) { }
	std::valarray<int>& years();
	std::valarray<int>& bottles();
	const std::valarray<int>& years() const { return years_; }
	const std::valarray<int>& bottles() const { return bottles_; }
};

std::valarray<int>& Pair<std::valarray<int>, std::valarray<int>>::years()
{
	return years_;
}

std::valarray<int>& Pair<std::valarray<int>, std::valarray<int>>::bottles()
{
	return bottles_;
}

#endif