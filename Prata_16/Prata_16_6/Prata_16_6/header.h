#ifndef HEADER_H_
#define HEADER_H_


class Customer
{
private:
    long arrive;        // arrival time for customer
    int processtime;    // processing time for customer
public:
    Customer() : arrive(0), processtime(0) {}
    void set(long when)
    {
        processtime = std::rand() % 3 + 1;
        arrive = when;
    }
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};



#endif
