#include <cmath> 
#include <numeric> 
#include <iostream>
#include <sstream>
#include <chrono>
#include <vector>

#include "SortingAlgorithm.hpp"
using namespace std;
using namespace chrono;

vector<unsigned int> generateVector(unsigned int size, const string& type) {
	vector<unsigned int> v(size);
	if (type=="sorted")
	{
		iota(v.begin(),v.end(),1);
	}
	else if (type=="reversed")
	{
		iota(v.rbegin(),v.rend(),1);
	}
	else
	{
		iota(v.begin(),v.end(),1);
		random_shuffle(v.begin(),v.end());
	}
	return v;
}
		
int main(int argc, char *argv[])
{
    if(argc!=2)
	{
		cerr << "Usage: " << argv[0] << "<vector size>" << endl;
		return 1;
	}
	const unsigned int size=stoi(argv[1]);
	const vector<string>types={"sorted","reverse","random"};
	const unsigned int NUM_SIMULATIONS=10;
	
	for (const string& type : types)
	{
		vector<unsigned int> original=generateVector(size,type);
		
		//BubbleSort
		long long bubble_total=0;
		for (unsigned int i=0;i<NUM_SIMULATIONS;i++)
		{
			vector<unsigned int> vec=original;
			auto start=high_resolution_clock::now();
			SortLibrary::BubbleSort(vec);
			auto end=high_resolution_clock::now();
			bubble_total=+duration_cast<microseconds>(end-start).count();
		}
		
		//HeapSort
		long long heap_total=0;
		for (unsigned int i=0;i<NUM_SIMULATIONS;i++)
		{
			vector<unsigned int> vec=original;
			auto start=high_resolution_clock::now();
			SortLibrary::HeapSort(vec);
			auto end=high_resolution_clock::now();
			heap_total=+duration_cast<microseconds>(end-start).count();
		}
		
		//HaepSortCostum
		long long heap_custom_total=0;
		for (unsigned int i=0;i<NUM_SIMULATIONS;i++)
		{
			vector<unsigned int> vec=original;
			auto start=high_resolution_clock::now();
			SortLibrary::HeapSortCustom(vec);
			auto end=high_resolution_clock::now();
			heap_custom_total=+duration_cast<microseconds>(end-start).count();
		}
		
		cout << "Vector type: " << type << endl;
		cout << "BubbleSort: " << bubble_total << " μs" << endl;
		cout << "HeapSort: " << heap_total << " μs" << endl;
		cout << "BHeapSortCustom: " << heap_custom_total << " μs" << endl;
	}
	return 0;
}

