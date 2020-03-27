#pragma once

#include <string>
#include <fstream>
#include "Algorithms.h"

class Menu {
	Algorithms array_of_arrays;

public:
	enum typeOfSorting
	{
		Quicksort,
		Mergesort,
		Introsort
	};
};