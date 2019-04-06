// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV597vbqAH0DFAVl&categoryId=AV597vbqAH0DFAVl&categoryType=CODE
/*
 * swea_2382_2.cpp
 *
 *  Created on: 2019. 4. 5.
 *      Author: Chulho Kang
 */

#include <string.h>
#include <iostream>
#include <list>
#include <queue>
int T, N, M, K;
int result;

// 1: ^
// 2: V
// 3: <
// 4: >
int d_x[5] = {0, 0, 0, -1, 1};
int d_y[5] = {0, -1, 1, 0, 0};
int replect_dir[5] = {0, 2, 1, 4, 3};

struct q_entry {
  int idx, y, x, dir, num;
  bool operator<(const q_entry& other) const { return num > other.num; }
};
int main(void) {
  int T;
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 0;
    scanf("%d %d %d", &N, &M, &K);
    std::list<q_entry> q_cell;

    q_entry temp_entry;
    for (int i = 1; i <= K; i++) {
      scanf("%d %d %d %d", &temp_entry.y, &temp_entry.x, &temp_entry.num,
            &temp_entry.dir);
      temp_entry.idx = i;
      q_cell.push_back(temp_entry);
    }

    int cur_x, cur_y;
    for (int cur_time = 0; cur_time < M; cur_time++) {
      int visit_map[102][102];
      memset(visit_map, 0, sizeof(visit_map));
      q_cell.sort();
      std::list<q_entry> q_next_cell;
      while (!q_cell.empty()) {
        cur_x = q_cell.front().x;
        cur_y = q_cell.front().y;
        temp_entry.dir = q_cell.front().dir;
        temp_entry.x = cur_x + d_x[temp_entry.dir];
        temp_entry.y = cur_y + d_y[temp_entry.dir];
        temp_entry.num = q_cell.front().num;
        temp_entry.idx = q_cell.front().idx;
        q_cell.pop_front();
        if (temp_entry.x == 0 || temp_entry.x == N - 1 || temp_entry.y == 0 ||
            temp_entry.y == N - 1) {
          temp_entry.dir = replect_dir[temp_entry.dir];
          temp_entry.num /= 2;
        }
        if (visit_map[temp_entry.y][temp_entry.x]) {
          for (auto it = q_next_cell.begin(); it != q_next_cell.end(); it++) {
            if (it->idx == visit_map[temp_entry.y][temp_entry.x]) {
              it->num += temp_entry.num;
              break;
            }
          }
        } else {
          visit_map[temp_entry.y][temp_entry.x] = temp_entry.idx;
          q_next_cell.push_back(temp_entry);
        }
      }
      q_cell = q_next_cell;
    }

    while (!q_cell.empty()) {
      result += q_cell.front().num;
      q_cell.pop_front();
    }
    printf("#%d %d\n", tc, result);
  }
  return 0;
}