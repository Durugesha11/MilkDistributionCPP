#include "MilkDistributor.h"

MilkDistributor::MilkDistributor() {}

void MilkDistributor::addCustomer()
{
    std::cout<<"add customer function\n";
    Customer* newCustomer=new Customer;
    m_customerDetails.push_back(newCustomer);

}

void MilkDistributor::addCustomer(std::vector<std::string>& customerData)
{

    Customer* newCustomer=new Customer(customerData[0],customerData[1],customerData[2],customerData);


    m_customerDetails.push_back(newCustomer);



}

void MilkDistributor::displayAllCustomer()
{
    std::cout<<"name phoneNumber houseNumber streetName Area City Pincode, milkOrdered\n";

    for(auto& customer:m_customerDetails)
    {
        customer->display();
        std::cout<<" = "<<customer->milkOrderedQuantity()<<std::endl;
    }
}

int MilkDistributor::CalculateHowMuchMilkRequireToday()
{

    int orderSum{0};
    for(auto& customer:m_customerDetails)
    {
        orderSum+=std::stoi(customer->milkOrderedQuantity());
    }
    return orderSum;
}

int MilkDistributor::getMilkFromHeadDistributors(int milkTotal)
{
    std::cout<<"total milk requested="<<milkTotal<<std::endl;
    m_milkContainer.clear();
    for(int i=0;i<milkTotal;i++)
    {
        Milk* newMilk=new Milk;
        m_milkContainer.push_back(newMilk);

    }
    return m_milkContainer.size();

}

void MilkDistributor::startDistribution()
{
    //this->displayAllCustomer();
    int choose=0;
    int milkQty=0;
    for(auto& Customer:m_customerDetails)
    {
        milkQty=std::stoi(Customer->milkOrderedQuantity());
        if(milkQty==0)
        {
            continue;
        }
        std::cout<<"we are at "<<Customer->name()<<" home address\n";
        std::cout<<"milk qty Req by customer="<<milkQty;
        std::cout<<"  confirm to provide= 1(yes) 0(no), 3(stop Distribution)=";
        std::cin>>choose;

        if(choose==0)
        {
            continue;
        }else if(choose==3)
        {
            std::cout<<"distribution stoped here\n";
            return;
        }
        for(int i=0;i<milkQty;i++)
        {
    Milk* newMilk=m_milkContainer.back();
    m_milkContainer.pop_back();
    Customer->collectMilk(newMilk);
        }
    }



}


int MilkDistributor::getTotalCustomers()
{
    return m_customerDetails.size();
}

std::string MilkDistributor::name() const
{
    return m_name;
}

void MilkDistributor::setName(const std::string &newName)
{
    m_name = newName;
}

long MilkDistributor::phonenumber() const
{
    return m_phonenumber;
}

void MilkDistributor::setPhonenumber(long newPhonenumber)
{
    m_phonenumber = newPhonenumber;
}

std::list<Customer *> MilkDistributor::customerDetails() const
{
    return m_customerDetails;
}

int MilkDistributor::milkBalance() const
{
   return m_milkContainer.size();
}

