#ifndef PLORG_H_
#define PLORG_H_

#include <string>

class Plorg
{
private:
    std::string name_;
    int CI_;
public:
	Plorg(const std::string name, int CI = 50);
    Plorg();
   ~Plorg(){}
    void ShowName() const;
    void ShowCI() const;
    void ShowPlorg() const;
    void ChangeCI(int index);
};

#endif