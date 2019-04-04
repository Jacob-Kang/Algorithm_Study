// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq
/*
 * swea_1949.cpp
 *
 *  Created on: 2019. 4. 4.
 *      Author: Chulho Kang
 */

#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>

int T, N, K, result;
int map[10][10];
bool visit_map[10][10];

// 0: >
// 1: V
// 2: <
// 3: ^
int d_x[4] = {1, 0, -1, 0};
int d_y[4] = {0, 1, 0, -1};

struct q_entry {
  int x, y;
};
std::queue<q_entry> highest_point;

void dfs(int depth, int cur_x, int cur_y, bool is_used_drill) {
  int next_x, next_y;
  for (int i = 0; i < 4; i++) {
    next_x = cur_x + d_x[i];
    next_y = cur_y + d_y[i];
    if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N &&
        !visit_map[next_y][next_x]) {
      if (map[cur_y][cur_x] > map[next_y][next_x]) {
        visit_map[next_y][next_x] = true;
        dfs(depth + 1, next_x, next_y, is_used_drill);
        visit_map[next_y][next_x] = false;
      } else if (!is_used_drill &&
                 map[next_y][next_x] - K < map[cur_y][cur_x]) {
        int temp_high = map[next_y][next_x];
        map[next_y][next_x] = map[cur_y][cur_x] - 1;
        is_used_drill = true;
        visit_map[next_y][next_x] = true;
        dfs(depth + 1, next_x, next_y, is_used_drill);
        visit_map[next_y][next_x] = false;
        map[next_y][next_x] = temp_high;
        is_used_drill = false;
      }
    }
  }
  result = result < depth ? depth : result;
}
int main(void) {
  freopen("input1.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 0;
    while (!highest_point.empty()) {
      highest_point.pop();
    }
    scanf("%d %d", &N, &K);
    int temp_highest = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &map[i][j]);
        temp_highest = temp_highest < map[i][j] ? map[i][j] : temp_highest;
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (temp_highest == map[i][j]) highest_point.push({j, i});
      }
    }
    while (!highest_point.empty()) {
      visit_map[highest_point.front().y][highest_point.front().x] = true;
      dfs(1, highest_point.front().x, highest_point.front().y, false);
      visit_map[highest_point.front().y][highest_point.front().x] = false;
      highest_point.pop();
    }
    printf("#%d %d\n", tc, result);
  }
  return 0;
}