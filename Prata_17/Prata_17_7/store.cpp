#include <fstream>
#include "store.h"

Store::Store(std::ofstream& stream) : s(stream)
{

}

void Store::operator()(const std::string& str)
{
    int size = str.length();
    s.write(reinterpret_cast<char*>(&size), sizeof(str.length()));
    //s.write(reinterpret_cast<char*>(&(str.length())), sizeof(str.length()));
    s.write(str.data(), str.length());
}
