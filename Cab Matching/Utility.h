#pragma once
class Utility
{
	public:
		static int NEXT_DRIVER_ID;
		static int NEXT_RIDER_ID;

	static int GetNextDriverID()
	{
		return NEXT_DRIVER_ID++;
	}

	static int GetNextRiderID()
	{
		return NEXT_RIDER_ID++;
	}
};

int Utility::NEXT_DRIVER_ID = 0;
int Utility::NEXT_RIDER_ID = 0;