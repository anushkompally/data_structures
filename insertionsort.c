/*****************************************************************/
//Insertion Sort Time complexity - O(n^2)
//Space Complexity - O(1)
//
//
/*****************************************************************/
void insertionSort(int arr[], int len)
{
  int key,i,j;
  for(i=1;i<len:i++)
  {
    key = arr[i];
    j = i-1;

    while(j>=0 && arr[j]>key)
    {
      arr[j+1] = arr[j];
      j=j-1;
    }
    a[j+1] = key;
  }
}
