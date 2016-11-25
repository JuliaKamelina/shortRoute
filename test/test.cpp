#include <gtest/gtest.h>
#include "trace.h"

TEST(test_searchTrace, no_road_for_one_point) {
  int **A = new int*;
    *A = new int;
    **A = 2;
  
  int min = searchTrace(A, 1, 1);
  
  EXPECT_EQ(-1, min);
}

TEST(test_searchTrace, can_find_the_sortest_way) {
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
  
  EXPECT_EQ(6, min);
}

TEST(test_searchTrace, can_detect_absence_of_way) {
  const int m = 4, n = 5;
  int **A = new int*[4];
  for (int i = 0; i < 4; i++)
    A[i] = new int[5];
    
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      A[i][j] = 1;
  A[0][4] = 2;
  A[3][0] = 2;
  A[2][0] = 0;
  A[3][1] = 0;
  
  int min = searchTrace(A, m, n);
  
  EXPECT_EQ(-1, min);
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}