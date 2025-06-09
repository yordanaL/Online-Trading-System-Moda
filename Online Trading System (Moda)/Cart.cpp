#include "Cart.h"

const Vector<Pair<int, int>> Cart::getProducts() const
{
    return this->products;
}

const double Cart::getPriceBeforeDiscount() const
{
    return this->priceBeforeDiscount;
}

const double Cart::getPriceAfterDiscount() const
{
    return this->priceAfterDiscount;
}

bool Cart::getDiscountUsed() const
{
    return this->discountUsed;
}

void Cart::cleanCart()
{
    this->products.clear();
    this->priceBeforeDiscount = DEFAULT_VALUE;
    this->priceAfterDiscount = DEFAULT_VALUE;
    this->discountUsed = false;
}
