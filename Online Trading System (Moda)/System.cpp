#include "System.h"

bool System::isProductIndexValid(int index) const
{
    return (index > DEFAULT_VALUE && index <= this->products.size());
}

int System::findIndexOfProductByName(const String& productName) const
{
	for (size_t i = 0; i < this->products.size(); i++) {
        if (this->products[i].getProductName() == productName)
            return i;
	}

    return NOT_FOUND;
}

int System::findIndexOfProductByID(int productID) const
{
    for (size_t i = 0; i < this->products.size(); i++) {
        if (this->products[i].getProductID() == productID)
            return i;
    }

    return NOT_FOUND;
}

int System::findIndexOfBuyerByEGN(const String & buyerEGN) const
{
    for (size_t i = 0; i < this->buyers.size(); i++) {
        if (this->buyers[i].getEGN() == buyerEGN)
            return i;
    }

    return NOT_FOUND;
}

//int System::findIndexOfBuyerByID(int buyerID) const
//{
//    for (size_t i = 0; i < this->buyers.size(); i++) {
//        if (this->buyers[i].get() == buyerEGN)
//            return i;
//    }
//
//    return NOT_FOUND;
//}

System& System::getInstance()
{
    static System system;
    return system;
}
