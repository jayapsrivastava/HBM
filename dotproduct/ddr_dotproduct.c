#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 30 

double dotProduct(double* arr1, double* arr2, int arrSize) {
  double dotProd = 0.0;
  int i = 0;
  for ( i = 0; i < arrSize; i++ ) {
    dotProd = dotProd + arr1[i] * arr2[i];
  }
  return dotProd;
}

int main()
{
  double *arr1 = NULL;
  double *arr2 = NULL;
  double prod = 0.0;

  FILE *fp ;
  char buf[BUFFER_SIZE];
  int arrSize, i = 0;
  char *filename = "data_array.txt";

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Couldn't open file data_array.txt! \n");
    exit(EXIT_FAILURE);
  }

  memset(buf, '\0', sizeof(buf)); 
  while (fgets(buf, BUFFER_SIZE, fp) != NULL) {
    if ( strstr(buf, "size") != NULL) {
      if ( fgets(buf, BUFFER_SIZE, fp) != NULL) {
        arrSize = atof(buf); 
        arr1 = (double*)malloc(arrSize*sizeof(double));
        arr2 = (double*)malloc(arrSize*sizeof(double));
      }
    }
    else if ( strstr(buf, "first" ) != NULL) {
      for (i=0; i < arrSize; i++) {
        if (fgets(buf, BUFFER_SIZE, fp) != NULL) {
          arr1[i] = atof(buf);
        }
      }
    }
    else if ( strstr(buf, "second") != NULL) {
      for (i=0; i < arrSize; i++) { 
        if (fgets(buf, BUFFER_SIZE, fp) != NULL) {
          arr2[i] = atof(buf);
        }
      }
    }
    else {
      printf("No other data array\n");
    }
  }

  fclose(fp);

  prod=dotProduct( arr1, arr2, arrSize);
  printf("Dot product : %lf\n", prod);

  //sleep (120); //Added to check the memory allocation using command - numstat
  free(arr1);
  free(arr2);
  return 0;
}
