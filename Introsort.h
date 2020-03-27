#pragma once

#include <cmath>

#include "Quicksort.h"

class Introsort {
	Quicksort q;
	int size;

public:
	int depthlimit = (int)std::floor(2 * std::log2(this->size));

	template<typename Var>
	void Intsort(Var *arr, int left, int right, int depthlimit)
	{
		if (right - left > 16)
		{
			if (this->depthlimit == 0)
				Heapsort(arr, left, right);
		
			this->depthlimit--;
			Var p = this->Partition(arr, left, right);
			Intsort(arr, p + 1, right, this->depthlimit);
			Intsort(arr, left, p, this->depthlimit);
		}

		else
			Insertionsort(arr, left, right);
	}

	template<typename Var>
	void DepthCalcu(Var right)
	{
		this->depthlimit = (int)std::floor(2 * std::log2(right));
	}

	template<typename Var>
	void IntrosortAlg(Var *arr, int left, int right, int depthlimit)
	{
		DepthCalcu(right);
		Intsort(arr, left, right, this->depthlimit);
	}

	template<typename Var>
	void Insertionsort(Var *arr, int left, int right)
	{
		for (int i = left; i <= right; i++)
		{
			Var key = arr[i];
			int j = i;

			while (j > left&& arr[j - 1] > key)
			{
				arr[j] = arr[j - 1];
				j--;
			}
			arr[j] = key;
		}
	}

	template<typename Var>
	void Heapsort(Var *arr, int left, int right)
	{
		++right;
		Var* temp = new Var[right - left];

		for (int i = 0; i < right - left; i++)
			temp[i] = arr[left + i];
		
		for (int i = (right - left) / 2 - 1; i >= 0; i--)
			Heaptree(temp, left, right, i);
		
		for (int i = (right - left) / 2 - 1; i >= 0; i--)
		{
			swap(temp[0], temp[i]);
			Heaptree(temp, 0, i, 0);
		}

		for (int i = 0; i < right - left; i++)
			arr[left + i] = temp[i];
	
		delete[] temp;
	}

	template<typename Var>
	void Heaptree(Var *arr, int left, int right, int heapN)
	{
		int size = right - left;
		int largest = heapN;
		int childLeft = 2 * heapN + 1;
		int childRight = 2 * heapN + 2;

		if (childLeft < size && arr[childLeft] > arr[largest])
			largest = childLeft;
		
		if (childRight < size && arr[childRight] > arr[largest])
			largest = childRight;
		
		if (largest != heapN)
		{
			swap(arr[heapN], arr[largest]);
			Heaptree(arr, left, right, largest);
		}
	}

	template<typename Var>
	int Partition(Var* arr, int left, int right)
	{
		Var pivot = arr[(left + right) / 2];
		Var i = left - 1;
		Var j = right + 1;

		while (true)
		{
			while (pivot > arr[++i]);

			while (pivot < arr[--j]);

			if (i >= j)
				return j;
			
			swap(arr[i], arr[j]);
		}
	}
};