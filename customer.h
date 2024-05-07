#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>
#include "milk.h"
#include "address.h"

class Customer
{
public:
    Customer();
    Customer(std::string name,std::string phoneNumber,std::string milkqty,std::vector<std::string> customerData);
    ~Customer();
    void init();

    void collectMilk(Milk*);

    void payBill();
    void setMilkOrderedQuantity();
    void addAddresss();
    void display();
    std::string milkOrderedQuantity()const;



    std::string name() const;

    std::string phoneNumber() const;

    Address *address() const;

private:
    std::string m_name;
    std::string m_phoneNumber;
    std::string m_milkorderperDay;
    Address* m_address;
    std::vector<Milk*> m_milkcontainer;

};

#endif // CUSTOMER_H
