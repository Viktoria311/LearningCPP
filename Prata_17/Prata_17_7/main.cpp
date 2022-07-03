#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "funcs.h"
#include "store.h"



int main()
{
    std::vector<std::string> vostr;
    std::string temp;


    std::cout << "Enter strings (empty line to quit):" << std::endl;
    while(std::getline(std::cin, temp)  && temp[0] != '\0')
        vostr.push_back(temp);
    std::cout << "Here is your input." << std::endl;
    std::for_each(vostr.begin(), vostr.end(), ShowStr);


    std::ofstream fout("strings.dat", std::ios_base::out | std::ios_base::binary);
    Store  store(fout);
    std::for_each(vostr.begin(), vostr.end(), store);
    fout.close();

    std::vector<std::string> vistr;
    std::ifstream fin("strings.dat", std::ios_base::in | std::ios_base::binary);
    if(!fin.is_open())
    {
        std::cerr << "Could not open file for input." << std::endl;
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    std::cout << "Here are the strings read fron the file:" << std::endl;
    std::for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}
