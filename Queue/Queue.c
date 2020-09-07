#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void enqueue(int **ptr, int item, int *f, int *r, int max)
{
  if(*r == max - 1)
  {
    printf("Overflow!\n");
    return;
  }
  if(*f == -1)
    *f = 0;
  (*r)++;
  *(*ptr + *r) = item;
  printf("Item: %d enqueued!\n", *(*ptr + *r));
}

void dequeue(int **ptr, int *f, int *r)
{
  if(*f == -1 || (*f == *r + 1))
    printf("Underflow!\n");
  else
  {
    printf("Item: %d dequeued!\n", *(*ptr + *f));
    *(*ptr + *f) = INT_MIN;
    (*f)++;
  }
}

void display(int **ptr, int *f, int *r)
{
  if(*f == *r + 1)
    printf("Queue is empty!\n");
  else
  {
    printf("Front - ");
    for(int i = *f ; i<=*r ; i++)
      printf("%d ", *(*ptr + i));
    printf("- End\n");
  }
}

void reset(int *f, int *r)
{
  *f = 0;
  *r = -1;
  printf("Queue reseted!\n");
}


int main()
{
  int item, front = -1, rear = -1, max, choice;

  printf("Enter size of queue: ");
  scanf("%d", &max);

  int *queue = malloc(max*sizeof(int));

  while(1)
  {
    printf("\nQueue operations:-\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Reset queue\n5. Exit\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
      printf("Enter item: ");
      scanf("%d", &item);
      enqueue(&queue, item, &front, &rear, max);
    }
    else if(choice == 2)
      dequeue(&queue, &front, &rear);
    else if(choice == 3)
      display(&queue, &front, &rear);
    else if(choice == 4)
      reset(&front, &rear);
    else if(choice == 5)
    {
      free(queue);
      break;
    }
    else
      printf("Invalid choice!\n");
  }
}
