#include "address.h"

Address::Address() {
    m_gcsCoordinates=nullptr;
    init();

}

Address::Address(std::string a_houseNumber, std::string streetName, std::string city, std::string pincode)
{


    m_houseNumber=a_houseNumber;
    m_streetName=streetName;
    m_city=city;
    m_pincode=pincode;


}

void Address::init()
{
    std::cout<<"enter house number=";
    std::cin.sync();
    std::cin>>m_houseNumber;
    std::cout<<"enter street name=";
    std::cin.sync();
    std::cin.ignore();
    std::getline(std::cin,m_streetName);
    std::cout<<"enter city Name=";
    std::cin.sync();
    std::getline(std::cin,m_city);
    std::cout<<"enter the pincode=";
    std::cin>>m_pincode;
}



std::string Address::houseNumber() const
{
    return m_houseNumber;
}

void Address::setHouseNumber(int newHouseNumber)
{
    m_houseNumber = newHouseNumber;
}

std::string Address::streetName() const
{
    return m_streetName;
}

void Address::setStreetName(const std::string &newStreetName)
{
    m_streetName = newStreetName;
}




std::string Address::city() const
{
    return m_city;
}

void Address::setCity(const std::string &newCity)
{
    m_city = newCity;
}

std::string Address::pincode() const
{
    return m_pincode;
}

void Address::setPincode(std::string newPincode)
{
    m_pincode = newPincode;
}

void Address::displayHouseDetails()
{
    std::cout<<" "<<m_houseNumber<<" "<<m_streetName<<" "<<m_city<<" "<<m_pincode;

}
