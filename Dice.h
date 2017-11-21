#pragma once
#include <time.h>
#include<cstdlib>

	inline int dice(unsigned int m)
	{
		return(rand() % m + 1);
	}
	
	inline int D6()
	{
		return dice(6);
	}

	inline int D20()
	{
		return dice(20);
	}
