#include "trace.h"

int main() {
  const int m = 4, n = 5;
  int **A = new int*[4];
  for (int i = 0; i < 4; i++)
    A[i] = new int[5];
    
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      A[i][j] = 1;
  A[0][4] = 2;
  A[3][0] = 2;
  
  int min = searchTrace(A, m, n);
  printf("%d ", min);
}