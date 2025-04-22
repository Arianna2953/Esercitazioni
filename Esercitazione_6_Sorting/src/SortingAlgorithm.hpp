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
		for (unsigned int i=0;i<n-1;i++)
		{
			for (unsigned int j=i+1;j<n;j++)
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
		for (unsigned int j=0;j<n;j++)
			pop_heap(v.begin(),v.end()-j); //dequeue
	}
	template<typename T>
	void HeapSortCustom(vector<T>& v)
	{
		unsigned int n=v.size();
		while(n)
		{
			// make_heap per la dimensione n
			for (unsigned int i=1;i<n;i++)
			{
				unsigned int p=(i-1)/2;
				while (v[p]<v[i])
				{
					const T tmp=v[i];
					v[i]=v[p];
					v[p]=tmp;
					if(p!=0)
					{
						i=p;
						p=(i-1)/2;
					}
				}
			}
			T tmp=v[n-1];
			v[n-1]=v[0];
			v[0]=tmp;
			n--;
		}
	}
}


