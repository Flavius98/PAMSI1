#include <iostream>

#include "Algorithms.h"
#include "Menu.h"

#define PATH "C:\\Users\\Patrick\\Documents\\PAMSI\\Projekt 1\\Pomiary\\"
#define EXTENSION ".txt"
#define EXTENSION2 ".csv"

std::string const NAME = "Timecount";

void CreateFile(double time, Menu::typeOfSorting type, int size, double typeOfArray)
{
	if (type == Menu::Mergesort)
	{
		std::ofstream mesFILE(PATH + NAME + std::to_string(typeOfArray) + "Mergesort" + std::to_string(size) + EXTENSION);
		mesFILE << time << std::endl << time / 100;
		mesFILE.close();
	}
}

int main()
{
	int sizeOfArray[] = { 10000,50000,100000,500000,1000000 };
	double typeOfArray[] = { -1,0,25,50,75,95,99,99.7 };

	std::ofstream FILE_outcsv(PATH + NAME + EXTENSION2);
	int i = 0, j = 0;

	FILE_outcsv << "type" << ", " << "size" << ", " << "time for all" << ", " << "Merge" << "\n";
	for (auto y : typeOfArray)
	{
		for (auto x : sizeOfArray)
		{
			if(typeOfArray[j] == -1)
				std::cout << "Mergesorting " << sizeOfArray[i] << " elements, which are inversely sorted\n";
			else if(typeOfArray[j] == 0)
				std::cout << "Mergesorting " << sizeOfArray[i] << " elements, of which none are sorted\n";
			else
				std::cout << "Mergesorting " << sizeOfArray[i] << " elements, of which " << typeOfArray[j] << "% are sorted\n";
			
			Algorithms* alg = new Algorithms(x, y);
			CreateFile(alg->Merge(), Menu::Mergesort, alg->size, y);
			FILE_outcsv << y << ", " << x << ", " << alg->timeMerge << "\n";
			delete alg;
			i++;
		}
		i = 0;
		j++;
	}

	j = 0;

	FILE_outcsv << "type" << ", " << "size" << ", " << "time for all" << ", " << "Quick" << "\n";
	for (auto y : typeOfArray)
	{
		for (auto x : sizeOfArray)
		{
			if (typeOfArray[j] == -1)
				std::cout << "Quicksorting " << sizeOfArray[i] << " elements, which are inversely sorted\n";
			else if (typeOfArray[j] == 0)
				std::cout << "Quicksorting " << sizeOfArray[i] << " elements, of which none are sorted\n";
			else
				std::cout << "Quicksorting " << sizeOfArray[i] << " elements, of which " << typeOfArray[j] << "% are sorted\n";

			Algorithms* alg = new Algorithms(x, y);
			CreateFile(alg->Quick(), Menu::Quicksort, alg->size, y);
			FILE_outcsv << y << ", " << x << ", " << alg->timeQuick << "\n";
			delete alg;
			i++;
		}
		i = 0;
		j++;
	}

	j = 0;

	FILE_outcsv << "type" << ", " << "size" << ", " << "time for all" << ", " << "Intro" << "\n";
	for (auto y : typeOfArray)
	{
		for (auto x : sizeOfArray)
		{
			if (typeOfArray[j] == -1)
				std::cout << "Introsorting " << sizeOfArray[i] << " elements, which are inversely sorted\n";
			else if (typeOfArray[j] == 0)
				std::cout << "Introsorting " << sizeOfArray[i] << " elements, of which none are sorted\n";
			else
				std::cout << "Introsorting " << sizeOfArray[i] << " elements, of which " << typeOfArray[j] << "% are sorted\n";

			Algorithms* alg = new Algorithms(x, y);
			CreateFile(alg->Intro(), Menu::Introsort, alg->size, y);
			FILE_outcsv << y << ", " << x << ", " << alg->timeIntro << "\n";
			delete alg;
			i++;
		}
		i = 0;
		j++;
	}

	j = 0;

	FILE_outcsv.close();

	std::cout << "Koniec" << std::endl;

	std::cin.ignore();
	std::cin.get();
	return 0;
}