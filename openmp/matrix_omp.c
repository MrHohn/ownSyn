#include <stdio.h>
#include "timer.h"

#define N 1000

int main (void)
{   
  double start_time, end_time;
  int i, j, k, tr;
  int a[N][N], b[N][N], c[N][N]; 
  int nthreads;

  start_time = get_time();
  /* Initialize matrices a and b */
  for (i=0; i<N; i++) 
    { 
      for (j=0; j<N; j++)
	{ 
	  a[i][j] = (i+j)%N;
	  b[i][j] = (N+i-j)%N;
	}
    }

#pragma omp parallel
  {
#pragma omp master
    {
      nthreads = omp_get_num_threads();
    }
    /* Compute matrix multiplication c=a*b */
#pragma omp for private(j,k)
    for (i=0; i<N; i++)
      { 
	for (j=0; j<N; j++)
	  { 
	    c[i][j]=0;
	    for (k=0; k<N; k++)
	      { 
		c[i][j]=c[i][j]+a[i][k]*b[k][j];
	      }
	  }
      }
  }

  /* Compute the trace of c, tr(c)=sum(diag(c)) */
  tr=0;
  for (i=0; i<N; i++)
    tr=tr+c[i][i];

  end_time = get_time();

  /* Print result */
  printf("The trace of a*b is %d\n",tr);
  printf("Using %d threads\n",nthreads);
  printf("Took %g seconds\n",end_time - start_time);
  return 0;
}
