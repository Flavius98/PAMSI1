#include "Algorithms.h"

Algorithms::Algorithms(int size, double rand)
{
	this->size = size;
	this->a = new Array[AMOUNT]();
	
	if (rand >= 0)
		for (int i = 0; i < AMOUNT; i++)
		{
			this->a[i].SetMemory(size);
			this->a[i].Randomize(size, rand);
		}

	else if (rand == -1)
		for (int i = 0; i < AMOUNT; i++)
		{
			this->a[i].SetMemory(size);
			this->a[i].Randomize(size, rand);
		}
}

Algorithms::~Algorithms()
{
	delete[] this->a;
}

double Algorithms::Merge()
{
	double timeAverage = 0.0;

	for (int i = 0; i < AMOUNT; i++)
	{
		std::chrono::high_resolution_clock clock;
		auto start = clock.now();
		
		int* tArray = new int[this->size];
		this->m.DivideSort(this->a[i].arr, tArray, 0, this->size - 1);
		auto end = clock.now();
		auto timeSpan = static_cast<std::chrono::duration<double>>(end - start);
		timeAverage += timeSpan.count();
		this->a[i].IsSorted(this->size);

		delete[] tArray;
	}

	this->timeMerge = timeAverage;

	return timeAverage;
}

double Algorithms::Quick()
{
	double timeAverage = 0.0;
	for (int i = 0; i < AMOUNT; i++)
	{
		std::chrono::high_resolution_clock clock;
		auto start = clock.now();

		this->q.QuicksortAlg(this->a[i].arr, 0, this->size - 1);
		auto end = clock.now();
		auto timeSpan = static_cast<std::chrono::duration<double>>(end - start);
		timeAverage += timeSpan.count();
		this->a[i].IsSorted(this->size);
	}

	this->timeQuick = timeAverage;

	return timeAverage;
}

double Algorithms::Intro()
{
	double timeAverage = 0.0;
	for (int i = 0; i < AMOUNT; i++)
	{
		std::chrono::high_resolution_clock clock;
		auto start = clock.now();

		this->in.IntrosortAlg(this->a[i].arr, 0, this->size - 1, in.depthlimit);
		auto end = clock.now();
		auto timeSpan = static_cast<std::chrono::duration<double>>(end - start);
		timeAverage += timeSpan.count();
		this->a[i].IsSorted(this->size);
	}

	this->timeIntro = timeAverage;

	return timeAverage;
}
