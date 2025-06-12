#include "Cart.h"
#include "System.h"

bool Cart::isCartEmpty() const
{
    return (this->products.size() == DEFAULT_VALUE);
}

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

void Cart::viewCart(const System& system) const
{
    if (isCartEmpty() == true) {
        cout << "Your cart is empty!" << endl;
        return;
    }

    cout << "Items in cart: " << endl;

    for (size_t i = 0; i < this->products.size(); i++) {
        cout << (i + INDEX_FIX) << ". ";
        cout << this->products[i].getValue() << "x ";
        cout << system.getProductNameByID(system, this->products[i].getKey());
        cout << " - ";
        cout << this->products[i].getValue() * system.getProductPriceByID(system, this->products[i].getKey());
        cout << " BGN" << endl;
    }

    if (this->discountUsed == true) {
        cout << "Total price before discount: " << this->priceBeforeDiscount << " BGN" << endl;
        cout << "Total price after discount: " << this->priceAfterDiscount << " BGN" << endl;
    }
    else {
        cout << "Total Price: " << this->priceBeforeDiscount << " BGN" << endl;
    }
}

void Cart::addProduct(int productID, int quantity)
{
    for (size_t i = 0; i < this->products.size(); i++) {
        if (this->products[i].getKey() == productID) {
            this->products[i].increaseValue(quantity);
            return;
        }
    }

    Pair<int, int> newProduct(productID, quantity);
    this->products.pushBack(newProduct);
}

int Cart::checkProductQuantityInCart(int productID)
{
    for (size_t i = 0; i < this->products.size(); i++) {
        if (this->products[i].getKey() == productID) {
            return this->products[i].getValue();
        }
    }

    return DEFAULT_VALUE;
}

void Cart::removeProduct(int productID, int quantity)
{
    int productIndex = NOT_FOUND;
    for (size_t i = 0; i < this->products.size(); i++) {
        if (this->products[i].getKey() == productID) {
            this->products[i].decreaseValue(quantity);
            productIndex = i;
            break;
        }
    }

    if (productIndex == NOT_FOUND) {
        cout << "Could not find product with this ID in you cart!" << endl;
        return;
    }

    if (this->products[productIndex].getValue() <= DEFAULT_VALUE)
        this->products.erase(productIndex);
}

void Cart::applyDiscount(int loyaltyPoints)
{
}

void Cart::cleanCart()
{
    this->products.clear();
    this->priceBeforeDiscount = DEFAULT_VALUE;
    this->priceAfterDiscount = DEFAULT_VALUE;
    this->discountUsed = false;
}
