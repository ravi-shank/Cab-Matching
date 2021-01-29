#pragma once
#include<string>
#include<unordered_set>

class Rider
{

private: 
	int id;
	std::string name;
	double avgRating;
	int numOfRides;
	std::unordered_set<std::string>blockedDriversList;

public:
	Rider()
	{
	}
	Rider( const int& ID, const std::string& name, double rating = 0.0 )
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

		avgRating = ( ( avgRating * numOfRides ) + rating ) / ( numOfRides + 1.0 );
		numOfRides++;
	}

	void AddBlockedDriver(const std::string& driverName)
	{
		blockedDriversList.insert( driverName );
	}
	
	bool HasBlocked( const std::string& driverName )
	{
		return ( blockedDriversList.find( driverName ) != blockedDriversList.end() );
	}
};

