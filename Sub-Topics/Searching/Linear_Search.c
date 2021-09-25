#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[10], i, search;
	printf("Linear Search\n````````````\n");
	
	FILE *myfile;
  myfile = fopen("array.txt", "r");

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
  
  //Linear search algo
  printf("\nEnter element to search: ");
  scanf("%d", &search);
  
  for(i=0;i<10;i++)
  {
  	if(search==arr[i])
  	{
  		printf("\nElement %d found at postion %d\n", search, i+1);  
  		break;
  	}
  }
  if(i==10)
  	printf("\nElement %d not found in array\n", search);
  	
  return 0;
}





