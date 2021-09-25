#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void push(int **ptr, int item, int* t, int max)
{
  if(*t == (max - 1))
    printf("Stack overflow!\n");
  else
  {
    (*t)++;
    *(*ptr + *t) = item;
    printf("Item: %d pushed successfully\n", item);
  }
}

void pop(int **ptr, int *t)
{
  if(*t == -1)
    printf("Stack underflow!\n");
  else
  {
    printf("Item: %d poped successfully\n", *(*ptr + *t));
    *(*ptr + *t) = INT_MIN;
    (*t)--;
  }
}

void display(int **ptr, int* t)
{
  if(*t == -1)
    printf("Stack is empty!\n");
  else
  {
    printf("Stack:-\n");
    for(int i = *t; i >= 0; i--)
      printf("| %d |\n", *(*ptr + i));
  }
  printf("------\n");
}

int main()
{
  int item, top = -1, max, choice;

  printf("Enter size of stack: ");
  scanf("%d", &max);

  int *stack = malloc(max*sizeof(int));

  while(1)
  {
    printf("\nStack operations:-\n");
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
      printf("Enter item: ");
      scanf("%d", &item);
      push(&stack, item, &top, max);
    }
    else if(choice == 2)
      pop(&stack, &top);
    else if(choice == 3)
      display(&stack, &top);
    else if(choice == 4)
    {
      free(stack);
      break;
    }
    else
      printf("Invalid choice!\n");
  }
  return 0;
}
