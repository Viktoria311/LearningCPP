#include <iostream>
#include <string>
#include "cpmv.h"


Cpmv::Cpmv()
{
    std::cout << std::endl << "default constructor" << std::endl;
    pi = new Info;
    pi->qcode = "default";
    pi->zcode = "default";
}

Cpmv::Cpmv(std::string q, std::string z)
{
    std::cout << std::endl << "constructor" << std::endl;
    pi = new Info;
    pi->qcode = q;
    pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv& cp)
{
    std::cout << std::endl << "copy constructor" << std::endl;
    pi  = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv && mv)
{
    std::cout << std::endl << "move constructor" << std::endl;
    pi = mv.pi;
    mv.pi = nullptr;

}

Cpmv::~Cpmv()
{
    std::cout << std::endl << "destructor" << std::endl;
    delete pi;
}

Cpmv & Cpmv::operator=(const Cpmv & cp)
{
    std::cout << std::endl << "copy operator= " << std::endl;
    if(this == &cp)
        return *this;
    delete pi;
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv)
{
    std::cout << std::endl << "move operator= " << std::endl;
    if(this == &mv)
        return *this;
    delete pi;
    pi = mv.pi;
    mv.pi = nullptr;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const
{
    std::cout << std::endl << "operator+ " << std::endl;
    Cpmv concat = Cpmv(this->pi->qcode + obj.pi->qcode, this->pi->zcode + obj.pi->zcode);
    return concat;
}

void Cpmv::Display() const
{
    if(this->pi == nullptr)
        std::cout << "object is empty " << std::endl;
    else
        std::cout << "string 1: " << pi->qcode << ";" << std::endl <<" string 2: " << pi->zcode << ";"<< std::endl;
}
