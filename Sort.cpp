#include "Sort.h"
#include <iostream>
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

int main(int argc, char **argv) {
	int a[10] = {0,1,3,2,5,8,6,7,9,11};
	bubble_sort(a,10);
	for(int i = 0; i < 10; ++i)
	{
		std::cout<< a[i] << " ";
	}
	std::cout<< std::endl;
	return 0;
}
