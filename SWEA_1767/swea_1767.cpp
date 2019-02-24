// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4suNtaXFEDFAUf

/*
 * swea_1767.cpp
 *
 *  Created on: 2019. 1. 29.
 *      Author: Chulho Kang
 */

#include <string.h>
#include <algorithm>
#include <deque>
#include <iostream>

#define INF_NUM 9999
int T, N;
int a[14][14];
int MIN_length;
int MAX_core;

// 0: >
// 1: V
// 2: <
// 3: ^
static int d_x[4] = {1, 0, -1, 0};
static int d_y[4] = {0, 1, 0, -1};

struct q_entry {
  int x, y;
};
std::deque<q_entry> q;

int connect_line(int c_x, int c_y, int way) {
  int temp_x = c_x + d_x[way];
  int temp_y = c_y + d_y[way];
  int depth;
  for (depth = 0; a[temp_y][temp_x] == 0; depth++) {
    a[temp_y][temp_x] = 2;
    temp_x += d_x[way];
    temp_y += d_y[way];
  }
  if (temp_x == 0 || temp_x == N + 1 || temp_y == 0 || temp_y == N + 1)
    return depth;
  else {
    for (; depth != 0; depth--) {
      temp_x -= d_x[way];
      temp_y -= d_y[way];
      a[temp_y][temp_x] = 0;
    }
    return -1;
  }
}

void disconnect_line(int c_x, int c_y, int way) {
  int temp_x = c_x + d_x[way];
  int temp_y = c_y + d_y[way];
  while (a[temp_y][temp_x] == 2) {
    a[temp_y][temp_x] = 0;
    temp_x += d_x[way];
    temp_y += d_y[way];
  }
  return;
}

void dfs(int core_id, int num_core, int total_length) {
  if (core_id == (int)q.size()) {
    if (MAX_core < num_core) {
      MIN_length = total_length;
      MAX_core = num_core;
    } else if (MAX_core == num_core) {
      if (MIN_length > total_length) {
        MIN_length = total_length;
      }
    }
    return;
  }
  for (int i = 0; i < 4; i++) {
    int temp_length = connect_line(q[core_id].x, q[core_id].y, i);
    if (temp_length == -1) {
      continue;
    } else {
      dfs(core_id + 1, num_core + 1, total_length + temp_length);
      disconnect_line(q[core_id].x, q[core_id].y, i);
    }
  }
  dfs(core_id + 1, num_core, total_length);
}
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    scanf("%d", &N);
    memset(a, -1, sizeof(a));
    while (!q.empty()) q.pop_front();
    MAX_core = 0;
    MIN_length = INF_NUM;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        scanf("%d", &a[i][j]);
        if (a[i][j] == 1 && i > 1 && i < N && j > 1 && j < N) {
          q.push_back({j, i});
        }
      }
    }
    dfs(0, 0, 0);
    printf("#%d %d\n", tc, MIN_length);
  }
}