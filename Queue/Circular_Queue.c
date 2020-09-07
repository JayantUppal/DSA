#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void enqueue(int **ptr, int item, int *f, int *r, int max)
{
  if((*r == max - 1 && *f == 0) | (*f == *r + 1))
  {
    printf("Overflow!\n");
    return;
  }
  if(*f == -1)
    *f = 0;
  //Set rear
  if(*r == max - 1)
    *r = 0;
  else
    (*r)++;
  //Enqueue item
  *(*ptr + *r) = item;
  printf("Item: %d enqueued!\n", *(*ptr + *r));
}

void dequeue(int **ptr, int *f, int *r, int max)
{
  if(*f == -1)
  {
    printf("Underflow!\n");
    return;
  }
  //Print dequeue item
  printf("Item: %d dequeued!\n", *(*ptr + *f));
  *(*ptr + *f) = INT_MIN;
  //Set front
  if(*r == *f)
  {
    *f = -1;
    *r = -1;
  }
  else if(*f == max - 1)
    *f = 0;
  else
    (*f)++;
}

void display(int **ptr, int *f, int *r, int max)
{
  if(*f == -1)
    printf("Queue is empty!\n");
  else
  {
    printf("\nQUEUE - ");
    for(int i = 0 ; i<max ; i++)
    {
      if(*(*ptr + i) == INT_MIN || *(*ptr + i) == 0)
        printf("_ ");
      else
        printf("%d ", *(*ptr + i));
    }
    printf("\nElement at front - %d\n", *(*ptr + *f));
    printf("Element at rear - %d\n", *(*ptr + *r));
  }
}


int main()
{
  int item, front = -1, rear = -1, max, choice;

  printf("Enter size of circular queue: ");
  scanf("%d", &max);

  int *queue = malloc(max*sizeof(int));

  while(1)
  {
    printf("\nCircular Queue operations:-\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
      printf("Enter item: ");
      scanf("%d", &item);
      enqueue(&queue, item, &front, &rear, max);
    }
    else if(choice == 2)
      dequeue(&queue, &front, &rear, max);
    else if(choice == 3)
      display(&queue, &front, &rear, max);
    else if(choice == 4)
    {
      free(queue);
      break;
    }
    else
      printf("Invalid choice!\n");
  }
}
