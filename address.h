#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
#include "gcs.h"
class Address
{
public:
    Address();
    Address(std::string a_houseNumber,std::string streetNum,std::string city,std::string pincode);
    void init();

    std::string houseNumber() const;
    void setHouseNumber(int newHouseNumber);

    std::string streetName() const;
    void setStreetName(const std::string &newStreetName);


    std::string city() const;
    void setCity(const std::string &newCity);

    std::string pincode() const;
    void setPincode(std::string newPincode);

    void displayHouseDetails();
private:
    std::string m_houseNumber;
    std::string m_streetName;

    std::string m_city;
    std::string m_pincode;
    GCS* m_gcsCoordinates;
};

#endif // ADDRESS_H
