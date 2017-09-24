//Binary heap
typedef struct heap
{
	int* h_arr;
	int capacity;
	int size;
}Heap;

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int parent(int i)
{
	return (i-1)/2;
}

int left(int i)
{
	return 2*i+1;
}

int right(int i)
{
	return 2*i+2;
}

Heap* heapInit(int capacity)
{
	Heap* heap = (Heap*) malloc (sizeof(Heap));
	heap->capacity = capacity;
	heap->size = 0;
	heap->h_arr = (int*)malloc(capacity*sizeof(int));

	return heap;
}

void heap_insertKey(Heap* heap, int key)
{
	if(heap == NULL || heap->capacity == heap->size)
		return;

	heap->size++;
	int i = heap_size-1;
	heap->h_arr[i] = key;

	while(i!=0 && heap->h_arr[parent(i)] > heap->h_arr[i])
	{
		swap(&heap->h_arr[parent(i)],&heap->h_arr[i]);
		i = parent(i);
	}
}


void heap_updateKey(Heap* heap, int i, int key)
{
	heap->h_arr[i] = key;

	while(i!=0 && heap->h_arr[parent(i)] > heap->h_arr[i])
	{
		swap(&heap->h_arr[parent(i)],&heap->h_arr[i]);
		i = parent(i);
	}

}

void minHeapify(Heap* heap, int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if(l < heap->size && heap->h_arr[l] < heap->h_arr[smallest])
		smallest = l;
	if(r < heap->size && heap->h_arr[r] < heap->h_arr[l])
		smallest = r;
	if(smallest != i)
	{
		swap(&heap->h_arr[smallest],&heap->h_arr[i]);
		minHeapify(heap,smallest);
	}

}

int heap_extractMin(Heap* heap)
{
	if(heap->size <= 0)
		return -1;
	if(heap->size == 1)
		heap->size--;
		return heap->h_arr[0];

	int root = heap->h_arr[0];
	heap->h_arr[0] = heap->h_arr[heap->size-1];
	heap->size--;
	minHeapify(heap,0);

}

void heapify(int arr[],int len, int i)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;

	if(l<len && arr[l] > arr[largest])
		largest = l;
	if(r<len && arr[r] > arr[l])
		largest = r;
	
	if(largest != i)
	{
		swap(&arr[largest],&arr[i]);
		heapify(arr[],len, largest);
	} 
}

void heapsort(int arr[], int len)
{// Build heap (rearrange array)
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(arr, len, i);
 
    // One by one extract an element from heap
    for (int i=len-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printArr(int arr[],int len)
{
	int i = 0;
	for(i=0;i<len;i++)
		printf("%d\t",arr[i]);
}

void minheapify(int arr[],int len, int i)
{
	int l = (2*i)+1;
	int r = (2*i)+2;
	int smallest = i;
	//printf("%d %d %d\n",arr[largest],arr[l],arr[r]);
	if(l<len && arr[l] < arr[smallest])
		smallest = l;
	if(r<len && arr[r] < arr[smallest])
		smallest = r;
	if(smallest != i)
	{
		swap(&arr[smallest],&arr[i]);
		minheapify(arr,len, smallest);
	} 
}

void maxheapify(int arr[],int len, int i)
{
	int l = (2*i)+1;
	int r = (2*i)+2;
	int largest = i;
	//printf("%d %d %d\n",arr[largest],arr[l],arr[r]);
	if(l<len && arr[l] > arr[largest])
		largest = l;
	if(r<len && arr[r] > arr[l])
		largest = r;
	if(largest != i)
	{
		swap(&arr[largest],&arr[i]);
		maxheapify(arr,len, largest);
	} 
}

void extractMax(int arr[],int len)
{
	if(len==1)
	return ;
	int root;
	for(int i =0;i<3;i++)
	{
		root = arr[0];
		arr[0] = arr[len-1];
		len = len-1;
		maxheapify(arr,len,0);
		printf("%d\t",root);
	}
}
