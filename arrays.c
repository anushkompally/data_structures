/*******************************************************************/
//Arrays
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void rotateArrByOne(int arr[],int len);

void rotateArr(int arr[],int len, int dTimes);

void printArray(int arr[], int len);

void reverseArr(int arr[],int len);

int binarySearch(int arr[],int high,int low, int key);

bool isSorted(int arr[],int len);

bool pairInSortedRotated(int arr[], int len, int sum);

int minimumInSortedRotated(int arr[], int len);

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void sortInWave(int arr[],int len);

void rearrangePosNeg(int arr[], int len);

void randomizeArray(int arr[], int len);

int main(void)
{
  int arr[7] = {4,-1,-9,7,3,-8,1};
  randomizeArray(arr,7);
  printArray(arr,7);
  return 0;
}

void randomizeArray(int arr[], int len)
{
  srand(time(NULL));

  for (int i = len-1; i>=0; i--)
  {
      int j = rand() % (i+1);
      swap(&arr[i],&arr[j]);
  }
}

void rearrangePosNeg(int arr[], int len)
{
  int key,j;

  for (int i = 1; i < len; i++)
  {
    key = arr[i];

    if(key>0)
      continue;

    j = i-1;
    while (j>=0 && arr[j]>0)
    {
      arr[j+1] = arr[j];
      j = j-1;
    }
    arr[j+1] = key;
  }
}

void sortInWave(int arr[],int len)
{
  for (int i = 0; i<len; i+=2)
  {
    if(i>0 && arr[i-1] > arr[i])
      swap(&arr[i-1],&arr[i]);

    if(i<len-1 && arr[i+1] > arr[i])
      swap(&arr[i+1],&arr[i]);
  }
}

int minimumInSortedRotated(int arr[], int len)
{
  int i;

  for(i=0;i<len;i++)
  {
    if(arr[i]>arr[i+1])
      break;
  }
  return arr[i+1];
}

bool pairInSortedRotated(int arr[], int len, int sum)
{
  int i;
  for(i = 0; i<len; i++)
  {
    if(arr[i]>arr[i+1])
      break;
  }
  int l = (i+1)%len;
  int r = i;

  while(l!=r)
  {
    if(arr[l] + arr[r] == sum)
      return true;

    if(arr[l] + arr[r] < sum)
        l = (l+1)%len;
    else
          r = (len + r - 1)%len;
  }
  return false;
}

bool isSorted(int arr[],int len)
{
  for (int i = 0; i<len ; i++)
  {
    if(arr[i]>arr[i+1])
      return false;
  }
  return true;
}

int binarySearch(int arr[],int high,int low, int key)
{
  if(high < low)
    return -1;

  if(high == low)
  {
     if(arr[low] == key)
       return low;
     else
       return -1;
  }

  int mid =  (low + high)/2;

  if (arr[mid] == key)
    return mid;

  if(arr[mid]>key)
    return binarySearch(arr,mid-1,low,key);

  return binarySearch(arr,high,mid+1,key);
}

void reverseArr(int a[],int len)
{
  int temp, i;
  for (i = 0; i<=len/2; i++)
  {
    temp = a[i];
    a[i] = a[len-i-1];
    a[len-i-1] = temp;
  }
}

void printArray(int arr[], int len)
{
    for(int i = 0; i<len; i++)
    {
      printf("%d ", arr[i]);
    }
}

void rotateArrByOne(int arr[],int len)
{
  int temp, i;
  temp = arr[0];

  for(i = 0; i< len-1; i++)
  {
    arr[i] = arr[i+1];
  }
  arr[i] = temp;
}

void rotateArr(int arr[],int len, int dTimes)
{
  while(dTimes>0)
  {
    rotateArrByOne(arr,len);
    dTimes--;
  }
}
