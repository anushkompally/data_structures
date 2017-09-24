#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void printArr(int arr[],int len)
{
	for(int i =0; i<len; i++)
		printf("%d",arr[i]);
}

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void minheapify(int arr[],int len, int i)
{
	int smallest = i;
	int l = 2*i+1;
	int r = 2*i+2;

	if(l<len && arr[l] < arr[smallest])
		smallest = l;
	if(r<len && arr[r] < arr[smallest])
		smallest = r;

	if(smallest != i)
	{
		swap(&arr[i],&arr[smallest]);
		minheapify(arr,len,smallest);
	}
}

void heapsort(int arr[],int len)
{
	for(int i = (len/2)-1;i>=0;i--)
		minheapify(arr,len,i);

	for(i=len;i>=0; i--)
	{
		swap(&arr[0],&arr[i]);
		minheapify(arr,i,0);
	}

}
