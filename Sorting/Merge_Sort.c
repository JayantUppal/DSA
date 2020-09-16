#include<stdio.h>

int array[1000], n;

void merge(int start, int middle, int end);

void mergesort(int l, int h)
{
  int mid;
  if(l<h)
  {
    mid=(l+h)/2;
    mergesort(l,mid);
    mergesort(mid+1,h);
    merge(l,mid,h);
  }
}

void merge(int start, int middle, int end)
{
  int i, j, k, sarray[1000];
  k=0;
  i=start;
  j=middle+1;

  while(i<=middle && j<=end)
  {
    if(array[i]<array[j])
      sarray[k++]=array[i++];
    else
      sarray[k++]=array[j++];

  }

  while(i<=middle)
    sarray[k++]=array[i++];

  while(j<=end)
    sarray[k++]=array[j++]; 
  
  for(i=end;i>=start;i--)
  	array[i]=sarray[--k]; 
}

int main()
{
  printf("Enter number of elements: ");
  scanf("%d", &n);
  printf("Enter array - ");
  for(int i=0;i<n;i++)
    scanf("%d", &array[i]);

  mergesort(0,n-1);

  printf("Sorted array - ");
  for(int i=0;i<n;i++)
    printf("%d ", array[i]);
  printf("\n");
  return 0;
}







