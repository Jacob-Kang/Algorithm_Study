// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRJ8EKe48DFAUo&categoryId=AWXRJ8EKe48DFAUo&categoryType=CODE
/*
 * swea_5653.cc
 *
 *  Created on: 2019. 2. 16.
 *      Author: Chulho Kang
 */
#include <string.h>
#include <iostream>
#include <queue>

#define OFF_LOC 300

int T, N, M, K;
int result;
int map[700][700];

// 0: >
// 1: V
// 2: <
// 3: ^
int d_x[4] = {1, 0, -1, 0};
int d_y[4] = {0, 1, 0, -1};

struct pq_entry {
  int life;
  int active_time;
  int x, y;
  bool already_breed;
};
struct cmp {
  bool operator()(pq_entry a, pq_entry b) {
    if (a.active_time == b.active_time) return a.life < b.life;
    return a.active_time > b.active_time;
  }
};
std::priority_queue<pq_entry, std::vector<pq_entry>, cmp> active_cell;
int main(void) {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 0;
    memset(map, 0, sizeof(map));
    while (!active_cell.empty()) active_cell.pop();
    // N: Y
    // M: X
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        scanf("%d", &map[OFF_LOC + i][OFF_LOC + j]);
        if (map[OFF_LOC + i][OFF_LOC + j] != 0)
          active_cell.push({map[OFF_LOC + i][OFF_LOC + j],
                            map[OFF_LOC + i][OFF_LOC + j] + 1, OFF_LOC + j,
                            OFF_LOC + i, false});
      }
    }
    int cur_time = 0;
    while (cur_time <= K) {
      int cur_x, cur_y, cur_life;
      bool cur_flag;
      int next_x, next_y;
      while (active_cell.top().active_time == cur_time) {
        cur_x = active_cell.top().x;
        cur_y = active_cell.top().y;
        cur_life = active_cell.top().life;
        cur_flag = active_cell.top().already_breed;
        active_cell.pop();
        if (!cur_flag) {
          for (int i = 0; i < 4; i++) {
            next_x = cur_x + d_x[i];
            next_y = cur_y + d_y[i];
            if (map[next_y][next_x] == 0) {
              map[next_y][next_x] = cur_life;
              active_cell.push(
                  {cur_life, cur_time + cur_life + 1, next_x, next_y, false});
            }
          }
          if (cur_life != 1)
            active_cell.push({cur_life, cur_time + cur_life - 1, 0, 0, true});
        }
      }
      cur_time++;
    }
    printf("#%d %d\n", tc, active_cell.size());
  }
  return 0;
}