#include "trace.h"

int main() {
  const int m = 4, n = 5;
  int A[m][n] = {1, 1, 1, 1, 2,
                 1, 1, 1, 0, 1,
                 1, 0, 1, 1, 1,
                 2, 1, 0, 1, 1};
  int min = searchTrace(A, m, n);
  printf("%d ", min);
}