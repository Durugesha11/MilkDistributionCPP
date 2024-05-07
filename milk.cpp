#include "milk.h"

Milk::Milk() {}

std::string Milk::brandname() const
{
    return m_brandname;
}

void Milk::setBrandname(const std::string &newBrandname)
{
    m_brandname = newBrandname;
}

int Milk::quantity() const
{
    return m_quantity;
}

void Milk::setQuantity(int newQuantity)
{
    m_quantity = newQuantity;
}
