#pragma once

#include <iostream>
#include <chrono>
#include <cstdlib>

#include "Array.h"
#include "Mergesort.h"
#include "Quicksort.h"
#include "Introsort.h"

#define AMOUNT 100

class Algorithms {
public:
	int size = 0;

	double timeMerge = 0;
	double timeQuick = 0;
	double timeIntro = 0;

	Array* a;
	Mergesort m;
	Quicksort q;
	Introsort in;

	Algorithms(int size, double rand);
	~Algorithms();

	double Merge();
	double Quick();
	double Intro();
};