#include "System.h"

bool System::isProductIndexValid(int index) const
{
    return (index > DEFAULT_VALUE && index <= this->products.size());
}

int System::findIndexOfProductByName(const String& productName) const
{
	for (int i = 0; i < this->products.size(); i++) {
        if (this->products[i].getProductName() == productName)
            return i;
	}

    return NOT_FOUND;
}

int System::findIndexOfProductByID(int productID) const
{
    for (int i = 0; i < this->products.size(); i++) {
        if (this->products[i].getProductID() == productID)
            return i;
    }

    return NOT_FOUND;
}

int System::findIndexOfBuyerByEGN(const String & buyerEGN) const
{
    for (int i = 0; i < this->buyers.size(); i++) {
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

void System::save()
{
    ofstream file("BackupFile.txt");
    if (!file.is_open()) {
        cout << "Failed to open file!" << endl;
        return;
    }

    this->admin.save(file);
    this->seller.save(file);
    this->buyers.save(file);
    this->products.save(file);
    this->transactions.save(file);

    this->allEGNs.save(file);
    this->allNames.save(file);

    file << this->adminSignedUp << endl;
    file << this->sellerSignedUp << endl;
    this->adminsRegistrations.save(file);
    this->sellersRegistrations.save(file);

    file.close();
}

void System::load()
{
    ifstream file("BackupFile.txt");
    if (!file.is_open()) {
        ofstream file("BackupFile.txt", ios::ate);
        file.close();
        return;
    }

    this->admin.load(file);
    this->seller.load(file);
    this->buyers.load(file);
    this->products.load(file);
    this->transactions.load(file);

    this->allEGNs.load(file);
    this->allNames.load(file);

    file >> this->adminSignedUp;
    file >> this->sellerSignedUp;
    this->adminsRegistrations.load(file);
    this->sellersRegistrations.load(file);

    file.close();
}
