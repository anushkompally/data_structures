/*
Queue is a FIFO data structure
Enqueued at rear and dequeued at the front
*/
struct queue
{
  int front, rear, size;
  unsigned capacity;
  int* array;
};

typedef struct queue Queue;

Queue* initQueue(unsigned capacity)
{
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;
  queue->rear = capacity - 1;
  queue->array = (int*)malloc(queue->capacity * sizeof(int));
  return queue;
}

bool isEmpty(Queue* Q)
{
  return (Q->size == 0)
}

bool isFull(Queue* Q)
{
  return (Q->size == Q->capacity);
}

void enqueue (Queue* Q, int num)
{
  if(isFull(Q))
    return;
  Q->rear = (Q->rear+1) % Q->capacity;
  Q->array[Q->rear] = num;
  Q->size = Q->size + 1;
}

int dequeue(Queue* Q)
{
  if(isEmpty(Q))
    return INT_MIN;
  int item = Q->array[Q->front];
  Q->front = (Q->front+1) % Q->capacity;
  Q->size = Q->size - 1;
  return item;
}

int peek_front(Queue* Q)
{
  return Q->array[Q->front];
}

int peek_rear(Queue* Q)
{
  return Q->array[Q->rear];
}
