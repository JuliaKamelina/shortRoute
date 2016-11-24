#include "trace.h"
#include <queue>

int searchTrace(int A[][5], int m, int n) {
  int **R = new int * [m];
  for (int i = 0; i < m; i++)
    R[i] = new int[n];
  std::queue<point> q;
  point start, finish;
  
  start.x = 0; start.y = n - 1;
  finish.x = m - 1; finish.y = 0;
  q.push(start);
  R[start.x][start.y] = 0;
    while(!q.empty()) {
      point first = q.front();
      if (first.x == finish.x && first.y == finish.y) {
        return R[first.x][first.y] - 1;
      }
      q.pop();
      if ((first.y - 1 >= 0) && (A[first.x][first.y - 1]) && (R[first.x][first.y - 1] < 0)) {
        R[first.x][first.y - 1] = R[first.x][first.y] + 1;
        point tmp;
        tmp.y = first.y - 1;   
        tmp.x = first.x;
        q.push(tmp); 
        }
        
      if ((first.x + 1 < m) && (A[first.x + 1][first.y]) && (R[first.x + 1][first.y] < 0)) {
        R[first.x + 1][first.y] = R[first.x][first.y] + 1;
        point tmp;
        tmp.x = first.x + 1;
        tmp.y = first.y;
        q.push(tmp);
      }
        
      if ((first.y + 1 < n) && (A[first.x][first.y + 1]) && (R[first.x][first.y + 1] < 0)) {
        R[first.x][first.y + 1] = R[first.x][first.y] + 1;
        point tmp;
        tmp.y = first.y + 1;
        tmp.x = first.x;
        q.push(tmp);
      }
        
      if ((first.x - 1 >= 0) && (A[first.x - 1][first.y]) && (R[first.x - 1][first.y] < 0)) {
        R[first.x - 1][first.y] = R[first.x][first.y] + 1;
        point tmp;
        tmp.x = first.x - 1;
        tmp.y = first.y;
        q.push(tmp);
      }
    }
  return -1;
}
