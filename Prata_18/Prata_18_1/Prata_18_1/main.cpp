#include <iostream>
#include <initializer_list>

template<typename T>
T average_list(std::initializer_list<T> q);


int main()
{
    auto q = average_list({15.4, 10.7, 9.0});
    std::cout << q << std::endl;
    std::cout << average_list({20,30,19,17,45,38}) << std::endl;

    auto ad = average_list<double>({'A', 70, 65.33});
    std::cout << ad << std::endl;

    return 0;
}

template<typename T>
T average_list(std::initializer_list<T> q)
{
    T  average;
    average =  *(q.begin());

    auto it = q.begin();

    ++it;

    for(; it != q.end(); ++it)
        average += *it;

    return average;
}
