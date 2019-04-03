// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeW7FakkUDFAVH&categoryId=AWIeW7FakkUDFAVH&categoryType=CODE
/*
 * swea_4014.cc
 *
 *  Created on: 2019. 4. 03.
 *      Author: Chulho Kang
 */

#include <math.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <string>

int T, N, X;
int result;
int map[52][52];
bool visit_map[52][52];

// 0: >
// 1: V
int d_x[2] = {1, 0};
int d_y[2] = {0, 1};

bool solve(int cur_x, int cur_y, int dir) {
  int cur_h = map[cur_y][cur_x];
  int next_x, next_y, next_h;
  int same_count = 1;
  for (int i = 0; i < N - 1; i++) {
    next_x = cur_x + d_x[dir];
    next_y = cur_y + d_y[dir];
    next_h = map[next_y][next_x];
    if (abs(cur_h - next_h) > 1) return false;
    if ((cur_h - next_h) == 1) {
      if (N - i + 1 < X) return false;
      int temp_x = next_x, temp_y = next_y, temp_h = next_h;
      for (int j = 0; j < X - 1; j++) {
        next_x = temp_x + d_x[dir];
        next_y = temp_y + d_y[dir];
        next_h = map[next_y][next_x];
        if (temp_h != next_h) return false;
        temp_x = next_x;
        temp_y = next_y;
        temp_h = next_h;
      }
      same_count = 0;
      i += (X - 1);
    } else if ((next_h - cur_h) == 1) {
      if (same_count < X) return false;
      same_count = 1;
    } else {
      same_count++;
    }
    cur_x = next_x;
    cur_y = next_y;
    cur_h = next_h;
  }
  return true;
}
int main(void) {
  int T;
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 0;
    memset(map, 0, sizeof(map));
    scanf("%d %d", &N, &X);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &map[i][j]);
      }
    }
    for (int i = 0; i < N; i++) {
      if (solve(i, 0, 1)) {
        result++;
        // std::cout << i + 1 << ", 0: ↓" << std::endl;
      }
      if (solve(0, i, 0)) {
        result++;
        // std::cout << "0, " << i + 1 << ": →" << std::endl;
      }
    }

    printf("#%d %d\n", tc, result);
  }
  return 0;
}