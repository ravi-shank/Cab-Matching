#include "Matcher.h"
#include"Utility.h"
#include"Rider.h"
#include"Driver.h"

void Matcher::AddRide( const Rider& rider, const Driver& driver )
{

}

bool Matcher::IsValidRider( const std::string& riderName )
{
	auto it = mpOfRiders.find( riderName );
	return (it != mpOfRiders.end());
}

bool Matcher::IsValidDriver( const std::string& driverName )
{
	auto it = mpOfDrivers.find( driverName );
	return ( it != mpOfDrivers.end() );
}

std::string Matcher::GetMatchingDriver( const std::string& riderName )
{
	Rider& rider = mpOfRiders[riderName];

	int maxMatchingDriverAvgRating = 0;
	std::string matchingDriverName;
	bool isMatchingDriverFound = false;

	std::string bestMatchingDriverName;
	int bestMaxDriverRating = 0;
	bool isBestMatchingDriverFound = false;

	for( auto& driver : mpOfDrivers )
	{
		double driverAvgRating = driver.second.GetAvgRating();
		double riderAvgRating = rider.GetAvgRating();
		std::string driverName = driver.second.GetName();

		if( !rider.HasBlocked( driverName ) )
		{
			if( driverAvgRating > riderAvgRating )
			{
				if( maxMatchingDriverAvgRating < driverAvgRating )
				{
					maxMatchingDriverAvgRating = driverAvgRating;
					matchingDriverName = driver.second.GetName();
					isMatchingDriverFound = true;
				}
			}
			else
			{
				if( bestMaxDriverRating < driverAvgRating )
				{
					bestMaxDriverRating = driverAvgRating;
					bestMatchingDriverName = driver.second.GetName();
					isBestMatchingDriverFound = true;
				}
			}
		}
	}

	if( isMatchingDriverFound )
		return matchingDriverName;
	if( isBestMatchingDriverFound )
		return bestMatchingDriverName;

	return "No driver found";
}

void Matcher::AddRideDetails( const std::string& riderName, const int& riderRating, const std::string& driverName, const int driverRating )
{
	Rider rider;
	Driver driver;

	if( IsValidRider( riderName ) )
	{
		rider = mpOfRiders[riderName];

		
	}
	else  // new rider
	{
		const int id = Utility::GetNextRiderID();
		rider = Rider( id, riderName );
		mpOfRiders[riderName] = rider;
	}

	if( IsValidDriver( driverName ) )
	{
		driver = mpOfDrivers[driverName];

	}
	else  // new driver
	{
		const int id = Utility::GetNextDriverID();
		driver = Driver( id, driverName );
		mpOfDrivers[driverName] = driver;
	}
	
	//  Update ratings
	mpOfRiders[riderName].AddRating( riderRating );
	mpOfDrivers[driverName].AddRating( driverRating );

	// Update blocked rider & blocked driver details to each other, if any
	if( riderRating == 1 || driverRating == 1 )
	{
		mpOfRiders[riderName].AddBlockedDriver( driverName );
		mpOfDrivers[driverName].AddBlockedRider( riderName );
	}
}

std::string Matcher::GetMatchingDriverName( const std::string riderName )
{
	// check is Valid rider, else return appropriate error
	if( !IsValidRider( riderName ) )
		return "Invalid rider name";

	std::string driverName = GetMatchingDriver( riderName );
	return driverName;
}
