#include "Check.h"

Check::Check() :amount(DEFAULT_VALUE), code(), buyerIndex(NOT_FOUND)
{ 
}

Check::Check(double _amount, const String& _code, int _buyerIndex)
	: amount(_amount), code(_code), buyerIndex(_buyerIndex)
{
}

const double Check::getAmount() const
{
	return this->amount;
}

const String& Check::getCode() const
{
	return this->code;
}

const int Check::getBuyerIndex() const
{
	return this->buyerIndex;
}
