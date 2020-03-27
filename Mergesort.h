#pragma once

#include <iostream>
#include <cstdlib>

class Mergesort {
public:
	template <typename Var>
	void Merging(Var* arr, Var* tArr, int left, int mid, int right)
	{
		for (Var i = left; i <= right; i++)
			tArr[i] = arr[i];

		Var i = left;
		Var j = mid + 1;

		for (Var k = left; k <= right; k++)
		{
			if (i <= mid)
			{
				if (j <= right)
				{
					if (tArr[j] < tArr[i])
						arr[k] = tArr[j++];

					else
						arr[k] = tArr[i++];
				}

				else
					arr[k] = tArr[i++];
			}

			else
				arr[k] = tArr[j++];
		}
	}

	template <typename Var>
	void DivideSort(Var* arr, Var* tArr, int left, int right)
	{
		if (right <= left)
			return;

		Var mid = (left + right) / 2;

		DivideSort(arr, tArr, mid + 1, right);
		DivideSort(arr, tArr, left, mid);
		Merging(arr, tArr, left, mid, right);
	}
};