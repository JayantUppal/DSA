#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 1000000

void quicksort(int arr[], int start, int end);
int partition(int arr[], int start, int end);

void quicksort(int arr[], int start, int end)
{
  int p;
  if(start<end)
  {
    p=partition(arr, start, end);
    quicksort(arr, start, p-1);
    quicksort(arr, p+1, end);
  }
}

int partition(int arr[], int start, int end)
{
  int temp, i;
  int pivot=arr[end];
  int pindex=start;
  for(int i=start;i<end;i++)
  {
    if(arr[i]<=pivot)
    {
      temp=arr[i];
      arr[i]=arr[pindex];
      arr[pindex]=temp;

      pindex++;
    }
  }
  temp=arr[pindex];
  arr[pindex]=arr[end];
  arr[end]=temp;

  return pindex;
}

int main()
{
  int arr[SIZE], n, i;

  printf("Enter no. of elements: ");
  scanf("%d", &n);

  printf("Unsorted array - ");
  for(i=0;i<n;i++)
    printf("%d ", arr[i]=rand()%1000);
   
  quicksort(arr, 0, n-1);

  printf("\nSorted array - ");
  for(i=0;i<n;i++)
    printf("%d ", arr[i]);

  return 0;
}









