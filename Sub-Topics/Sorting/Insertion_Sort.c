#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[5], i, j, temp;
	printf("Insertion Sort\n````````````\n");
	
	FILE *myfile;
  myfile = fopen("numbers.txt", "r");

  if(myfile == NULL)
  {
  	printf("Error Reading File\n");
    exit(0);
  }
  
  printf("Unsorted array - ");
  for (i=0;i<5;i++)
  {
  	fscanf(myfile, "%d", &arr[i]);
  	printf("%d ", arr[i]);
  }
  
  fclose(myfile);
	//Insertion sort
	for(i=1;i<5;i++)
	{
		j=i;
		while(j>0)
		{
			if(arr[j-1]>arr[j])
			{
				count++;
				temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}
			j--;
		}
	}
	
	//Sorted array
	printf("\nSorted array - ");
	for(i=0;i<5;i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}




