// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpLlKAQ4DFAUq&categoryId=AV5PpLlKAQ4DFAUq&categoryType=CODE

/*
 * swea_1953.cc
 *
 *  Created on: 2019. 4. 3.
 *      Author: Chulho Kang
 */

#include <string.h>
#include <iostream>
#include <queue>
#include <string>

int T, N, M, R, C, L;
int result;
int map[52][52];
bool visit_map[52][52];

// 0: >
// 1: V
// 2: <
// 3: ^
int d_x[4] = {1, 0, -1, 0};
int d_y[4] = {0, 1, 0, -1};

// 1: 1 3 6 7    1 2 4 7   1 3 4 5   1 2 5 6
// 2:            1 2 4 7             1 2 5 6
// 3: 1 3 6 7              1 3 4 5
// 4: 1 3 6 7                        1 2 5 6
// 5: 1 3 6 7    1 2 4 7
// 6:            1 2 4 7   1 3 4 5
// 7:                      1 3 4 5   1 2 5 6
static int able_shape[4][4] = {
    {1, 3, 6, 7}, {1, 2, 4, 7}, {1, 3, 4, 5}, {1, 2, 5, 6}};
static bool abel_path[8][4] = {
    {false, false, false, false}, {true, true, true, true},
    {false, true, false, true},   {true, false, true, false},
    {true, false, false, true},   {true, true, false, false},
    {false, true, true, false},   {false, false, true, true}};

struct q_entry {
  int x, y, shpae, depth;
};
std::queue<q_entry> q_step;

int main(void) {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 0;
    memset(map, 0, sizeof(map));
    memset(visit_map, 0, sizeof(visit_map));
    while (!q_step.empty()) q_step.pop();
    scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        scanf("%d", &map[i][j]);
      }
    }
    q_step.push({C, R, map[R][C], 1});
    visit_map[R][C] = true;
    result++;

    int cur_x, cur_y, cur_shape, cur_depth, next_x, next_y, next_shape;
    while (!q_step.empty()) {
      cur_x = q_step.front().x;
      cur_y = q_step.front().y;
      cur_shape = q_step.front().shpae;
      cur_depth = q_step.front().depth;
      q_step.pop();
      if (cur_depth == L) break;

      for (int i = 0; i < 4; i++) {
        if (!abel_path[cur_shape][i]) continue;
        next_x = cur_x + d_x[i];
        next_y = cur_y + d_y[i];
        if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N ||
            visit_map[next_y][next_x])
          continue;
        next_shape = map[next_y][next_x];
        if (next_shape < 8 &&
            (able_shape[i][0] == next_shape || able_shape[i][1] == next_shape ||
             able_shape[i][2] == next_shape ||
             able_shape[i][3] == next_shape)) {
          result++;
          visit_map[next_y][next_x] = true;
          q_step.push({next_x, next_y, next_shape, cur_depth + 1});
        }
      }
    }
    printf("#%d %d\n", tc, result);
  }
  return 0;
}