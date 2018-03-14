#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Header.hpp"
#include <vector>

//prints a formatted list with the Ads entered by user
void printAds(vector<AdShown> const &v);

//computes total of money earned with ads according to the values/clicks/how many times were shown
//and assigns the percentage of clicks and money earned corresponding to each ad
void computeStatisticsPerDay(vector<AdShown> & v);

//prints the statistics results
//it's called from inside statisticsPerDay doesn't have to return any variable
void printAdsStatistics(vector<AdShown> const & v);

#endif

