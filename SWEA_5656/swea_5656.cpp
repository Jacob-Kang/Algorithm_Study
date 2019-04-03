// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo
/*
 * swea_5656.cc
 *
 *  Created on: 2019. 2. 16.
 *      Author: Chulho Kang
 */

#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>

int T, N, W, H, result;
int map[15][12];

// 0: >
// 1: V
// 2: <
// 3: ^
int d_x[4] = {1, 0, -1, 0};
int d_y[4] = {0, 1, 0, -1};

struct q_entry {
  int data, x, y;
};

void dfs(int depth) {
  if (depth == N) {
    int temp = 0;
    for (int i = 0; i < W; i++) {
      for (int j = H - 1; j >= 0; j--) {
        if (map[j][i] == 0) break;
        temp++;
      }
    }
    result = result > temp ? temp : result;
    return;
  }
  int temp_map[15][12];
  memcpy(temp_map, map, sizeof(map));

  for (int i = 0; i < W; i++) {
    bool check_break[12];
    memset(check_break, 0, sizeof(check_break));
    int curr_x, curr_y, curr_target = 0;
    for (curr_y = 0; curr_y < H; curr_y++) {
      if (map[curr_y][i] != 0) {
        curr_target = map[curr_y][i];
        break;
      }
    }
    std::queue<q_entry> cmd_set;
    map[curr_y][i] = 0;
    cmd_set.push({curr_target, i, curr_y});
    int next_x, next_y;
    while (!cmd_set.empty()) {
      curr_x = cmd_set.front().x;
      curr_y = cmd_set.front().y;
      curr_target = cmd_set.front().data;
      cmd_set.pop();
      for (int j = 0; j < 4; j++) {
        next_x = curr_x;
        next_y = curr_y;
        for (int k = 1; k < curr_target; k++) {
          next_x += d_x[j];
          next_y += d_y[j];
          if (next_x >= 0 && next_x < W && next_y >= 0 && next_y < H &&
              map[next_y][next_x] != 0) {
            cmd_set.push({map[next_y][next_x], next_x, next_y});
            map[next_y][next_x] = 0;
            check_break[next_x] = true;
          }
        }
      }
    }
    for (int x = 0; x < W; x++) {
      if (check_break[x]) {
        int temp_a[15], pivot = 0;
        memset(temp_a, 0, sizeof(temp_a));
        for (int i = H - 1; i >= 0; i--) {
          if (map[i][x] != 0) {
            temp_a[pivot] = map[i][x];
            pivot++;
          }
        }
        for (int i = 0; i < H; i++) {
          map[H - 1 - i][x] = temp_a[i];
        }
      }
    }
    dfs(depth + 1);
    memcpy(map, temp_map, sizeof(map));
  }
}

int main(void) {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 9999;
    scanf("%d %d %d", &N, &W, &H);
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        scanf("%d", &map[i][j]);
      }
    }
    dfs(0);
    printf("#%d %d\n", tc, result);
  }
  return 0;
}