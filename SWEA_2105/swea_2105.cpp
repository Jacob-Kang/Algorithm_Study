// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5VwAr6APYDFAWu&categoryId=AV5VwAr6APYDFAWu&categoryType=CODE
/*
 * swea_2105.cpp
 *
 *  Created on: 2019. 4. 4.
 *      Author: Chulho Kang
 */

#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>

int T, N, result;
int map[22][22];
bool visit_map[22][22];
bool eaten_flag[101];

// 0: ↘
// 1: ↙
// 2: ↖
// 3: ↗
int d_x[4] = {1, -1, -1, 1};
int d_y[4] = {1, 1, -1, -1};

void dfs(int start_x, int start_y, int cur_x, int cur_y, int depth,
         int turn_count, int dir) {
  if (turn_count > 4) return;
  if (turn_count >= 3 && cur_x == start_x && cur_y == start_y) {
    result = result < depth ? depth : result;
    return;
  }

  int next_x, next_y;
  for (int i = 0; i < 2; i++) {
    next_x = cur_x + d_x[dir + i];
    next_y = cur_y + d_y[dir + i];
    if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N &&
        !visit_map[next_y][next_x] && !eaten_flag[map[next_y][next_x]]) {
      visit_map[next_y][next_x] = true;
      eaten_flag[map[next_y][next_x]] = true;
      dfs(start_x, start_y, next_x, next_y, depth + 1, turn_count + i,
          (dir + i) % 4);
      visit_map[next_y][next_x] = false;
      eaten_flag[map[next_y][next_x]] = false;
    }
  }
}
int main(void) {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 0;
    memset(map, 0, sizeof(map));
    memset(visit_map, 0, sizeof(visit_map));
    memset(eaten_flag, 0, sizeof(eaten_flag));
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &map[i][j]);
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if ((j == 0) || (i == N - 1) || (j == N - 1)) continue;
        dfs(j, i, j, i, 0, 0, 0);
      }
    }
    if (result == 0)
      printf("#%d -1\n", tc);
    else
      printf("#%d %d\n", tc, result);
  }
  return 0;
}