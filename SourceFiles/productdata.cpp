#include "../HeaderFiles/productdata.hpp"

ostream& operator<<(ostream &lhs, ProductData &rhs)
{
    lhs << "Uniqe ID: " << rhs.get_uniqid() << " Product Name: " << rhs.get_productname();
    return lhs;
}