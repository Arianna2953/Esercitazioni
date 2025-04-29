#pragma once

#include <iostream>
#include <vector>
#include <algorithm> // per usare le strutture heap di STL

using namespace std;

namespace SortLibrary {
	template<typename T>
	void BubbleSort(vector<T>& v)
	{
		const unsigned n=v.size();
		for (size_t i=0;i<n-1;i++)
		{
			for (size_t j=i+1;j<n;j++)
			{
				if(v[j]<v[i])
				{
					// swap
					const T tmp=v[i];
					v[i]=v[j];
					v[j]=tmp;
				}
			}
		}
	}
	
	template<typename T>
	void HeapSort(vector<T>& v)
	{
		const unsigned int n=v.size();
		make_heap(v.begin(),v.end()); // per trasformare il vettore v in un heap
		for (size_t j=0;j<n;j++){
			pop_heap(v.begin(),v.end()-j); //dequeue
		}
	}
}


