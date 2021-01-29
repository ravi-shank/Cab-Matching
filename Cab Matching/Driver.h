#pragma once
#include<string>
#include<unordered_set>

class Driver
{

private:
	int id;
	std::string name;
	int avgRating;
	int numOfRides;
	std::unordered_set<std::string>blockedRidersList;

public:
	Driver()
	{
	}

	Driver( const int& ID, const std::string& name, double rating = 0.0)
	{
		this->id = ID;
		this->name = name;
		this->avgRating = rating;
		this->numOfRides = 0;
	}

	const int& GetID() const
	{
		return id;
	}

	const std::string& GetName()
	{
		return name;
	}

	const int& GetAvgRating()
	{
		return avgRating;
	}

	void AddRating( const int& rating )
	{
		
		avgRating = ( ( avgRating * numOfRides ) + rating ) / ( numOfRides + 1 );
		numOfRides++;
	}

	void AddBlockedRider( const std::string& riderName )
	{
		blockedRidersList.insert( riderName );
	}

	
};

