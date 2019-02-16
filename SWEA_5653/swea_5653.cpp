// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRJ8EKe48DFAUo&categoryId=AWXRJ8EKe48DFAUo&categoryType=CODE

/*
 * swea_5653.cc
 *
 *  Created on: 2019. 2. 16.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>
#include <vector>
#define A_OFFSET 200
using namespace std;

int T, N, M, K;
int a[450][450];
int result;

// 0: >
// 1: V
// 2: <
// 3: ^
int d_x[4] = {1, 0, -1, 0};
int d_y[4] = {0, 1, 0, -1};

struct pq_entry {
  int total_time, life_time, x, y;
  bool is_active;
};

struct cmp {
  bool operator()(pq_entry t, pq_entry u) {
    if (t.total_time == u.total_time)
      return t.life_time < u.life_time;
    else
      return t.total_time > u.total_time;
  }
};
std::priority_queue<pq_entry, vector<pq_entry>, cmp> pq2;

void print_map(int num) {
  std::cout << "\n########## " << num << "[" << pq2.size() << "] ##############"
            << std::endl;
  for (int i = 0; i < N + 10; i++) {
    for (int j = 0; j < M + 10; j++) {
      std::cout << a[i + A_OFFSET - 5][j + A_OFFSET - 5] << " ";
    }
    printf("\n");
  }
  std::cout << "########################" << std::endl;
  for (auto it = &pq2.top(); it != &pq2.top() + pq2.size(); it++)
    std::cout << it->total_time << ", " << it->life_time << ", ("
              << it->x - A_OFFSET << ", " << it->y - A_OFFSET << "), "
              << it->is_active << std::endl;
}
void solve() {
  int temp_time;
  int c_x, c_y, c_life;
  int temp_x, temp_y;
  bool c_active_state;
  // print_map(0);
  for (int c_time = 1; c_time < K; c_time++) {
    for (temp_time = pq2.top().total_time; temp_time == c_time;
         temp_time = pq2.top().total_time) {
      c_x = pq2.top().x;
      c_y = pq2.top().y;
      c_life = a[c_y][c_x];
      c_active_state = pq2.top().is_active;
      pq2.pop();
      if (c_life > 1 && !c_active_state)
        pq2.push({c_time + c_life - 1, c_life, c_x, c_y, true});

      if (!c_active_state) {
        for (int i = 0; i < 4; i++) {
          temp_x = c_x + d_x[i];
          temp_y = c_y + d_y[i];
          if (a[temp_y][temp_x] == 0) {
            a[temp_y][temp_x] = c_life;
            pq2.push({c_time + c_life + 1, c_life, temp_x, temp_y, false});
          }
        }
      }
    }
    // print_map(c_time);
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    memset(a, 0, sizeof(a));
    result = 0;
    while (!pq2.empty()) pq2.pop();
    // while (!temp_pq.empty()) temp_pq.pop();
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        scanf("%d", &a[A_OFFSET + i][A_OFFSET + j]);
        if (a[A_OFFSET + i][A_OFFSET + j] != 0)
          pq2.push({a[A_OFFSET + i][A_OFFSET + j],
                    a[A_OFFSET + i][A_OFFSET + j], A_OFFSET + j, A_OFFSET + i,
                    false});
      }
    }
    solve();
    printf("#%d %ld\n", tc, pq2.size());
  }
  return 0;
}