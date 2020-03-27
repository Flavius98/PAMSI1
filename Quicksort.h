#pragma once

#include <iostream>

auto swap = [](auto& numb1, auto& numb2)
{
	auto temp = numb1;
	numb1 = numb2;
	numb2 = temp;
};

class Quicksort {
	int size;

public:
	template<typename Var>
	int Partition(Var* arr, int left, int right)
	{
		Var pivot = arr[(left + right) / 2];
		int i = left - 1;
		int j = right + 1;

		while (true)
		{
			while (pivot > arr[++i]);

			while (pivot < arr[--j]);

			if(i >= j) 
				return j;
			
			swap(arr[i], arr[j]);
		}
	}

	template<typename Var>
	void QuicksortAlg(Var* arr, int left, int right)
	{
		if (left < right)
		{
			int pivot = Partition(arr, left, right);
			QuicksortAlg(arr, left, pivot);
			QuicksortAlg(arr, pivot + 1, right);
		}
	}
};