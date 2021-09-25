#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[5], i, j, temp, min;
	printf("Selection Sort\n````````````\n");
	
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
	
	//Selection sort
	for(i=0;i<4;i++)
	{
		min=i;
		for(j=i+1;j<5;j++)
		{
			if(arr[j]<arr[min])
				min=j;
		}
		
		if(min!=i)
		{
			temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
		}
	}
	
	//Sorted array
	printf("\nSorted array - ");
	for(i=0;i<5;i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}




