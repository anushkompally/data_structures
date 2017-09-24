void bubblesort(int arr[],int len)
{
	int count;
	while(count != 0)
	{
		count = 0;
		for(int i = 0; i<len-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				swap(&arr[i],&arr[i+1]);
				count++;
			}
		}
		if(count==0)
		 break;
	}
}


