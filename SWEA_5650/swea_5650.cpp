// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo&categoryId=AWXRF8s6ezEDFAUo&categoryType=CODE
/*
 * swea_5650.cpp
 *
 *  Created on: 2019. 4. 4.
 *      Author: Chulho Kang
 */

#include <string.h>
#include <iostream>
#include <vector>

int T, N;
int result;
int map[102][102];

struct q_entry {
  int x, y;
};
std::vector<q_entry> worm_hole[5];
std::vector<q_entry> black_hole;

// 0: >
// 1: V
// 2: <
// 3: ^
int d_x[4] = {1, 0, -1, 0};
int d_y[4] = {0, 1, 0, -1};

// 1: 2 0 3 1
// 2: 2 3 1 0
// 3: 1 3 0 2
// 4: 3 2 0 1
// 5: 2 3 0 1
int dir_block[6][4] = {{2, 3, 0, 1}, {2, 0, 3, 1}, {2, 3, 1, 0},
                       {1, 3, 0, 2}, {3, 2, 0, 1}, {2, 3, 0, 1}};

int solve(int start_x, int start_y, int dir) {
  int score = 0;
  int cur_x, cur_y, next_x, next_y;
  cur_x = start_x;
  cur_y = start_y;
  while (1) {
    next_x = cur_x + d_x[dir];
    next_y = cur_y + d_y[dir];
    if (next_x < 0 || next_x == N || next_y < 0 || next_y == N) {
      dir = dir_block[0][dir];
      score++;
      cur_x = next_x;
      cur_y = next_y;
      continue;
    }
    if (map[next_y][next_x] == -1 || (next_x == start_x && next_y == start_y)) {
      return score;
    } else if (map[next_y][next_x] == 0) {
      cur_x = next_x;
      cur_y = next_y;
    } else if (map[next_y][next_x] >= 1 && map[next_y][next_x] <= 5) {
      dir = dir_block[map[next_y][next_x]][dir];
      score++;
      cur_x = next_x;
      cur_y = next_y;
    } else if (map[next_y][next_x] >= 6 && map[next_y][next_x] <= 10) {
      for (int i = 0; i < 5; i++) {
        if (worm_hole[i].size() != 0) {
          if (worm_hole[i][0].x == next_x && worm_hole[i][0].y == next_y) {
            cur_x = worm_hole[i][1].x;
            cur_y = worm_hole[i][1].y;
            break;
          } else if (worm_hole[i][1].x == next_x &&
                     worm_hole[i][1].y == next_y) {
            cur_x = worm_hole[i][0].x;
            cur_y = worm_hole[i][0].y;
            break;
          }
        }
      }
    }
  }
}
int main(void) {
  int T;
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    std::vector<q_entry> start_point;
    result = 0;
    memset(map, 0, sizeof(map));
    for (int i = 0; i < 5; i++) {
      while (!worm_hole[i].empty()) worm_hole[i].pop_back();
    }
    while (!black_hole.empty()) black_hole.pop_back();

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &map[i][j]);
        if (map[i][j] == 0) {
          start_point.push_back({j, i});
        } else if (map[i][j] == -1) {
          black_hole.push_back({j, i});
        } else if (map[i][j] >= 6 && map[i][j] <= 10) {
          worm_hole[map[i][j] - 6].push_back({j, i});
        }
      }
    }
    int temp_x, temp_y, temp_score;
    while (!start_point.empty()) {
      temp_x = start_point.back().x;
      temp_y = start_point.back().y;
      start_point.pop_back();
      for (int i = 0; i < 4; i++) {
        temp_score = solve(temp_x, temp_y, i);
        result = result < temp_score ? temp_score : result;
      }
    }
    printf("#%d %d\n", tc, result);
  }
  return 0;
}