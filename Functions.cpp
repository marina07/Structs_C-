#include "Functions.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <locale>

using namespace std;

static string title = { "Ad Description" };
const unsigned int DESCRIPTIONTITLESLENGTH = title.length();


//prints the statistics results
//it's called from inside statisticsPerDay doesn't have to return any variable
void printAdsStatistics(vector<AdShown> const & v)
{
	cout << "\n***********Ads' Statistics***********" << endl;

	cout << left << " Ad_Id " << "|" << setw(13) << " % of Clicks " << "|"
		<< setw(15) << " $ Earned " << "|" << endl;

	for (vector<AdShown>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
	{
		cout << left << setw(7) << it->id_ << "|" << setw(13) << it->clicksPercent_ << "|"
			<< setw(15)<< (it->moneyEarned_) << "|" << endl;
	}

	cout << endl;

}

//computes total of money earned with ads according to the values/clicks/how many times were shown
//and assigns the percentage of clicks and money earned corresponding to each ad
void computeStatisticsPerDay(vector<AdShown>& v)
{
	unsigned int clicksSum(0);
	unsigned int shownSum(0);
	double totalMoneyEarned(0), moneyEarned(0), percentageClicksPerAd(0), clicks(0), shown(0);
	vector<AdShown> newV;

	for (auto &x : v)
	{
		clicksSum += x.timesClicked_;
		shownSum += x.timesShown_;
	}


	for (auto &x : v)
	{
		moneyEarned = x.timesClicked_ * x.value_;
		x.setMoneyEarned(moneyEarned);
		totalMoneyEarned += moneyEarned;
		
		percentageClicksPerAd = static_cast<double>(x.timesClicked_) / (clicksSum);
		percentageClicksPerAd *= 100;
		x.setClicksPercentage(percentageClicksPerAd);
	}

	double totalPercentClicked = static_cast<double>(clicksSum) / (shownSum);
	totalPercentClicked *= 100;

	cout << "\n******Statistical Information********" << endl;

	cout << right << setw(29) << "Total of Ads Shown: " << shownSum << "\n" << setprecision(2)
		<< right << setw(29) << "Percentage of Clicks: " << totalPercentClicked << " %" << "\n"
		<< right << setw(29) << "Total Money Earned: " << "$ " << totalMoneyEarned << "\n"		
		<< right << setw(29) << "Average earned per ad shown: " << "$ " 
		<< static_cast<double>(totalMoneyEarned / shownSum) << endl;
}

//identifies the max size of struct's fields
unsigned int fieldLength(const vector<AdShown>& v, Field f)
{
	switch (f)
	{
		case ID:
		{
			return 1; //id type of char
		}
		case DESCRIPTION:
		{
			unsigned int descriptionLength(0);
			for (vector<AdShown>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
			{
				if (it->description_.length() > descriptionLength)
					descriptionLength = it->description_.length();
			}
			return descriptionLength;
		}
		case VALUE:
		{
			unsigned int size(0);
			for (vector<AdShown>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
			{
				int digits = static_cast<int>(it->value_ * 100);
				string value(to_string(digits));

				if (size < value.length())
					size = value.length() + 1; //add the length with all digits and one dot
			}
			return size;
		}
		case CLICK:
		{
			int size = 0;
			for (vector<AdShown>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
			{
				int hold = it->timesClicked_;
				while (hold > 0)
				{
					hold = hold / 10;
					++size;
				}
			}
			return size;
		}
		case SHOWN:
		{
			int size = 0, temp = 0;
			for (vector<AdShown>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
			{
				int hold = it->timesShown_;
				while (hold > 0)
				{
					hold = hold / 10;
					++temp;
				}
				if (temp > size)
					size = temp;
				temp = 0;
			}
			return size;
		}
		default:
		{
			cout << "Return from fieldLengthField function: field unknown." << endl;
			return 0;
		}
	}
}

//prints a formatted list with the Ads entered by user
void printAds(vector<AdShown> const &v)
{
	unsigned int descriptionMaxSize = fieldLength(v, DESCRIPTION);
	unsigned int valueMaxSize = fieldLength(v, VALUE);
	unsigned int clicksMaxSize = fieldLength(v, CLICK);
	unsigned int shownMaxSize = fieldLength(v, SHOWN);

	if (descriptionMaxSize < DESCRIPTIONTITLESLENGTH)
		descriptionMaxSize = DESCRIPTIONTITLESLENGTH;

	if (valueMaxSize < 10)
		valueMaxSize = 10;

	if (clicksMaxSize < 10)
		clicksMaxSize = 10;

	cout << "\n*************Ads Entered************" << endl;

	cout << left << "Ad_Id " << "|" << setw(descriptionMaxSize + 2) << "Ad Description" << "|"
		<< setw(valueMaxSize + 2) << "Ad Value " << "|" << setw(clicksMaxSize + 2) << "Ad Clicks " << "|"
		<< setw(shownMaxSize + 7) << "Shown" << "|" << endl;

	for (vector<AdShown>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
	{
		cout << left << setw(6) << it->id_ << "|" << setw(descriptionMaxSize + 2) << it->description_
			<< "|" << setw(valueMaxSize + 2) << setprecision(2) << fixed << (it->value_) << "|" << setw(clicksMaxSize + 2)
			<< it->timesClicked_ << "|" << setw(shownMaxSize + 1) << it->timesShown_ << " times" << "|" << "\n";
	}
	cout << endl;
}