#ifndef STORE_H
#define STORE_H

#include <fstream>
#include <string>

class Store
{
private:
    std::ofstream& s;
public:
    Store(std::ofstream& stream);
    void operator()(const std::string& s);

};

#endif // STORE_H
