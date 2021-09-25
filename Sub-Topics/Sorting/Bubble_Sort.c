#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[5], i, j, temp;
	printf("Bubble Sort\n````````````\n");
	
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
	
	//Bubble sort
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
	//Sorted array
	printf("\nSorted array - ");
	for(i=0;i<5;i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}




