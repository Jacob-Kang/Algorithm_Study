// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq&categoryId=AV5PoOKKAPIDFAUq&categoryType=CODE

/*
 * swea_1949.cc
 *
 *  Created on: 2019. 2. 18.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T, N, K;
int a[8][8];
bool visit[8][8];
int result;
int largest;
// 0: >
// 1: V
// 2: <
// 3: ^
int d_x[4] = {1, 0, -1, 0};
int d_y[4] = {0, 1, 0, -1};

void dfs(int c_x, int c_y, int depth, bool is_driled) {
  int temp_x, temp_y;
  for (int i = 0; i < 4; i++) {
    temp_x = c_x + d_x[i];
    temp_y = c_y + d_y[i];
    if (temp_x >= 0 && temp_x < N && temp_y >= 0 && temp_y < N &&
        !visit[temp_y][temp_x]) {
      if (a[temp_y][temp_x] >= a[c_y][c_x]) {
        if (!is_driled && a[temp_y][temp_x] - K < a[c_y][c_x]) {
          int temp_height = a[temp_y][temp_x];
          a[temp_y][temp_x] = a[c_y][c_x] - 1;
          visit[temp_y][temp_x] = true;
          dfs(temp_x, temp_y, depth + 1, true);
          visit[temp_y][temp_x] = false;
          a[temp_y][temp_x] = temp_height;
        }
      } else {
        visit[temp_y][temp_x] = true;
        dfs(temp_x, temp_y, depth + 1, is_driled);
        visit[temp_y][temp_x] = false;
      }
    }
  }
  result = depth + 1 > result ? depth + 1 : result;
}
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 0;
    largest = 0;
    memset(a, 0, sizeof(a));
    memset(visit, 0, sizeof(visit));
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &a[i][j]);
        largest = a[i][j] > largest ? a[i][j] : largest;
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (a[i][j] == largest) {
          visit[i][j] = true;
          dfs(j, i, 0, false);
          visit[i][j] = false;
        }
      }
    }
    printf("#%d %d\n", tc, result);
  }
  return 0;
}