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

void STRASSEN_algorithm(int n, int A[n][n], int B[n][n], int C[n][n])
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

			//Strassen's algorithm
      add(new, a00, a11, ares);// a00 + a11
      add(new, b00, b11, bres);// b00 + b11
      STRASSEN_algorithm(new, ares, bres, P);//P = (a00+a11)*(b00+b11)

      add(new, a10, a11, ares);// a10 + a11
      STRASSEN_algorithm(new, ares, b00, Q);//Q = (a10+a11) * (b00)

      sub(new, b01, b11, bres);// b01 - b11
      STRASSEN_algorithm(new, a00, bres, R);//R = (a00) * (b01 - b11)

      sub(new, b10, b00, bres);// b10 - b00
      STRASSEN_algorithm(new, a11, bres, S);//S = (a11) * (b10 - b00 ;/p[']']

      add(new, a00, a01, ares);// a00 + a01
      STRASSEN_algorithm(new, ares, b11, T);//T = (a00+a01) * (b11)

    	sub(new, a10, a00, ares);// a10 - a00
      add(new, b00, b01, bres);// b00 + b01
      STRASSEN_algorithm(new, ares, bres, U);//U = (a10-a00) * (b00+b01)

      sub(new, a01, a11, ares);// a01 - a11
      add(new, b10, b11, bres);// b10 + b11
      STRASSEN_algorithm(new, ares, bres, V);//V = (a01-a11) * (b10+b11)

      // calculating c00, c01, c10 c11
      add(new, R, T, c01);// c01 = R + T
      add(new, Q, S, c10);// c10 = Q + S

      add(new, P, S, ares);//P + S
      add(new, ares, V, bres);//P + S + V
      sub(new, bres, T, c00);//c00 = P + S - T + V

      add(new, P, R, ares);//P + R
      add(new, ares, U, bres);//P + R + U
      sub(new, bres, Q, c11); //c11 = P + R - Q + U

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

		printf("Strassen's Matrix Multiplication\n");
		printf("`````````````````````````````````\n");
		printf("NOTE - SMM works on square matrix of size 2, 4, 8, 16...\n");
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

	  STRASSEN_algorithm(n, mat1, mat2, result);

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
