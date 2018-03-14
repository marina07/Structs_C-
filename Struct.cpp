#include "Struct.hpp"

//member function which sets the click rate per Ad
void AdShown::setClicksPercentage(const double &p)
{
	this->clicksPercent_ = p;
}

//member function which sets the total earnings per Ad
void AdShown::setMoneyEarned(const double &m)
{
	this->moneyEarned_ = m;
}

