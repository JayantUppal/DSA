#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void add(int n, int A[n][n], int B[n][n], int C[n][n])
{
    int i, j;
    for(i=0;i<n;i++)
    {
			for(j=0;j<n;j++)
      {
      	C[i][j] = A[i][j] + B[i][j];
      }
    }
}

void sub(int n, int A[n][n], int B[n][n], int C[n][n])
{
    int i, j;
    for(i=0;i<n;i++)
    {
			for(j=0;j<n;j++)
      {
      	C[i][j] = A[i][j] - B[i][j];
      }
    }
}

void MM(int n, int A[n][n], int B[n][n], int C[n][n])
{
    if(n==1)
    {
    	C[0][0] = A[0][0] * B[0][0];
    	return;
    }
    else
    {
    	int i, j, new = n / 2;
			int a00[new][new], a01[new][new], a10[new][new], a11[new][new];
			int b00[new][new], b01[new][new], b10[new][new], b11[new][new];
			int c00[new][new], c01[new][new], c10[new][new], c11[new][new];

			int P[n][n], Q[n][n], R[n][n], S[n][n], T[n][n], U[n][n], V[n][n];
			int ares[n][n], bres[n][n];

			for(i=0;i<new;i++)
			{
				for(j=0;j<new;j++)
				{
					a00[i][j]=A[i][j];
					a01[i][j]=A[i][j+new];
					a10[i][j]=A[i+new][j];
					a11[i][j]=A[i+new][j+new];

					b00[i][j]=B[i][j];
					b01[i][j]=B[i][j+new];
					b10[i][j]=B[i+new][j];
					b11[i][j]=B[i+new][j+new];
				}
			}

      //Naive method
      MM(new, a00, b00, ares);
      MM(new, a01, b10, bres);
      add(new, ares, bres, c00);

      MM(new, a00, b01, ares);
      MM(new, a01, b11, bres);
      add(new, ares, bres, c01);

      MM(new, a10, b00, ares);
      MM(new, a11, b10, bres);
      add(new, ares, bres, c10);

      MM(new, a10, b01, ares);
      MM(new, a11, b11, bres);
      add(new, ares, bres, c11);

      // Grouping the results obtained in a single matrix:
      for(i=0;i<new;i++)
      {
      	for(j=0;j<new;j++)
        {
        	C[i][j]=c00[i][j];
          C[i][j+new]=c01[i][j];
          C[i+new][j]=c10[i][j];
          C[i+new][j+new]=c11[i][j];
        }
      }

    }
}

int main()
{
    int n, i, j;
    double timetaken;

		printf("Matrix Multiplication\n");
		printf("`````````````````````````````````\n");
		printf("NOTE - It works on square matrix of size 2, 4, 8, 16...\n");
		printf("\nEnter size: ");
		scanf("%d", &n);

		int mat1[n][n], mat2[n][n], result[n][n];

		srand(time(0));
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				mat1[i][j] = rand()%10;
				mat2[i][j] = rand()%10;
			}
		}

		printf("Matrix-1 : \n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d ", mat1[i][j]);
			}
			printf("\n");
		}

		printf("Matrix-2 : \n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d ", mat2[i][j]);
			}
			printf("\n");
		}

	  struct timespec start, end;
	  clock_gettime(CLOCK_REALTIME, &start);

	  MM(n, mat1, mat2, result);

	  clock_gettime(CLOCK_REALTIME, &end);

	  timetaken = (end.tv_sec - start.tv_sec) +
						(end.tv_nsec - start.tv_nsec) / 1000000000.0;


		printf("Resultant matrix : \n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d ", result[i][j]);
			}
			printf("\n");
		}

    printf("\nTime elpased : %f seconds\n", timetaken);
    return 0;
}
