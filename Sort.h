#ifndef __SORT_H__
#     define __SORT_H__
void insert_sort(int src[], int n);
void bubble_sort(int src[], int n);
void b_insert_sort(int src[],int n);
int b_search(int a[],int left,int right,int s_number);
void quick_sort(int src[], int p, int r);
int partition(int src[],int p, int r);

void heap_sort(int src[],int n);
void build_max_heap(int src[], int n);
void max_heapify(int src[], int i);
#define PARENT(x) ((x)/2)
#define LEFT(x) (2*(x))
#define RIGHT(x) (2*(x) + 1)
int heap_size;

void select_sort(int src[],int n);

void radix_sort(int src[],int n);
#define BITS(x) ((x)%10)
#define TEN(x)	((x)/10%10)
#define HUNDERD(x) ((x)/100)
#endif /* __SORT_H__ */
