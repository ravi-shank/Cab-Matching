#pragma once
#include<list>
#include<map>
#include"Rider.h"
#include "Driver.h"

class Matcher
{
	
	std::map<std::string, Rider>mpOfRiders;
	std::map<std::string, Driver>mpOfDrivers;

	void AddRide( const Rider& rider, const Driver& driver );
	bool IsValidRider( const std::string& riderName );
	bool IsValidDriver( const std::string& driverName );
	std::string GetMatchingDriver( const std::string& riderName );
	
public:

	void AddRideDetails( const std::string& riderName, const int& riderRating, const std::string& driverName, const int driverRating );
	std::string GetMatchingDriverName(const std::string riderName);
};

