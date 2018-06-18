#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hbwmalloc.h>

/* numactl -H shows following output on knl node -
 * node 1 cpus:
 * node 1 size: 16384 MB
 * node 1 free: 14896 MB
 * So I chose to have 10 GB of array size
 */
#define ARRAY_SIZE 1000000000

double dotProduct(double* arr1, double* arr2) {
  double dotProd = 0.0;
  long i = 0;
  for ( i = 0; i < ARRAY_SIZE; i++ ) {
    dotProd = dotProd + arr1[i] * arr2[i];
  /*  printf("Dot product : %lf arr1[%d]= %lf arr2[%d]=%lf\n", dotProd, i, arr1[i], i, arr2[i]); */
  }
  return dotProd;
}

int main(int argc, char** argv)
{
  double *arr1 = NULL; 
  double *arr2 = NULL;
  double prod = 0.0;
  long i = 0;

  if (argc != 2) {
    printf("Usage: ./dotproduct [OPTIONS]\n");
    printf("OPTIONS:\n");
    printf("    ddr : For malloc allocator\n");
    printf("    hbm : For hbw_malloc allocator\n");
    return 1;
  }
  
  if (!strcmp(argv[1], "ddr")) {
    printf("Using malloc allocator\n");
    arr1 = (double*)malloc(ARRAY_SIZE*sizeof(double));
    if ( arr1 == NULL) {
      perror("malloc");
      return 1;
    }
    arr2 = (double*)malloc(ARRAY_SIZE*sizeof(double));
    if ( arr2 == NULL) {
      perror("malloc");
      return 1;
    }
  }
  else if (!strcmp(argv[1], "hbm")) {
    printf("Using hbw_malloc allocator\n"); 
    arr1 = (double*)hbw_malloc(ARRAY_SIZE*sizeof(double));
    if (arr1 == NULL) {
      perror("hbw_malloc()");
      printf("Unable to allocate hbw string\n");
      return 1;
    }

    arr2 = (double*)hbw_malloc(ARRAY_SIZE*sizeof(double));
      if (arr2 == NULL) {
        perror("hbw_malloc()");
        return 1;
      }
  }
  else {
    printf("Wrong argument passed!!\n");
    printf("Usage: ./dotproduct [OPTIONS]\n");
    printf("OPTIONS:\n");
    printf("    ddr : For malloc allocator\n");
    printf("    hbm : For hbw_malloc allocator\n");
    return 1;
  } 

  for ( i=0; i < ARRAY_SIZE; i++) {
    arr1[i]= 1.1;
    arr2[i]= 1.1;
  }

  prod=dotProduct( arr1, arr2);
  printf("Dot product : %lf\n", prod); 

  if (!strcmp(argv[1], "ddr")) {
    free (arr1);
    free (arr2);
  }
  else {
    hbw_free(arr1);
    hbw_free(arr2);
  }

  return 0;
}
