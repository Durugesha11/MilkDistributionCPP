#include "customer.h"

Customer::Customer() {
    init();
}

Customer::Customer(std::string name, std::string phoneNumber, std::string milkqty, std::vector<std::string> customerData)
{

    m_name=name;
    m_phoneNumber=phoneNumber;

    m_milkorderperDay=milkqty;
    m_address=new Address(customerData[3],customerData[4],customerData[5],customerData[6]);

}

Customer::~Customer()
{
    if(m_address!=nullptr)
    {
        delete m_address;
    }
    for(auto milkobj:m_milkcontainer)
    {
        if(milkobj)
        {
            delete milkobj;
        }
    }
}

void Customer::init()
{

    std::cout<<"enter the customer name=";
    std::cin.ignore();
    std::getline(std::cin,m_name);
    std::cout<<"enter phone number=";
    std::cin>>m_phoneNumber;
    std::cout<<"how much milk needed per day=";
    std::cin>>m_milkorderperDay;
    m_address=new Address;


}

void Customer::collectMilk(Milk* newMilk)
{
    m_milkcontainer.push_back(newMilk);
    std::cout<<"milk received by "<<m_name<<std::endl;
}


void Customer::display()
{
    std::cout<<m_name<<" ,"<<m_phoneNumber;
    m_address->displayHouseDetails();

}

std::string Customer::milkOrderedQuantity() const
{
    return m_milkorderperDay;
}

std::string Customer::name() const
{
    return m_name;
}

std::string Customer::phoneNumber() const
{
    return m_phoneNumber;
}

Address *Customer::address() const
{
    return m_address;
}
