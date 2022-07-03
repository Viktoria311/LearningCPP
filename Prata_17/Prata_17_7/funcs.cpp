#include <iostream>
#include "funcs.h"

void ShowStr(const std::string& s)
{
    std::cout << s << std::endl;
}

void GetStrs(std::ifstream& stream, std::vector<std::string>& vec)
{
    //char len;
    int len;
    std::string some_str;

   while(stream.read(reinterpret_cast<char*>(&len), sizeof(len)))
   {
       for(int i = 0; i < len; ++i)
           stream.read(&some_str[i], sizeof(len));

       vec.push_back(some_str);
   }

}
