#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Header.hpp"

using namespace std;

int main()
{
	cout << "\nWelcome! Struct demonstration - Marina Pereira - 2018"
		<< "\nIn order to compute how much money a website made per day from advertising,"
		<< "\nplease enter the the ad's id, description, value and how many times it was clicked in a given day."
		<< "\nPlease use whitespace between each field above.\n"
		<< "When you're done, press Crtl^Z + Enter to finish your input, so that the program will print the reports.\n";

	string input;
	
	id_t id;
	adDesc_t description;
	adValue_t value;
	clicks_t timesClicked;
	shown_t timesShown;
	vector<AdShown> v;
	while (getline(cin, input))
	{
		istringstream hold(input);
		if (hold)
		{
			hold >> id >> description >> value >> timesClicked >> timesShown;
			AdShown newAd{ id, description, value, timesClicked, timesShown };
			v.push_back(newAd);

		}
		else
		{
			cerr << "Wrong input." << endl;
			return EXIT_FAILURE;
		}
	}

	//print Ads entered
	printAds(v);
	
	//compute clicks, percentage, money earned and print the results
	computeStatisticsPerDay(v);

	//print statistics (money earned, clicks percentage) for each ad
	printAdsStatistics(v);

	cout << "\nEnd of program" << endl;

}