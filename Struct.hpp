#ifndef STRUCT_H
#define STRUCT_H

#include <string>


typedef double percentage_t;
typedef char id_t;
typedef int clicks_t;
typedef int shown_t;
using clicks_t = int;
using adDesc_t = std::string;
using adValue_t = double;

using namespace std;

struct AdShown {
	id_t id_;
	adDesc_t description_;
	adValue_t value_;
	clicks_t timesClicked_;
	shown_t timesShown_;
	double clicksPercent_ = 0;
	double moneyEarned_ = 0;

	void setClicksPercentage(const double &p);
	void setMoneyEarned(const double &m);
};

#endif
