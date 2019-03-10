// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV597vbqAH0DFAVl&categoryId=AV597vbqAH0DFAVl&categoryType=CODE

/*
 * swea_2382.cpp
 *
 *  Created on: 2019. 2. 23.
 *      Author: Chulho Kang
 */

#include <string.h>
#include <algorithm>
#include <deque>
#include <iostream>

int T, N, M, K;

int result;

// 1: ^
// 2: V
// 3: <
// 4: >
static int d_x[5] = {0, 0, 0, -1, 1};
static int d_y[5] = {0, -1, 1, 0, 0};
int change_dir[5] = {0, 2, 1, 4, 3};
struct q_entry {
  int idx, x, y;
};
std::deque<q_entry> q;
int a_cell[1000][2];

void print_for_debug() {
  int temp_map[100][100];
  char temp_map2[100][100];
  memset(temp_map, 0, sizeof(temp_map));
  memset(temp_map2, '0', sizeof(temp_map2));
  int temp_x, temp_y, temp_idx;
  for (int i = 0; i < (int)q.size(); i++) {
    temp_x = q[i].x;
    temp_y = q[i].y;
    temp_idx = q[i].idx;
    if (a_cell[q[i].idx][0] != 0) {
      temp_map[q[i].y][q[i].x] = a_cell[q[i].idx][0];
      if (a_cell[q[i].idx][1] == 1)
        temp_map2[q[i].y][q[i].x] = '^';
      else if (a_cell[q[i].idx][1] == 2)
        temp_map2[q[i].y][q[i].x] = 'V';
      else if (a_cell[q[i].idx][1] == 3)
        temp_map2[q[i].y][q[i].x] = '<';
      else if (a_cell[q[i].idx][1] == 4)
        temp_map2[q[i].y][q[i].x] = '>';
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d \t", temp_map[i][j]);
    }
    printf("\t");
    for (int j = 0; j < N; j++) {
      printf("%c \t", temp_map2[i][j]);
    }
    printf("\n");
  }
  int res = 0;
  for (int i = 0; i < K; i++) res += a_cell[i][0];
  printf("%d\n\n", res);
}

void solve(int time) {
  int temp_x, temp_y, temp_idx, temp_way;
  std::deque<q_entry> temp_q;
  if (time == M) {
    while (!q.empty()) {
      temp_idx = q.front().idx;
      if (a_cell[q.front().idx][0] != 0) result += a_cell[q.front().idx][0];
      q.pop_front();
    }
    return;
  }
  int temp_a[100][100];
  int temp_a2[100][100];
  memset(temp_a, 0, sizeof(temp_a));
  memset(temp_a2, 0, sizeof(temp_a2));
  while (!q.empty()) {
    temp_x = q.front().x;
    temp_y = q.front().y;
    temp_idx = q.front().idx;
    temp_way = a_cell[temp_idx][1];
    q.pop_front();
    if (a_cell[temp_idx][0] == 0) continue;
    temp_x = temp_x + d_x[temp_way];
    temp_y = temp_y + d_y[temp_way];
    if (temp_x == 0 || temp_x == N - 1 || temp_y == 0 || temp_y == N - 1) {
      a_cell[temp_idx][0] >>= 1;
      a_cell[temp_idx][1] = change_dir[temp_way];
    }
    if (temp_a[temp_y][temp_x]) {
      if (temp_a2[temp_y][temp_x] < a_cell[temp_idx][0]) {
        a_cell[temp_a[temp_y][temp_x]][1] = a_cell[temp_idx][1];
        temp_a2[temp_y][temp_x] = a_cell[temp_idx][0];
      }
      a_cell[temp_a[temp_y][temp_x]][0] += a_cell[temp_idx][0];
      a_cell[temp_idx][0] = 0;
    } else {
      temp_a[temp_y][temp_x] = temp_idx;
      temp_a2[temp_y][temp_x] = a_cell[temp_idx][0];
      temp_q.push_back({temp_idx, temp_x, temp_y});
    }
  }
  q = temp_q;
}

int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d\n", &T);
  for (int tc = 1; tc <= T; tc++) {
    scanf("%d %d %d\n", &N, &M, &K);
    while (!q.empty()) q.pop_front();
    result = 0;
    memset(a_cell, 0, sizeof(a_cell));
    int cell[2];
    for (int i = 1; i <= K; i++) {
      scanf("%d %d %d %d\n", &cell[1], &cell[0], &a_cell[i][0], &a_cell[i][1]);
      q.push_back({i, cell[0], cell[1]});
    }

    for (int i = 0; i <= M; i++) {
      solve(i);
    }
    printf("#%d %d\n", tc, result);
  }
}