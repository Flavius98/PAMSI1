#pragma once

#include <iostream>
#include <time.h>

auto compsmtbig = [](auto& a, auto& b) {return a <= b; };


class Array {
public:
	int *arr = nullptr;

	Array();
	~Array();

	void Randomize(int size, double percent);
	void SetMemory(int size);
	void IsSorted(int size);
};