#include "Sort.h"
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;
//insert sort
void insert_sort(int a[], int n)
{
	for(int i = 1; i < n; ++i)
		for(int j = i-1; j>=0 && a[j] > a[j+1]; --j)
		{
			swap(a[j],a[j+1]);
		}
}

//bubble sort
void bubble_sort(int a[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 1; j < n-i; ++j)
		{
			if(a[j-1] > a[j])
				swap(a[j-1],a[j]);
		}
	}
}

//折半插入排序
void b_insert_sort(int a[],int n)
{
	for(int i = 1; i < n; ++i)
	{
		int sed = b_search(a,0,i,a[i]);
		for(int j = sed; j < i; ++j)
		{
			swap(a[j],a[i]);
		}
	}
}

//折半查找
int b_search(int a[],int left, int right, int s_number)
{
	if(left+1 == right)
	{
		return right;
	}
	else
	{
		if(s_number > a[(left+right)/2])
		{
			left = (left + right)/2;
			return	b_search(a,left,right,s_number);
		}
		else
		{
			right = (left + right)/2;
			return 	b_search(a,left,right,s_number);
		}
	}
}

//quick sort
void quick_sort(int a[], int p, int r)
{
	if(p < r)
	{
		int q = partition(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
}

int partition(int a[], int p, int r)
{
	int x = a[r];
	int i = p - 1;
	for(int j = p; j < r; ++j)
	{
		if(a[j] <= x)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
}

//heap sort
void max_heapify(int a[],int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest;
	if(l <= heap_size && a[l] > a[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if(r <= heap_size && a[r] > a[largest])
	{
		largest = r;
	}
	if(largest != i)
	{
		swap(a[i], a[largest]);
		max_heapify(a,largest);
	}
}

void build_max_heap(int a[],int n)
{
	heap_size = n;
	for(int i = n/2; i >= 1; --i)
	{
		max_heapify(a,i);
	}
}

void heap_sort(int a[],int n)
{
	build_max_heap(a,n);
	for(int i = n; i >= 2; --i)
	{
		swap(a[1],a[i]);
		heap_size--;
		max_heapify(a,1);
	}
}


//selection sort
void select_sort(int a[],int n)
{
	for(int i = 0; i < n; ++i)
	{
		int min = a[i];
		for(int j = i; j < n; ++j)
		{
			if(min > a[j])
			{
				swap(min,a[j]);
			}
		}
	}
}

void radix_sort(int a[], int n)
{
	queue<int> radix[10];
	for(int i = 0; i < 3; ++i)
	{
		switch (i)
		{
			case 0:
				for(int j = 0; j < n; ++j)
				{
					radix[BITS(a[j])].push(a[j]);	
				}
				break;
			case 1:
				for(int j = 0; j < n; ++j)
				{
					radix[TEN(a[j])].push(a[j]);
				}
				break;
			case 2:
				for(int j = 0; j < n; ++j)
				{
					radix[HUNDERD(a[j])].push(a[j]);
				}
				break;
			default:
				;
		}
		int count = 0;
		for(int i = 0; i < 10; ++i)
		{
			if(!radix[i].empty())
			{
				a[count++] = radix[i].front();
			}	
		}
	}
}

int main(int argc, char **argv) {
	cout << "Please enter N:" << endl;
	int	N,choice; 
	while(cin >> N && N!=0)
	{
		int a[N];

		for(int i = 0; i < N; ++i)
		{
			a[i] = rand()%1000;
		}
		cout << "please chose a way to sort:" << endl;
		cout << "1.b_insert_sort\t2.bubble_sort\t3.heap_sort\t\n4.insert_sort\t5.quick_sort\t6.radix_sort\n7.select_sort\t"<<endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
				b_insert_sort(a,N);		
				break;
			case 2:
				bubble_sort(a,N);
				break;
			case 3:
				heap_sort(a,N);
				break;
			case 4:
				insert_sort(a,N);
				break;
			case 5:
				quick_sort(a,0,N);
				break;
			case 6:
				radix_sort(a,N);
				break;
			case 7:
				select_sort(a,N);
				break;
			default:
				;
		}
		cout << "done!!" << endl;
	}
	return 0;
}
