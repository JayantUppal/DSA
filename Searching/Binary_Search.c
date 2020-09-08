#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[10], i, search, middle, first, last;
	printf("Binary Search\n````````````\n");
	
	FILE *myfile;
  myfile = fopen("sortedarray.txt", "r");

  if(myfile == NULL)
  {
  	printf("Error Reading File\n");
    exit(0);
  }
  
  printf("Array - ");
  for (i=0;i<10;i++)
  {
  	fscanf(myfile, "%d", &arr[i]);
  	printf("%d ", arr[i]);
  }
  
  //Binary search algo
  printf("\nEnter element to search: ");
  scanf("%d", &search);
  
  first=0;
  last=10-1;
  middle=(first+last)/2;
 
  while(first<=last)
  {
  	if(arr[middle]<search)
         first=middle+1;    
    else if(arr[middle]==search) 
    {
    	printf("\nElement %d found at postion %d\n", search, middle+1);
      break;
    }
    else
      last=middle-1;
 
  	middle=(first+last)/2;
	}
  if(first>last)
  	printf("\nElement %d not found in array\n", search);
  	
  return 0;
}





