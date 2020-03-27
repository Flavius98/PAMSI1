#include "Array.h"

Array::Array()
{
	//std::cout << "arr++";
}

Array::~Array()
{
	delete[] arr;
}

void Array::Randomize(int size, double percent)
{
	srand(time(NULL));

	int restOfSize = size - size * (percent / 100);

	if (percent >= 0)
		for (int i = 0; i < size; i++)
		{
			if (i < restOfSize)
				arr[i] = (std::rand() % (size * 10) + 1);

			else
				arr[i] = i;
		}


	else if (percent == -1)
		for (int i = size; i >= 0; i--)
			arr[size - i] = i;

}

void Array::SetMemory(int size)
{
	if (size == 0)
		std::cout << "memory cant be alocated";

	else if (size < 100000)
		arr = new int[size * 10];

	else if (size >= 100000)
		arr = new int[size * 2];
}

void Array::IsSorted(int size)
{
	for (int count = 0; count < size; count++)
	{

		if (compsmtbig(this->arr[count - 1], this->arr[count]))
		{
			//do nothing
		}
		else if (count == 0)
		{
			// do nothing
		}
		else
		{
			std::cout << "not sorted well";
			break;
		}
	}
}