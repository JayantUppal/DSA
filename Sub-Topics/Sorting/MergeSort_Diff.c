#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define BILLION 1000000000.0
#define SIZE 1000000
 
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int L[n1+1], R[n2+1];

	L[n1]=1000000;
	R[n2]=1000000;

	for(i=0;i<n1;i++)
		L[i] = arr[l + i];

	for(j=0;j<n2;j++)
		R[j] = arr[m + 1+ j];

 	i = 0;
	j = 0;
	k = l;

	while (i < n1 || j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = (l+r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);

	}
} 

int main()
{
	int arr[SIZE], n, i;
	double timetaken;
	
  printf("Enter number of elements: ");
  scanf("%d", &n);
  
  printf("Unsorted array - ");
  for(i=0;i<n;i++)
  {
    arr[i] = rand()%10000;
    printf("%d ", arr[i]);
  }
    
  //sort and time taken
	struct timespec start, end;

	clock_gettime(CLOCK_REALTIME, &start);
	
	mergeSort(arr,0,n-1);
	
	clock_gettime(CLOCK_REALTIME, &end);

	timetaken = (end.tv_sec - start.tv_sec) +
						(end.tv_nsec - start.tv_nsec) / BILLION;

	printf("\nSorted array - ");
	for(i=0;i<n;i++)
		printf("%d ", arr[i]);
	
	printf("\nTime elpased by Sorting algorithm : %f seconds\n", timetaken);
  return 0;

}




