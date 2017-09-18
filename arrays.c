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

void swap(int *x, int *y);

void sortInWave(int arr[],int len);

void rearrangePosNeg(int arr[], int len);

void randomizeArray(int arr[], int len);

void strToLower(char* str);

void strToUpper(char* str);

//CTCI
bool isAnagram(char *str1,char *str2);

//CTCI
void reverseStr(char *str);

//CTCI
bool allUniqueChar(char *str);

int main(void)
{
  int arr[7] = {4,-1,-9,7,3,-8,1};
  char str1[] = "tea";
  char str2[] = "eat";
  reverseStr(str1);
  if(allUniqueChar(str2))
    printf("Unique");
  randomizeArray(arr,7);
  printArray(arr,7);
  return 0;
}

void strToLower(char* str)
{
	while(*str != '\0')
	{
		if(*str>=65 && *str <= 90)
		*str = *str+32;
		str++;
	}
}

void strToUpper(char* str)
{
	while(*str != '\0')
	{
		if(*str>=97 && *str <= 122)
		*str = *str-32;
		str++;
	}
}

bool allUniqueChar(char *str)
{
  char count[26];
  memset (count, 0, 26);
  int index;

  strToLower(str);
  while(*str != '\0')
  {
    index =(unsigned int)(*str) % 26;
    if(count[index] != 0)
        return false;
    count[index]++;
    str++;
  }

  return true;
}

void reverseStr(char *str)
{
  char *str_begin = str;
  char *str_end = str + strlen(str) - 1;

  char temp;

  while(str_begin < str_end)
  {
    temp = *str_begin;
    *(str_begin++) = *str_end;
    *(str_end--) = temp;
  }
  return;

  //Wihtout using pointers
  /*
  int len = strlen(str);
  int i =0;
  char temp;

  while(str[i] != '\0' && i < len-1)
  {
	temp = str[i];
	str[i] = str[len-i-1];
	str[len-i-1] = temp;
	i++;
  }
  return;
  */
}

bool isAnagram(char *str1,char *str2)
{
  int count[256];
  int index = -1;

  if(strlen(str1) != strlen(str2))
    return false;
  memset(count,0,256*sizeof(int));

  while(str1[++index] != '\0')
  {
    ++count[(unsigned int)str1[index]];
  }

  index = -1;
  while(str2[++index] != '\0')
  {
    --count[(unsigned int)str2[index]];
  }

  index = -1;
  while(++index < 256)
  {
    if(count[index] != 0)
      return false;
  }

  return true;
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
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
