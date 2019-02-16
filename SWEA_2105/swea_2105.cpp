// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5VwAr6APYDFAWu&categoryId=AV5VwAr6APYDFAWu&categoryType=CODE

/*
 * swea_2105.cc
 *
 *  Created on: 2019. 2. 16.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T, N;
int a[22][22];
bool visit[22][22];
bool desert[101];
int result;

// 0: >
// 1: V
// 2: <
// 3: ^
int d_x[4] = {1, -1, -1, 1};
int d_y[4] = {1, 1, -1, -1};

void dfs(int start_y, int start_x, int y, int x, int way, int count,
         int rotate_count) {
  if (start_x == x && start_y == y && visit[start_y][start_x]) {
    if (result < count) result = count;
    return;
  }
  int temp_x, temp_y;
  for (int i = 0; i < 2 && rotate_count + i != 4; i++) {
    temp_x = x + d_x[way + i];
    temp_y = y + d_y[way + i];

    // 경로 체크
    if (temp_x >= 0 && temp_x < N && temp_y >= 0 && temp_y < N) {
      if (!visit[temp_y][temp_x] && !desert[a[temp_y][temp_x]]) {
        visit[temp_y][temp_x] = true;
        desert[a[temp_y][temp_x]] = true;
        dfs(start_y, start_x, temp_y, temp_x, way + i, count + 1,
            rotate_count + i);
        visit[temp_y][temp_x] = false;
        desert[a[temp_y][temp_x]] = false;
      }
    }
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    memset(a, 0, sizeof(a));
    memset(visit, 0, sizeof(visit));
    memset(desert, 0, sizeof(desert));
    result = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &a[i][j]);
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dfs(i, j, i, j, 0, 0, 0);
      }
    }
    if (result == 0)
      printf("#%d -1\n", tc);
    else
      printf("#%d %d\n", tc, result);
  }
  return 0;
}