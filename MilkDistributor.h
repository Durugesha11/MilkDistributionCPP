#ifndef MILKDISTRIBUTOR_H
#define MILKDISTRIBUTOR_H
#include <iostream>
#include "milk.h"
#include <list>
#include <vector>
#include "customer.h"
class MilkDistributor
{
public:
    MilkDistributor();
    void addCustomer();
    void addCustomer(std::vector<std::string>& customerData);
    void displayAllCustomer();
    int CalculateHowMuchMilkRequireToday();
    int getMilkFromHeadDistributors(int milkTotal);

    void startDistribution();

    Milk& getMilkFromContainer();

    int getTotalCustomers();


    std::string name() const;
    void setName(const std::string &newName);

    long phonenumber() const;
    void setPhonenumber(long newPhonenumber);

    std::list<Customer *> customerDetails() const;
    int milkBalance() const;
private:
    std::string m_name;
    long int m_phonenumber;
    std::vector<Milk*> m_milkContainer;
    std::list<Customer*> m_customerDetails;

};

#endif // MILKDISTRIBUTOR_H
