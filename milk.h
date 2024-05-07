#ifndef MILK_H
#define MILK_H
#include <iostream>
class Milk
{
public:
    Milk();

    std::string brandname() const;
    void setBrandname(const std::string &newBrandname);

    int quantity() const;
    void setQuantity(int newQuantity);
    void setMilkInformation();

private:
    std::string m_brandname;
    int m_quantity;
    int milkPrice;
    int m_milkId;

};

#endif // MILK_H
